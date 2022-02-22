for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    mn = arr.index(min(arr))
    if mn == n-1:
        print(arr[mn])
        continue
    for i in range(2, n):
        if arr[i] > arr[i-1]:
            diff = arr[i]
             
