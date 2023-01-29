for _ in range(int(input())):
    s = input()
    ans = 0
    se = set()
    for i in s:
        if i not in se and len(se) == 3:
            ans += 1
            se = set()
        se.add(i)
    if len(se):
        ans += 1
    print(ans)
    
