for _ in range(int(input())):
    n = int(input())
    s = input()
    name = "Timur"
    if len(s) != len(name):
        print("NO")
        continue
    cond = True
    for i in name:
        if i not in s:
            cond = False
            break
    print("YES" if cond else "NO")