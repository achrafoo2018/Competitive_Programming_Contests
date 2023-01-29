for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    mn = min(arr)
    mx = max(arr)
    if mn == mx:
        print(-1)
        continue
    ans = 1
    for i in range(mx, 0, -1):
        m = mx % i
        j = 0
        while j < n:
            if arr[j] % i != m:
                break
            j += 1
        if j == n:
            ans = i
            break
    print(ans)