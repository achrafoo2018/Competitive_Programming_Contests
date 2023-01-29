for _ in range(int(input())):
    n = int(input())
    if n % 2 == 1:
        print(0)
    else:
        ans = (n // 2) * (n // 4)
        if n % 4 == 0:
            ans -= (n // 4)
        print(ans)