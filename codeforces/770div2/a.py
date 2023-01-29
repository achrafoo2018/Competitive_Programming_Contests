for _ in range(int(input())):
    n, k = map(int, input().split(" "))
    s = input()
    if s != s[::-1] and k > 0:
        print(2)
    else:
        print(1)