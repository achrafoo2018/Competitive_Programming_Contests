t = int(input())
for _ in range(t):
    x1, p1 = [int(i) for i in input().split(" ")]
    x2, p2 = [int(i) for i in input().split(" ")]
    if p1 == p2 and x1 == x2:
        print("=")
    elif p1 > p2 and x1 >= x2:
        print(">")
    elif p1 < p2 and x1 <= x2:
        print("<")
    else:
        12 2 
        2  2
