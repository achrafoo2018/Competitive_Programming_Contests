n = int(input())
mp = dict()
mx = 0
arr = list(map(int, input().split(" ")))
arr.sort()
print(*arr, sep=" ")
exit()
for i in range(n):
    x = int(arr[i])
    mx = max(mx, x)
    if x not in mp:
        mp[x] = 1
    else:
        mp[x] += 1
for i in range(2, mx+1):
    if i not in mp or mp[i] > mp[i-1]:
        print("NO")
        exit()
print("YES")
