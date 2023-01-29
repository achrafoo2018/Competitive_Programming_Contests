from math import comb
t = int(input())
for _ in range(t):
    n = int(input())
    arr = input().split(" ")
    zeros = arr.count("0")
    ones = arr.count("1")
    if zeros+ones == 0:
        print(0)
    elif zeros == 0:
        print(ones)
    else:
        ans = 0
        for i in range(zeros+1):
            ans += comb(zeros, i)
        print(ans*ones)