for _ in range(int(input())):
    s = input()
    dp = dict()
    def solve(i, j):
        if i > j:
            return
        if j in dp[i]:
            return dp[i][j]
        dp[i][j] =  s
