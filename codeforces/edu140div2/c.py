MOD = 998244353

def count_binary_strings(i, j, a):
    # Base case: i = 1
    if i == 1:
        if a[1][1] == 0:
            return 2
        if a[1][1] == 1:
            return 1
        if a[1][1] == 2:
            return 2

    # General case: i > 1
    if a[1][i-1] == 0:
        return (count_binary_strings(i-1, 0, a) * 2) % MOD
    if a[1][i-1] == 1:
        return count_binary_strings(i-1, 1, a)
    if a[1][i-1] == 2:
        return (count_binary_strings(i-1, 0, a) + count_binary_strings(i-1, 2, a)) % MOD

# Test the function with the first example from the prompt
n = 3
a = [[0, 1, 2], [1, 0], [1]]
print(count_binary_strings(n, 0, a))  # Expected output: 6

# Test the function with the second example from the prompt
n = 3
a = [[1, 1, 2], [1, 0], [1]]
print(count_binary_strings(n, 0, a))  # Expected output: 2
