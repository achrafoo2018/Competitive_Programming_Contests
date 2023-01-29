t = int(input())
for _ in range(t):
    s = "".join(sorted(input()))
    t = input()
    aa = s.count('a')
    bb = s.count('b')
    cc = s.count('c')
    if aa and bb and cc and t == "abc":
        print("a"*aa + "c" * cc + "b" * bb + s[aa+bb+cc:])
    else:
        print(s)
