
class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

yes = dict()
no = dict()
chars = dict()
def build(id_):
    tree = Node(chars[id_])
    def buildd(id_):
        newNode = Node(chars[id_])
        if id_ in yes:
            newNode.left = buildd(yes[id_])
        if id_ in no:
            newNode.right = buildd(no[id_])
        return newNode
    if id_ in yes:
        tree.left = buildd(yes[id_])
    if id_ in no:
        tree.right = buildd(no[id_])
    return tree

    
n, p = [int(i) for i in input().split(" ")]
mn = -1
ids_ = []
for i in range(n):
    s = input().split(" ")
    id_  = int(s[1])
    if s[0] == 'I':
        ids_.append(id_)
        chars[id_] = s[2]
        yes[id_] = int(s[3])
        no[id_] = int(s[4])
    else:
        language = s[2]
        chars[id_] = language

mn = -1
for i in ids_:
    if i not in yes.values() and i not in no.values():
        mn = i
        break
tree = build(mn)
for i in range(p):
    s = set(input())
    ans = set()
    def work(node):
        if node.left == None or node.right == None:
            ans.add(node.data)
            return
        if node.data not in s:
            work(node.left)
            work(node.right)
        else:
            work(node.left)
    work(tree)
    ss = []
    for lng in ans:
        ss.append(lng)
    ss.sort()
    for jj in ss:
        print(jj, end=" ")
    print()
