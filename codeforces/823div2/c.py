for _ in range(int(input())):
    s = input()
    n = len(s)
    s = [int(i) for i in s]
    for i in range(n):
        s[i] = [s[i], i]
    s.sort()
    mxidx = s[0][1]
    ans = ""
    ans += str(s[0][0])
    for i in range(1, n):
        x = str(s[i][0])
        if mxidx > s[i][1]:
            x = str(min(9, s[i][0]+1))
        ans += x
        mxidx = max(mxidx, s[i][1])
    ans = sorted(ans)
    ans = "".join(ans)
    print(ans)
