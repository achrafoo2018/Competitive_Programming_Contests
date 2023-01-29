with open('equal.in', "r") as file:
    t = int(file.readline())
    for _ in range(t):
        a, b, c = [int(i) for i in file.readline().split(" ")]
        if a == b or a == c or b == c:
            print("YES")
        else:
            print("NO")

