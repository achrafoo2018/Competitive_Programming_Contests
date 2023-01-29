n , m = [int(i) for i in input().split(" ")]
arr = [int(i) for i in input().split(" ")]
arr.sort()
MOD = 10**9+7
ans = pow(2, arr[-1], MOD)
if m == 1:
    for i in range(n-1):
        ans += pow(2, arr[i], MOD)
print(ans % MOD)
    