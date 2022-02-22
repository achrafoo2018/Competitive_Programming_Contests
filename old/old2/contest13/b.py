for _ in range(int(input())):
    x = list(input())
    mx = -1
    idx = 1
    for i in range(1, len(x)):
        s = int(x[i])+int(x[i-1])
        if len(str(s)) == 2:
            idx = i
    s = str(int(x[idx])+int(x[idx-1]))
    for i in range(idx-1):
        print(x[i], end="")
    print(s, end="")
    for i in range(idx+1, len(x)):
        print(x[i], end="")
    print()
