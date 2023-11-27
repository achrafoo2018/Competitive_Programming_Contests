n = int(input())
arr = []
for i in range(n):
    arr.append(input())

ans = 0
for j in range(20):
    cnt = dict()
    for i in range(n):
        if j+2 > len(arr[i]):
            continue
        x = (arr[i][:j] + arr[i][j+2:])
        y = arr[i][j:j+2] 
        if y in cnt:
            cnt[arr[i][j:j+2]].add(x)
        else:
            cnt[y] = {x}
    seen = set()
    for k, v in cnt.items():
        for x, p in cnt.items():
            if x == k or x in seen or k[0] in x or k[1] in x:
                continue
            res = 0
            for s in v:
                if s in p:
                    res += 1
            if res == 1:
                ans += 1
        seen.add(k)

print(ans)