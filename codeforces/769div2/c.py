for _ in range(int(input())):
    a, b = map(int, input().split(" "))
    tmp_a = str(bin(a))[2:]
    tmp_b = str(bin(b))[2:]
    tmp_b = tmp_b[-len(tmp_a):]
    x, x2 = 0, 0
    n = len(tmp_a)
    for i in range(n-1, -1, -1):
        if tmp_a[i] == '0' and tmp_b[i] == '1':
            x2 += (1 << n-i-1)
        elif tmp_a[i] == '1' and tmp_b[i] == '0':
            x += (1 << n-i-1)
            x -= x2
            x2 = 0
    ans = min(b-a, x + 1)
    print(ans)