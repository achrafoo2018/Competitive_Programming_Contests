for _ in range(int(input())):
    n = int(input())
    t = input()
    mp = dict()
    alpha = list("abcdefghijklmnopqrstuvwxyz")
    for i in t:
        if i not in mp:
            if i == alpha[0]:
                c = alpha[0]
                alpha.pop(0)
                alpha.insert(1, c)
            while alpha[0] in mp and mp[alpha[0]] == i:
                c = alpha[0]    
                alpha.pop(0)
                alpha.insert(1, c)
            mp[i] = alpha[0]
            alpha.pop(0)
        print(alpha)
    s = ""
    for i in t:
        s += mp[i]
    print(s)