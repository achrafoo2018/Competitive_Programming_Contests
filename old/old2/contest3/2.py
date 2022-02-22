import math
for _ in range(int(input())):
    n = int(input())
    s = set()
    i = 1
    while i*i <= n:
        s.add(i**2)
        i += 1
    i = 1
    while i**3 <= n:
        s.add(i**3)
        i += 1
    print(len(s))