for _ in range(int(input())):
    n = int(input())
    cond = False
    for i in range(n//21+1):
        if((n - 21*i) % 22 == 0):
            cond = True
            break
    if(cond):
        print("YES")
    else:
        print("NO")