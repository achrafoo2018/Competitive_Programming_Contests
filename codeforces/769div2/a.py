for _ in range(int(input())):
    n = int(input())
    s = input()
    if n >= 3:
        print("NO")
    else:
        if s == s[::-1] and len(s) == 2:
            print("NO")
        else:
            print("YES")