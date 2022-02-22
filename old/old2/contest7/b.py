for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    s = input()
    arr2 = [1]*n
    zeros = s.count('0')
    for i in range(n):
        arr2[arr[i]-1] = i
    ans = [1]*n
    z = 0
    o = 0
    for i in range(n):
        idx = arr2[i]
        if s[idx] == '0':
            ans[idx] = z + 1
            z += 1
        else:
            ans[idx] = o+zeros+1
            o += 1
    print(*ans, sep=" ")

