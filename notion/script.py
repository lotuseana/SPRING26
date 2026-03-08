import requests
import config
import json
from pprint import pprint
from datetime import datetime, timedelta, timezone
from pathlib import Path


CANVAS_URLS = config.URLS
CANVAS_KEYS = config.CANVAS_TOKENS
ALLOWED_COURSES = config.COURSES
ASSIGNMENTS_PATH = Path(__file__).parent / config.ASSIGNMENTS_OUTPUT
GRADES_PATH = Path(__file__).parent / config.GRADES_OUTPUT

ASSIGNMENTS_DB_ID = config.ASSIGNMENTS_DB_ID
GRADES_DB_ID = config.GRADES_DB_ID
NOTION_KEY = config.NOTION_TOKEN

notion_headers = { 
    "Authorization": f"Bearer {NOTION_KEY}",
    "Notion-Version": "2022-06-28"}

def get_canvas_data(KEY, URL):

    def canvas_get(path):
        headers = {"Authorization": f"Bearer {KEY}"}
        url = f"{URL}{path}"
        resp = requests.get(url, headers=headers, params={"per_page": 100})
        #print("canvas responded")
        return resp.json()

    raw_courses = canvas_get("/courses")

    courses = []
    for rc in raw_courses:
        if (('access_restricted_by_date' not in rc or not rc['access_restricted_by_date']) and rc['id'] in ALLOWED_COURSES.keys()):
            courses.append({'id' : rc['id'],
                            'name' : rc['name']})


    raw_grades = canvas_get("/users/self/enrollments?include[]=grades")
    grades = []
    for rg in raw_grades:
        if (rg['course_id'] in ALLOWED_COURSES.keys()):
            grades.append({ 'course_id' : rg['course_id'],
                            'course' : ALLOWED_COURSES.get(rg['course_id']),
                            'grade' : 1 if rg['grades']['current_score'] == None else rg['grades']['current_score'] / 100})

    raw_assignments = []
    for c in courses:
        raw_assignments += canvas_get(f"/courses/{c['id']}/assignments?include[]=submission")

    assignments = []
    for ra in raw_assignments:
        if 'due_at' in ra and ra['due_at'] is not None and datetime.fromisoformat(ra['due_at']) > datetime.now(timezone.utc):
            assignments.append({'id' : ra['id'],
                                'name': ra['name'],
                                'due date' : str(datetime.fromisoformat(ra['due_at'])) ,
                                'status' : ra['submission']['workflow_state'],
                                'course' : ALLOWED_COURSES.get(ra['course_id'])})
            print(f"actual: {ra['due_at']}")
            print(f"converted: {str(datetime.fromisoformat(ra['due_at']))}")
            

    return [assignments, grades]


def get_notion_assignments():
    query_url = f"https://api.notion.com/v1/databases/{ASSIGNMENTS_DB_ID}/query"
    notion_data = []
    cursor = None
    
    while True:
        payload = {
            "page_size": 100,
            "filter": {
                "property": "due date",
                "date": {
                    "on_or_after": str(datetime.now(timezone.utc))
                }
            }
        }
        
        if cursor:
            payload["start_cursor"] = cursor

        response = requests.post(query_url, json=payload, headers=notion_headers)
        raw_notion_data = response.json()
        
        for rn in raw_notion_data['results']:
            notion_data.append({'course': rn['properties']['course']['rich_text'][0]['plain_text'],
                                'due date' : rn['properties']['due date']['date']['start'],
                                'id' : rn['properties']['id']['number'],
                                'name' : rn['properties']['name']['title'][0]['plain_text'],
                                'status' : rn['properties']['status']['status']['name'],
                                'page_id' : rn['id'] })
        
        if not raw_notion_data.get('has_more'):
            break
        
        cursor = raw_notion_data.get('next_cursor')
        
    return notion_data

def get_notion_grades():
    query_url = f"https://api.notion.com/v1/databases/{GRADES_DB_ID}/query"
    notion_data = []

    response = requests.post(query_url, headers=notion_headers)
    raw_notion_data = response.json()

    for rn in raw_notion_data['results']:
        notion_data.append({'course': rn['properties']['course']['title'][0]['plain_text'],
                            'course_id' : rn['properties']['course_id']['number'],
                            'grade' : rn['properties']['grade']['number'],
                            'page_id' : rn['id'] })
    return notion_data

def format_for_notion(canvas_item):
    return {
        "name": {"title": [{"text": {"content": canvas_item['name']}}]},
        "course": {"rich_text": [{"text": {"content": canvas_item['course']}}]},
        "due date": {"date": {"start": canvas_item['due date']}},
        "status": {"status": {"name": canvas_item['status']}},
        "id": {"number": canvas_item['id']}
    }

def create_assignment_page(data):
    create_url = "https://api.notion.com/v1/pages"

    payload = {"parent": {"database_id": ASSIGNMENTS_DB_ID}, "properties": format_for_notion(data)}

    res = requests.post(create_url, headers=notion_headers, json=payload)
    return res

def update_page(data, page_id, data_type="assignment"):
    url = f"https://api.notion.com/v1/pages/{page_id}"

    if data_type == "grade":
        properties = {"grade": {"number": data['grade']}}
    else:
        properties = format_for_notion(data)

    payload = {"properties": properties}

    res = requests.patch(url, json=payload, headers=notion_headers)
    return res


def main():
    canvas_assignments = []
    canvas_grades = []

    for i in range(len(CANVAS_KEYS)):
        canvas_data = get_canvas_data(CANVAS_KEYS[i], CANVAS_URLS[i])
        #pprint(canvas_data)
        canvas_assignments += canvas_data[0]
        canvas_grades += canvas_data[1]

    #pprint(canvas_grades)

    notion_assignments = get_notion_assignments()
    notion_grades = get_notion_grades()

    #pprint(notion_grades)

    for g in canvas_grades:
        for check_g in notion_grades:
            if g['course_id'] == check_g['course_id'] and g['grade'] != check_g['grade']:
                update_page(g, check_g['page_id'], data_type="grade")
                print(f"{g['course']} grade changed from {check_g['grade']} to {g['grade']}")
                break

    to_add = []
    to_update = []

    for a in canvas_assignments:
        found = False
        for check_a in notion_assignments:
            if a['id'] == check_a['id']:
                found = True
                if a['status'] != check_a['status'] or a['due date'] != check_a['due date']:
                    to_update.append([a, check_a['page_id']])
                break
        if not found:
            to_add.append(a)

    print(f"num to add: {len(to_add)}")
    print(f"num to update: {len(to_update)}")

    for a in to_add:
        create_assignment_page(a)

    for a in to_update:
        update_page(a[0], a[1])

    print("done!")


main()


#DUNGEON

    # with open(ASSIGNMENTS_PATH, 'w') as file:
    #     json.dump(canvas_assignments, file)
    #     print("assignments dumped")
    
    # with open(GRADES_PATH, 'w') as file:
    #     json.dump(canvas_grades, file)
    #     print("assignments dumped")

    # with open(OUTPUT_PATH, 'r') as file:
    #     canvas_assignments = json.load(file)
    #     print("read successful")

    # with open(GRADES_PATH, 'r') as file:
    #     canvas_grades = json.load(file)
    #     print("read successful")