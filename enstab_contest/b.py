s = input()
ans = ""
for i in range(len(s)):
    if i % 2 == 0:
        ans += s[i].upper()
    else:
        ans += s[i].lower()
print(ans)