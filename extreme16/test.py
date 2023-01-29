mp = [dict() for i in range(8)]
for i in range(7647):
    s = input()
    if(len(s) > 8):
        continue
    for j in range(min(len(s), 8)):
        if s[j] in mp[j]:
            mp[j][s[j]] += 1
        else:
            mp[j][s[j]] = 1

arr = [[] for _ in range(8)]
for i in range(8):
    for j in mp[i]:
        arr[i].append((mp[i][j], j))
    arr[i].sort()

for i in range(8):
    print("\"", end="")
    for j in range(9):
        print(arr[i][j][1], end="")
    print(" \"")
