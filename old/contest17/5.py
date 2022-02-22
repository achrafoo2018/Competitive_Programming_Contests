n, q = [int(i) for i in input().split(" ")]
s = input()
alpha = "abcdefghijklmnopqrstuvwxyz"
prefix = [0]
for i in range(len(s)):
    pos = alpha.index(s[i])
    prefix.append(prefix[i]+pos+1)
for _ in range(q):
    l, r = [int(i) for i in input().split(" ")]
    ans = prefix[r] - prefix[l-1]
    print(ans)