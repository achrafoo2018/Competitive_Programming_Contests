import re
import bisect
s = input()
arr1 = [_.start() for _ in re.finditer("heavy", s)] 
arr2 = [_.start() for _ in re.finditer("metal", s)] 
n = len(arr1)
n2 = len(arr2)
ans = 0
for i in arr1:
    ans += (n2 - bisect.bisect_right(arr2, i))
print(ans)