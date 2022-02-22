for _ in range(int(input())):
    n = int(input())
    arr = sorted(map(int, input().split(" ")))
    mp = {}
    for i in range(n):
        while arr[i] > n:
            arr[i] //= 2
    for i in range(n):
        if arr[i] in mp:
            mp[arr[i]] += 1
        else:
            mp[arr[i]] = 1
    arr = sorted(arr)
    cond = True
    for i in range(n):
        while mp[arr[i]] > 1 and arr[i] != 1:
            mp[arr[i]] -= 1
            arr[i] //= 2
            if arr[i] in mp:
                mp[arr[i]] += 1
            else:
                mp[arr[i]] = 1
        if arr[i] == 1 and mp[arr[i]] > 1:
            cond = False
            break
    print("YES" if cond else "NO")