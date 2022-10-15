for i in range(int(input())):
    n = int(input())
    l = input().split('W')
    cond = False
    for s in l:
        r = 'R' in s
        b = 'B' in s
        if r ^ b:
            cond = True
    print("NO" if cond else "YES")