for _ in range(int(input())):
    n, s = input().split(" ")
    n = int(n)
    f = set(s)
    
    if len(s) == 1 and s not in ['8', '1', '0']:
        print("NO")
        continue
    if len(f) == 1 and ('1' in f  or '8' in f or '0' in f):
        print("YES")
    else:
        l, r = 0, n-1
        cond = True
        while l < r:
            if s[l] not in ['8', '0', '1'] or s[r] not in ['9', '6', '8', '0', '1']:
                cond = False
                break
            if s[l] != s[r]:
                if not( s[l] == '6' and s[r] == '9' or s[l] == '9' and s[r] =='6'):
                    cond = False
                    break
            l += 1
            r -= 1
        if cond:
            print("YES")
        else:
            print("NO")