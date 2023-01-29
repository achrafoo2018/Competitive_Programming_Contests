for _ in range(int(input())):
    n, k = map(int, input().split(" "))
    ans = [['.' for _ in range(n)] for _ in range(n)]
    i = 0
    while k and i < n:
        ans[i][i] = 'R'
        i += 2
        k -= 1
    if k == 0:
        for i in ans:
            print(*i, sep="")
    else:
        print(-1)
