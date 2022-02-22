n = int(input()) + 1
ans = []
visited = [False for _ in range(n)]
for i in range(2, n):
    x = i
    while x < n:
        if not visited[x]:
            visited[x] = 1
            ans.append(x)
        x *= i
    j = i
    while j < n:
        visited[j] = 1
        j += i
print(len(ans))
print(*ans, sep=" ")