def isPalindrome(string, low, high):
    while low < high:
        if string[low] != string[high]:
            return False
        low += 1
        high -= 1
    return True

def solve(s, l):
    low = 0
    high = len(s) - 1
    res = 0
    while low < high:
        if l == s[high] and l == s[low]:
            low += 1
            high -= 1
        elif s[high] == l:
            high -= 1
            res += 1
        elif s[low] == l:
            low += 1
            res += 1
        elif s[low] != s[high]:
            return -1
        else:
            low += 1
            high -= 1
        if isPalindrome(s, low, high):
            return res
    return -1

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    if s == s[::-1]:
        print(0)
        continue
    se = set(s)
    ans = 10**10
    for i in se:
        k = solve(s, i)
        if k != -1:
            ans = min(ans, k)
    print(ans if ans != 10**10 else -1)