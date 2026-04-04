def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def tree(root_label, branches=[]):
    for branch in branches:
        assert is_tree(branch), 'branches must be trees'
    return [root_label] + list(branches)

def label(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_leaf(tree):
    return not branches(tree)

def count_leaves(tree):
    if is_leaf(tree):
        return 1
    else:
        branch_counts = [count_leaves(b) for b in branches(tree)]
        return sum(branch_counts)

def main():
    tree1 = tree(4, [tree(2, [tree(1), tree(3)]), tree(6, [tree(5)])])
    print(f"tree: {tree1}")
    print(f"label: {label(tree1)}")
    print(f"branches: {branches(tree1)}")
    print(f"number of leaves: {count_leaves(tree1)}")


main()