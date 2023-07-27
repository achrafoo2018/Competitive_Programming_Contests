for _ in range(int(input())):
    n = int(input())
    s = input()
    prev = ""
    ans = 0
    for i in range(1, n):
        pp = s[i-1:i+1]
        if pp == prev[::-1]:
            prev = pp
            continue
        prev = pp
        ans += 1
    print(ans)