for _ in range(int(input())):
    n, k = map(int, input().split(" "))
    s = input()
    mp = {}
    for i in range(n):
        if s[i] in mp:
            mp[s[i]] += 1
        else:
            mp[s[i]] = 1
    arr = []
    for i in mp:
        arr.append(mp[i])
    arr.sort(reverse=True)
    s, s2 = 0, 0
    print(arr, end="")
    print(" k = ", k)
    # for i in range(len(arr)):
    #     if arr[i] % 2 == 1:
    #         arr[i] -= 1
    #         s2 += 1
    #     s += arr[i]
    # print(s // k + (len(arr) // s2 // k))
    # ans = arr[k-1] 
    # for i in range(k, len(arr)):
    #     ans += arr[i] // 2
    # print(ans)