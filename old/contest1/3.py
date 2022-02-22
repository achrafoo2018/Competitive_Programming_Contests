def bs(arr, x):
    l, h = 0, len(arr)-1
    while l <= h:
        mid = (l + h) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            l = mid + 1
        else:
            h = mid - 1
t = int(input())
for _ in range(t):
    n = int(input())
    arr = sorted(map(int, input().split(" ")))
    s = set(arr)
    x = n-1
    ans = 0
    visited = [False] * n
    for i in range(n, 0, -1):
        if i in s:
            if i == arr[x]:
                x -= 1
            visited[bs(arr, i)] = True
            continue
        while visited[x]:
            x -= 1
        if i*2+1 > arr[x] :
            ans = -1
            break
        ans += 1
        x -= 1
    print(ans)
    