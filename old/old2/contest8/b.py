for _ in range(int(input())):
    n = int(input())
    arr = []
    for __ in range(n):
        l, r = map(int, input().split(" "))
        arr.append((l, r))
    ans = []
    used = [False]*n
    for i in range(n):
        if arr[i][0] == arr[i][1]:
            ans.append([arr[i][0], arr[i][1], arr[i][0]])
            continue
        for j in range(n):
            if arr[j][0] == arr[i][0] and arr[j][1] <  arr[i][1] and not used[j]:
                ans.append([arr[i][0], arr[i][1], arr[j][1]+1])
                used[j] = True
                break
            elif arr[j][1] == arr[i][1] and arr[j][0] > arr[i][0] and not used[j]:
                ans.append([arr[i][0], arr[i][1], arr[j][0]-1])
                used[j] = True
                break
    for i in range(n):
        print(*ans[i], sep=" ")
