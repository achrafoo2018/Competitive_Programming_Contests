for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    isSorted = True
    for i in range(1, n):
        if arr[i] < arr[i-1]:
            isSorted = False
            break
    if isSorted:
        print(0)
    elif arr[-2] <= arr[-1] and arr[-2] - arr[-1] <= arr[-2] and arr[-2] - arr[-1] <= arr[-1]:
        print(n-2)
        for i in range(1, n-1):
            print(i, n-1, n)
    else:
        print(-1)