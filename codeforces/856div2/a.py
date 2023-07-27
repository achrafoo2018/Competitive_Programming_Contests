for _ in range(int(input())):
    n = int(input())
    s = list(filter(lambda y : len(y) == n-1, input().split(" ")))
    if s[0] == s[1][::-1]:
        print("YES")
    else:
        print("NO")