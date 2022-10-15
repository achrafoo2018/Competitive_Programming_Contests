for _ in range(int(input())):
    a, b, c, d = [int(i) for i in input().split(" ")]
    if a / b == c / d:
        print(0)
        continue
    if a == 0 or c == 0 or (a/b) % (c/d) == 0 or (c/d) % (a/b) == 0 or (a == c and (b%d == 0 or d%b==0)) or (b == d and (a%c == 0 or c%a==0)):
        print(1)
    else:
        print(2)
