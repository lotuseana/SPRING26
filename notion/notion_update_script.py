import requests
import config
import json
from pprint import pprint
from datetime import datetime as dt


BASE_URL = "https://ccsf.instructure.com/api/v1"
KEYS = config.TOKENS
ALLOWED_COURSES = config.COURSES

def canvas_get(path):
    response = []
    for KEY in KEYS:
        headers = {"Authorization": f"Bearer {KEY}"}
        url = f"{BASE_URL}{path}"
        resp = requests.get(url, headers=headers, params={"per_page": 100})
        response += resp.json()
    return response      


raw_courses = canvas_get("/courses")

courses = []
#pprint(courses)
for c in raw_courses:
    if (('access_restricted_by_date' not in c or not c['access_restricted_by_date']) and c['id'] in ALLOWED_COURSES):
        courses.append(c)
for c in courses:
    print(c['id'], c['name'])
#pprint(cleaned)

raw_assignments = []
for c in courses:
    raw_assignments+=(canvas_get(f"/courses/{c['id']}/assignments"))

assignments = []
for a in raw_assignments:
    if 'due_at' in a and a['due_at'] is not None and dt.fromisoformat(a['due_at']).replace(tzinfo=None) > dt.now():
        assignments.append(a)

for a in assignments:
    print(a['name'], a['due_at'])
#pprint(assignments)
    
    # if (dt.fromisoformat(a['due_at']).replace(tzinfo=None) > dt.now().replace(tzinfo=None)):
    #     print(a['name'])   dt.fromisoformat(a['due_at']).replace(tzinfo=None) and a['due_at'].replace(tzinfo=None) > dt.now()
