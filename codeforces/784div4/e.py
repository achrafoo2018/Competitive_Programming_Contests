for _ in range(int(input())):
    n = int(input())
    arr = []
    for i in range(n):
        x = input()
        arr.append(x)
        if x != x[::-1]:
            arr.append(x[::-1])
    arr.sort()
    mp = {}
    mp[arr[0]] = 1
    ans = 0
    for i in range(1, len(arr)):
        if arr[i][0] == arr[i-1][0]:
            if arr[i] in mp:
                mp[arr[i]] += 1
                

        else:
            nn = len(s)
            if nn > 1:
                ans += (nn*(nn+1)) // 2
            s = set()
    print(ans)