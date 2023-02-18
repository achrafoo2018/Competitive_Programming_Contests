for _ in range(int(input())):
    _ = input()
    s = input()
    s += input()[::-1]
    ans = 0
    for i in range(1, len(s)):
        ans += s[i] == s[i-1]
    print("YES" if ans <= 1 else "NO")
