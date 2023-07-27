def min_operations(A, B):
    N = len(A)
    dp = [[0, 0] for _ in range(N)]

    # Base case
    dp[0][0] = 0
    dp[0][1] = 1

    for i in range(1, N):
        if A[i] != B[i]:
            if A[i] != A[i-1] and B[i] != B[i-1]:
                dp[i][0] = min(dp[i-1][0], dp[i-1][1])
            else:
                dp[i][0] = dp[i-1][1] if A[i] != A[i-1] else dp[i-1][0]
            dp[i][1] = dp[i-1][0] + 1
        else:
            dp[i][0] = dp[i-1][0]
            dp[i][1] = dp[i-1][1]

    return min(dp[N-1][0], dp[N-1][1])

# Example usage:
A = [1, 10, 10, 2, 7]
B = [9, 3, 3, 5, 5]
print(min_operations(A, B))