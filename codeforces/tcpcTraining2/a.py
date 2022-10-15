ans = 0
for n in range(int(input())):
    s = input()
    if(s[0] - 'A' == n):
        ans += 1
print(ans)