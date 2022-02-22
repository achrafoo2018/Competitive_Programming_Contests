from sys import stdout
for _ in range(int(input())):
    n = int(input())
    ans = [0] * n
    for i in range(n):
        print(f"? {i+1}")
        input()
        stdout.flush()
        print(f"? {i+1}")
        ans[i] = int(input())
        stdout.flush()
    print("! ", end="")
    print(*ans, sep=" ")

