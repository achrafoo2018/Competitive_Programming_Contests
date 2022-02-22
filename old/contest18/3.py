t = int(input())
for _ in range(t):
    n = int(input())
    m1 = [int(i) for i in input().split(" ")]
    m2 = [int(i) for i in input().split(" ")]
    mp1 = m1.index(max(m1))
    mp2 = m2.index(max(m2))         
    ans = ["0"]*n
    ans[mp1] = "1"
    ans[mp2] = "1"
    min1 = m2[mp1]
    min2 = m1[mp2]
    for i in range(n):
        if m1[i] >= min2:
            min1 = min(min1, m2[i])
        if m2[i] >= min1:
            min2 = min(min2, m1[i])
    for i in range(n):
        if m1[i] >= min2 or m2[i] >= min1:
            ans[i] = '1'
    print("".join(ans))