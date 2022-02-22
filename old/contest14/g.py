t = int(input())
for _ in range(t):
    n = int(input())
    f2 = (n//2)**0.5
    f4 = (n//4)**0.5
    if(not n % 2 and (f2 % int(f2)) == 0):
        print("YES")
    elif(not n % 4 and (f4 % int(f4)) == 0):
        print("YES")
    else:
        print("NO")