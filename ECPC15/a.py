for _ in range(int(input())):
    n = input()
    arr = list(n)
    arr.sort()
    arr = arr[::-1]
    print(arr)