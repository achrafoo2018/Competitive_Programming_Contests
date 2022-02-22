import collections
t = int(input())
for case in range(1, t+1):
    s = input().lower()
    if len(set(s)) == 1:
        print(f"Case #{case}: 0")
        continue
    maxv = -1
    maxc = -1
    mov = None
    moc = None
    for i in s:
        c = s.count(i)
        if i in "aeuio":
            if(c > maxv):
                maxv = c
                mov = i
        else:
            if(c > maxc):
                maxc = c
                moc = i
    res = 0
    for i in s:
        if i == mov:
            continue
        if i in "aeuio":
            res += 2
        else:
            res += 1
    res2 = 0
    for i in s:
        if i == moc:
            continue
        if i in "aeyuio":
            res2 += 1
        else:
            res2 += 2
    print(f"Case #{case}: {min(res, res2)}")
        