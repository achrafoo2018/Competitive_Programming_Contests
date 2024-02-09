T = int(input())

for _ in range(T):
    h, c, t = [int(i) for i in input().split(" ")]
    if ((h+c) >= 2 * t):
        print(2)
        continue
    ans = (c-t+c-2*t+h-1) // (c-2*t+h)
    res = ans
    mx = 10**18
    for i in range(max(1, ans-10), ans+10):
        x = abs((i*h + (i-1)*c) / 1.0 * (2*i-1) - t)
        if(x < mx):
            mx = x
            res = i
    print(2*res-1)

