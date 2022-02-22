for _ in range(int(input())):
    n, k = map(int, input().split(" "))
    arr = sorted(map(int, input().split(" ")))
    sm = sum(arr)
    ans = 0
    if k < arr[0]:
        ans += arr[0] - k
        sm -= ans
        arr[0] = k
    if 