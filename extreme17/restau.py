for _ in range(int(input())):
    s = input().split(" ")
    mp = dict()
    for i in range(7):
        j = chr(ord('A') + i)
        mp[j] = 0
    for j in s:
        for i in j:
            if not i.isalpha():
                continue
            if i.upper() in mp:
                mp[i.upper()] += 1
            else:
                mp[i.upper()] = 1
    ans = "A"
    for i in range(1, 7):
        j = chr(ord('A') + i)
        if mp[j] > mp[ans]:
            ans = j
    print(ans)