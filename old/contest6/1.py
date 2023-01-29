t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    res = 0
    for i in range(n-1, -1, -1):
        if int(s[i]) == 0:
            continue
        res += int(s[i])
        if i != n-1:
            res += 1
    print(res)        

