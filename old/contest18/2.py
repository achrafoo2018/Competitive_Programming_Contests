t = int(input())
for _ in range(t):
    n, a, b = [int(i) for i in input().split(" ")]
    if abs(a-b) > 1 or (n % 2 == 0 and a != b):
        print(-1)
        continue
    arr = [i for i in range(1, n+1)]
    res = []
    if a < b:
        for i in range(a):
            if i % 2 == 0:
                res.append(arr[i])
            else:
                res.append(arr[n-i])
        
    elif a > b:
    else: