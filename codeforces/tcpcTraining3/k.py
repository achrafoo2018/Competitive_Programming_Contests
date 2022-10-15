s = input()
t = input()
ans = ""
for i in s:
    if t.count(i) != s.count(i) and i not in ans:
        ans += i
print(ans)