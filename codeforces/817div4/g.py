for _ in range(int(input())):
    n = int(input())
    ans = 1
    for i in range(1, n-3):
        print(i, end=" ")
        if i > 1:
            ans ^= i
    print(f"{2**29} {2**30} {ans}")