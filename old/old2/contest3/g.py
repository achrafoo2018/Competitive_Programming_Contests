for _ in range(int(input())):
    input() # \n
    n, k = map(int, input().split(" "))
    grid = []
    for i in range(n):
        x, y, t = map(int, input().split(" "))
        grid.append([*sorted([x, y]), t])
    grid = sorted(grid)
    print(grid)