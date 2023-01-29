for _ in range(int(input())):
    n = int(input())
    arr = []
    for i in range(n):
        l, r, c = map(int, input().split(" "))  
        arr.append([l, r, c])
    costl, costh = arr[0][2], 0
    print(costl+costh)
    l, h = arr[0][0], arr[0][1]
    for i in range(1, n):
        ll = arr[i][0]
        hh = arr[i][1]
        cost = arr[i][2]
        if l > ll and h < hh:
            l = ll
            h = hh
            costl = cost
            costh = 0
            print(costl+costh)
            continue
        if l > ll:
            l = ll
            if h == hh:
                costl = cost
                costh = 0
            else:
                if costh == 0 and h > hh:
                    costh = costl
                costl = cost
            print(costl+costh)
            continue
        if h < hh:
            h = hh
            if l == ll:
                costl = cost
                costh = 0
            else:
                costh = cost
            print(costl+costh)
            continue
        if l == ll and h == hh and cost < costl+costh:
            costl = cost
            costh = 0
            print(costl+costh)
            continue
        if l == ll and cost < costl and costh != 0:
            costl = cost
            print(costl+costh)
            continue
        if h == hh and cost < costh:
            costh = cost
            print(costl+costh)
            continue
        print(costl+costh)
        