for _ in range(int(input())):
    s = input()
    ans = "NO"
    n = len(s)
    i = 1
    while i*i <= n:
        j = i-1
        cond = True
        while j < n-1:
            if j < n-1 and s[j+1] != ' ':
                cond = False
                break
            j += i+1
        if cond and j == n-1:
            ans = "YES"
            break
        i += 1
    print(ans)