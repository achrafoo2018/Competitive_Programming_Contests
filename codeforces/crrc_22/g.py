n = int(input())
arr = []
for i in range(n):
    arr.append(input().split(" "))
ans = [1 for _ in range(60*60*24)]
for i in range(n):
    x = arr[i][0].split(":")
    y = arr[i][1].split(":")
    x = list(map(int, x))
    y = list(map(int, y))
    for j 
    print(x)
print(sum(ans))