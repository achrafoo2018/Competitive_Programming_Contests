t = int(input())
for _ in range(t):
    n, k = [int(i) for i in input().split(' ')]
    if k == 1:
        res = int(str(n)[0]*len(str(n)))
        if(res >= n):
            print(res)
        else:
            print(str(int(str(res)[0])+1)*len(str(res)))
    else:
        for i in range(n, 10**9+1):
            if(len(set(str(i))) == k):
                print(i)
                break
     