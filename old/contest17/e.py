from math import sqrt
n, k = [int(i) for i in input().split(" ")]
ans = 0.0
arr = []
for _ in range(n):
    arr.append([int(i) for i in input().split(" ")])

for i in range(1, n):
    ans += sqrt((arr[i][0]-arr[i-1][0])**2+(arr[i][1]-arr[i-1][1])**2) / 50
print("%.10f"%(ans*k))