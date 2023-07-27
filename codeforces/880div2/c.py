for _ in range(int(input())):
    a, b, c, k = [int(x) for x in input().split(" ")]
    mna = int("1" + "0" * (a-1))
    mnb = int("1" + "0" * (b-1))
    la = mna
    ra = mna * 10 - 1
    aa = -1
    bb = -1
    while la <= ra:
        mida = (la + ra) // 2
        lb = mnb
        rb = mnb * 10 - 1
        found = False
        while lb <= rb:
            midb = (lb + rb) // 2
            if len(str(mida + midb)) >= c:
                bb = midb
                found = True
                rb = midb - 1
            else:
                lb = midb + 1
        if found:
            aa = mida
            ra = mida - 1
        else:
            la = mida + 1

    x = mnb * 10 - 1 - bb
    if x >= k:
        bb += (k - 1)
        if len(str(aa+bb)) == c:
            print(f"{aa} + {bb} = {aa+bb}")
        else:
            print(-1)
        continue
    
    aaa = aa
    bbb = bb
    pp = 0
    for i in range(k):
        bbb += 1
        if bbb > (mnb * 10 - 1):
            aaa += 1
            pp += 1
            bbb = mnb - pp 
        if len(str(aaa+bbb)) > c or len(str(aaa)) > a or len(str(bbb)) > b:
            break
    if len(str(aaa+bbb)) != c or len(str(aaa)) != a:
        print(-1)
    else:
        print(f"{aaa} + {bbb} = {aaa+bbb}")
