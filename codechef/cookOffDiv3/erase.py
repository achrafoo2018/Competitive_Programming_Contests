for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split(" ")))
    mx = arr.index(max(arr))
    mn = arr.index(min(arr))
    if mn == n-1 or mx == 0:
        print("NO")
        continue
    if mn < mx:
        print("YES")
        continue
    else:
        mxmn = max(arr[mn:])
        mnmx = min(arr[:mx])
        mxmid = max(arr[mx+1:mn+1])
        if mnmx < mxmn and mxmid < mxmn:
            print("YES")
        else:
            print("NO")
    