n = int(input())
s = list(input())
ans = ""
if not n & 1:
    for i in range(n):
        if i % 2 == 1:
            ans += s[i]
        else:
            ans = s[i] + ans
else:
    for i in range(n):
        if i % 2 == 0:
            ans += s[i]
        else:
            ans = s[i] + ans
print(ans)

    