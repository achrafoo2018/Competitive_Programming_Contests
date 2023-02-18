for _ in range(int(input())):
    n = int(input())
    sn = str(n)
    x = 0
    for i in sn:
        x += int(i)
    y = 0
    ans = 0
    for i in range(len(sn)-1, -1, -1):
        p = int(sn[i])
        if y+p >= (x // 2):
            ans = int(str(x//2 - y) + sn[i+1:])
            break
        y += p
    print(f'{ans} {n-ans}')