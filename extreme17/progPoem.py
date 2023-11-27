n, m = [int(i) for i in input().split(" ")]
mp = dict()
k = 'A'
for i in range(n):
    s = input().split(" ")
    for j in s:
        mp[j] = k
    k = chr(ord(k) + 1)
    if k == 'X':
        k = chr(ord(k) + 1)

input()
cnt = dict()
ans = ""
for i in range(m):
    s = input().lower().split(" ")
    if s[-1] in mp:
        if mp[s[-1]] not in cnt:
            cnt[mp[s[-1]]] = 1
        else:
            cnt[mp[s[-1]]] += 1
        ans += mp[s[-1]]
    else:
        ans += 'X'
curr = 'A'
pp = dict()
res = ""
for i in range(len(ans)):
    if ans[i] == 'X': 
        res += 'X'
        continue
    if ans[i] not in pp:
        if ans[i] in cnt and cnt[ans[i]] == 1:
            res += 'X'
            continue
        pp[ans[i]] = curr
        curr = chr(ord(curr) + 1)
        if curr == 'X':
            curr = chr(ord(curr) + 1)
    res += pp[ans[i]]
print(res)