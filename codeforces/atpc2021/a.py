n = int(input())
arr = []
for i in range(n):
    a = input().split(" ")
    for j in range(3):
        a[j] = int(a[j])
    arr.append(a)
arr.sort()
print(" ".join(arr[-1][3:]))