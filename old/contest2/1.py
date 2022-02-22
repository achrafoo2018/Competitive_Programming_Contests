t = int(input())
arr = [i for i in range(1, 1667) if i % 3 != 0 and str(i)[-1] != '3']
for _ in range(t):
    k = int(input()) 
    print(arr[k-1])   