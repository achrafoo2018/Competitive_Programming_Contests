for _ in range(int(input())):
    n, c = [int(i) for i in input().split(" ")]
    arr = [int(i) for i in input().split(" ")]
    def check(mid):
        s = sum((x + mid + mid)**2 for x in arr)
        return s >= c
    l = 0
    r = 10**9
    ans = 0
    while l <= r:
        mid = (l+r) // 2
        if check(mid):
            ans = mid
            r = mid - 1
        else:
            l =  mid + 1
    print(ans)