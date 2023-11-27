for _ in range(int(input())):
    s = input()
    if s == '()':
        print("NO")
        continue
    ans = ""
    for i in s:
        ans += '('
    for i in s:
        ans += ')'
    ans2 = ""
    for i in s:
        ans2 += '()'
    print("YES")
    if ")(" in s:
        print(ans)
    else:
        print(ans2)