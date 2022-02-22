s = input()
t = input()
if len(s) == 1:
    print("YES")
    exit(0)
x = (ord(t[0]) - ord(s[0]))
if x < 0:
    x += 26
for i in range(1, len(s)):
    k = (ord(t[i]) - ord(s[i]))
    if k < 0:
        k += 26
    if k != x:
        print("NO")
        exit(0)
print("YES")
