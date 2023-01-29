n = input()
ans = 0
for i in n:
    ans += int(i)
print("YES" if (ans%9 == 0 and int(n[-1]) %2 == 0) else "NO")