st = set()
for i in range(2, 10**6 + 7):
    j = i * i
    x = 1 + i + j
    while x <= 10**18 + 10:
        st.add(x)
        j *= i
        x += j

for _ in range(int(input())):
    n = int(input())
    if n < 7:
        print("NO")
        continue
    k = int((n-1) ** 0.5)
    if (k * (k + 1) == (n - 1) or (k - 1) * k == (n - 1)):
        print("YES")
        continue
    if n in st:
        print("YES")
    else:
        print("NO")