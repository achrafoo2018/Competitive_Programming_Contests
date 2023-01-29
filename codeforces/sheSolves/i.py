for _ in range(int(input())):
    a = input()
    n = len(a)
    ans = [1 + int(a[n-1])]
    for i in range(n-2, -1, -1):
        if int(a[i]) != 0:
            ans[i] = int(a[i])
            ans[i] *= ans[i+1]
    print(sum(ans))
