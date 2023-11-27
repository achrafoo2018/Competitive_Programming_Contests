n = int(input())
mp = dict()
k = 1
for i in range(n):
    s = input().split(" ")[1:]
    for j in s:
        mp[j] = k
    k += 1

m = int(input())
for i in range(m):
    pass1, pass2 = input().split(" ")
    
    if cond:
        print("REJECT")
    else:
        print("OK")