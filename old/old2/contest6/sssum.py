n, s = map(int, input().split(" "))
arr = sorted(map(int, input().split(" ")))
sm = 0
ans = 0
for i in range(n):
    sm += arr[i]
    if sm > s:
        break
    ans += 1
print(ans)