def min_k_factorial(x):
    twoFactor = 0
    threeFactor = 0
    fiveFactor = 0
    while x % 2 == 0:
        x = x // 2
        twoFactor += 1
    while x % 3 == 0:
        x = x // 3
        threeFactor += 1
    while x % 5 == 0:
        x = x // 5
        fiveFactor += 1
    return max(twoFactor, threeFactor, fiveFactor) + 1

x = int(input())
print(min_k_factorial(x))