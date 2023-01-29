n, a, b =map(int,input().split())
arr = []
for i in range(1, n):
    arr.append(min(a//i, b//(n-i)))
print(max(arr))