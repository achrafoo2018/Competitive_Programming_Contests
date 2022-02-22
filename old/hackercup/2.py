q = int(input())
for _ in range(q):
    l, r, d = [int(i) for i in input().split(" ")]
    if d < l or d > r:
        print(d)
    else:
        print(d*(r//d+1))