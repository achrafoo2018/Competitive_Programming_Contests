n = int(input())
if(n < 10):
    print(n)
else:
    s = ""
    for i in range(1, n+1):
        s += str(i)
    print(s[n-1])