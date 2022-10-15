for _ in range(int(input())):
    s = input()
    c = input()
    cond = False
    for i in range(len(s)):
        if s[i] == c and (i+1) % 2 == 1:
            cond = True
            break
    if cond:
        print("YES")
    else:
        print("NO")