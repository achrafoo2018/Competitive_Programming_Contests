import math

def ternary_search(a, l, r):
    # Precision for our ternary search
    eps = 1e-8

    while r - l > eps:
        m1 = l + (r - l) / 3
        m2 = r - (r - l) / 3

        f_m1 = abs(math.cos(int(m1) * a))
        f_m2 = abs(math.cos(int(m2) * a))

        # Move towards the smaller value of |cos(n * a)|
        if f_m1 < f_m2:
            r = m2
        else:
            l = m1
    return int(l)

for _ in range(int(input())):
    a = float(input())
    a = math.radians(a)
    L = 360
    result = ternary_search(a, 1, L)

    print(result)
