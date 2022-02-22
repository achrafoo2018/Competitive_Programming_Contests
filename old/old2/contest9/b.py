for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = s[0]
    arr = [ord(s[0])]
    i = 1
    if n >= 2 and s[1] != s[0]:
        while i < n:
            if ord(s[i]) > ord(s[i-1]):
                break
            ans += s[i]
            i += 1
    print(ans+ans[::-1])