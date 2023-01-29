for _ in range(int(input())):
    n = int(input())
    s = input()
    mp = dict()
    ans = "NO"
    for i in range(1, n):
        pp = s[i-1:i+1]
        if pp in mp and mp[pp] != i-1:
            ans = "YES"
            break
        elif pp not in mp:
            mp[pp] = i
    print(ans)