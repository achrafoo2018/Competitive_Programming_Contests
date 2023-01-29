for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    ans = 0
    for i in range(n):
        ans |= arr[i]
    print(ans)