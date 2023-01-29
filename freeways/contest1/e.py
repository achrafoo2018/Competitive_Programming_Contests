n = int(input())
arr = list(map(int, input().split(" ")))
arr.sort()
mp = dict()
for i in arr:
    if i in mp:
        mp[i] += 1
    else:
        mp[i] = 1
def solve():
    dp = dict()
    for idx in range(n):
        s = 0 if (arr[idx]-1) not in mp else mp[arr[idx]-1]
        x = dp[arr[idx-mp[arr[idx]]-s]] if arr[idx-mp[arr[idx]]-s] in dp else 0
        x2 = dp[arr[idx-mp[arr[idx]]]] if arr[idx-mp[arr[idx]]] in dp else 0
        dp[arr[idx]] = max(arr[idx]*mp[arr[idx]] + x, x2)
    return dp[arr[n-1]]
print(solve())
