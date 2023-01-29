for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    even, odd = 0, 0
    for i in arr:
        even += (i % 2 == 0)
        odd += (i % 2)
    dp = [[[[0]*3]*3]*102]*102
    def work(even, odd, winner, io):
        if ie == 0 and io == 0:
            return 
        if o in dp[e]:
            return dp[e][o]
        dp[e][o] = work(e+1, o, ie-1, io) or work(e, o+1, ie, io-1)
        return dp[e][o]
    if work()