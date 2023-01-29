for _ in range(int(input())):
    input()
    n, m = map(int, input().split(" "))
    numbers = []
    for i in range(n):
        numbers.append(input())
    newFriend = input()
    ans = []
    l, r = 0, m
    while l < r - 1:
        i = 0
        while i < n:
            if newFriend[l:r] in numbers[i]:
                ans.append([l, r, i])
                l = r
                break
            i += 1
        if i == n:
            l -= 1
        
