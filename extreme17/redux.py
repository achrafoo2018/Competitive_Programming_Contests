for _ in range(int(input())):
    n = int(input())
    s = input()
    x = 1
    ans = ""
    if "the" in s.split(" "):
        x *= -1
    for i in s:
        if i.isalpha():
            shift = (ord(i) - ord('a') + (n * x) + 26) % 25
            ans += chr(ord('a') + shift)
        else:
            ans += i
    print(ans)
