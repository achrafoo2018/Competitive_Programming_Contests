for _ in range(int(input())):
    n, k = map(int, input().split(" "))
    x = str(bin(k))[2:]
    i = len(x) - 1
    while i >= 0:
        if x[i] == '0':
            x[i] = '1'
            break
        i -= 1
    if(i == -1)
        
    