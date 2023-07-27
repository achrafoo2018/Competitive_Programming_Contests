for _ in range(int(input())):
    a = input()
    b = input()
    if a[0] == b[0]:
        print("YES")
        print(a[0]+"*")
        continue
    elif a[-1] == b[-1]:
        print("YES")
        print("*"+a[-1])
        continue
    ans = ""
    for i in range(1, len(a)):
        p = a[i-1:i+1]
        if p in b:
            ans = p
            break
    if ans:
        print("YES")
        print(f"*{ans}*")
    else:
        print("NO")
    