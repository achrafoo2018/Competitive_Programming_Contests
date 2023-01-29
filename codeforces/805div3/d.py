for _ in range(int(input())):
    s = input()
    p = int(input())
    pp = 0
    for i in s:
        pp += ord(i)-ord('a')+1
    if pp <= p:
        print(s)
        continue
    n = len(s)
    mp = dict()
    for i in s:
        if i not in mp:
            mp[i] = 1
        else:
            mp[i] += 1
    ss = sorted(s)
    ans = ""
    for i in range(n-1, -1, -1):
        if pp <= p:
            break
        pp -= ord(ss[i])-ord('a')+1
        mp[ss[i]] -= 1
    for i in s:
        if mp[i] > 0:
            ans += i
            mp[i] -= 1
    print(ans)
