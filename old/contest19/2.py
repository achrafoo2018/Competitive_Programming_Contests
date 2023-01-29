t = int(input())
for _ in range(t):
    n = int(input())
    arr = input().split(" ")
    if len(arr) == 1:
        print(arr[0]+"a")
        continue
    ans = arr[0][0]
    for i in range(1, n-2):
        if arr[i-1][1] != arr[i][0]:
            ans += arr[i-1][1] + arr[i][0]
        else:
            ans += arr[i-1][1]
    ans += arr[n-3][1]
    if(len(ans) < n):
        ans += "a"*(n-len(ans))
    print(ans)