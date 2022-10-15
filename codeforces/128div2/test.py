def getIdxOfZeroFromLeft(s):
    for i in range(len(s)):
        if s[i] == '0':
            return i
    return -1

def getIdxOfZeroFromRight(s):
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '0':
            return i
    return -1


def check(s, mid):
    left = getIdxOfZeroFromLeft(s[:mid])
    right = getIdxOfZeroFromRight(s[mid:])
    return left == right

t = int(input())
for _ in range(t):
    s = input().strip('0')
    deletedOnes = 0
    zeros = s.count('0')
    l, r = 0, len(s) - 1
    ans = 10**10
    while l < r:
        mid = (l + r) // 2
        if check(s, mid):
            r = mid
            ans = min(ans, mid)
        else:
            l = mid + 1
    print(ans if ans != 10**10 else 0)