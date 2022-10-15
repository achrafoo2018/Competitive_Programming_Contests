for t in range(1, int(input())+1):
    n = int(input())
    rx = ry = 0
    ans = 0
    for _ in range(n):
        x, y = [int(i) for i in input().split(" ")]
        ans = ans + x**2 + y**2 
        rx += x
        ry += y
    q = int(input())
    res = []
    for _ in range(q):
        x, y = [int(i) for i in input().split(" ")]
        res.append(ans + n * (x*x + y*y) - 2 * (rx*x + ry*y))
    mod = 1000000007
    print("Case #{}: {}".format(t, sum(res)%mod))
