for _ in range(int(input())):
    s = input()
    print("YES" if s[:len(s)//2] == s[len(s)//2:] else "NO")