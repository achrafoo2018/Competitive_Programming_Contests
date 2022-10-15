N = 4
def isSafe(grid, row, col, num):
    for x in range(4):
        if grid[row][x] == num:
            return False
    for x in range(4):
        if grid[x][col] == num:
            return False
    startRow = row - row % 2
    startCol = col - col % 2
    for i in range(2):
        for j in range(2):
            if grid[i + startRow][j + startCol] == num:
                return False
    return True
 

def solveSudoku(grid, row, col):
    if (row == N - 1 and col == N):
        return True
    if col == N:
        row += 1
        col = 0
    if grid[row][col] > 0:
        return solveSudoku(grid, row, col + 1)
    for num in range(1, N + 1, 1):
        if isSafe(grid, row, col, num):
            grid[row][col] = num
            if solveSudoku(grid, row, col + 1):
                return True
        grid[row][col] = 0
    return False
for _ in range(int(input())):
    arr = []
    for i in range(4):
        x = input().split(" ")
        for i in range(4):
            if x[i].isnumeric():
                x[i] = int(x[i]) + 1
            else:
                x[i] = 0
        arr.append(x)
    solveSudoku(arr, 0, 0)
    for i in range(4):
        for j in range(4):
            arr[i][j] -= 1
    for i in range(4):
        print(*arr[i], sep=" ")