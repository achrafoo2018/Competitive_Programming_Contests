for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = ""
    for i in range(n):
        if s[i] == '0' and (i == n-1 or s[i+1] != '0'):
            ans = ans[:-2]
            ans += chr(int(s[i-2:i])+ord('a')-1)
        else:
            ans += chr(ord('a')+int(s[i])-1)
    print(ans)