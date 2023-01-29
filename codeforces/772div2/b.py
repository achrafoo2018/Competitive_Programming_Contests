for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    ans = 0
    for i in range(1, n-1):
        if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
            ans += 1
            x = arr[i+2] if i < n-2 else arr[i]
            arr[i+1] = max(arr[i], x)
    print(ans)
    print(*arr, sep=" ")