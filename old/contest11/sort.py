def sort(u):
    if vis[u]:
        return
    vis[u] = True
    ans.append(a[u])
    for i in range(n):
        if a[u] and a[i]:
            sort(i)
    for i in range(n):
        if (a[u] and not a[i]) == a[u]:
            sort(i)

with open("sorting.in", 'r') as file:
    vis = [False] * 10**5
    ans = []
    n = int(file.readline())
    a = [int(i) for i in file.readline().split(" ")]
    sort(0)
    print(*ans)
