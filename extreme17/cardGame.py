arr = ['2','3','4','5','6','7','8','9','T','J','Q','K','A']
mp = dict()
for i in range(len(arr)):
    mp[arr[i]] = i
for _ in range(int(input())):
    a = "".join(input().split(" "))
    b = "".join(input().split(" "))
    l1 = 0
    l2 = 0
    seen = set()
    cond = False
    seen.add((a[l1:]+":"+b[l2:]))
    while l1 < len(a) and l2 < len(b):
        if mp[a[l1]] > mp[b[l2]]:
            a += (b[l2])
        elif mp[a[l1]] < mp[b[l2]]:
            b += (a[l1])
        else:
            a += b[l2]
            b += a[l1]
        l1 += 1
        l2 += 1
        if (a[l1:]+":"+b[l2:]) in seen:
            cond = True
            break
        seen.add((a[l1:]+":"+b[l2:]))
    # print(f"a={a}, b={b}, l1={l1}, l2={l2}")
    if cond:
        print("draw")
    elif l1 == len(a):
        print("player 2")
    else: 
        print("player 1") 

