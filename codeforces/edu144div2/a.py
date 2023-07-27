s = ""
for i in range(1000):
    if i % 5 == 0 and i % 3 == 0:
        s += "FB"
    elif i % 3 == 0:
        s += "F"
    elif i % 5 == 0:
        s += 'B'
for _ in range(int(input())):
    _ = input()
    ss = input()
    if ss not in s:
        print("NO")
    else:
        print("YES")