import math
s1, x = [int(i) for i in input().split(" ")]
s2, p, f = [int(i) for i in input().split(" ")]
f1 = (x-p) / s1
f2 = x / s2
if f1 < f2:
    print(0)
else:
    ans = 0
    if(f1==f2):
        ans += 1
    else:
        ans += math.ceil((f1-f2)/f)
    print(ans)