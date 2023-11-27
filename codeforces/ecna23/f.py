import math
n = int(input())
arr = [int(math.log2(int(i))) for i in input().split(" ")]
maxi = 0
for i in range(1103):
    if len(arr) == 0:
        break
    maxi = max(maxi, max(arr))
    for j in range(len(arr)-1):
        if arr[j] == i and arr[j+1] == i:
            arr[j] = i+1
            arr[j+1] = -1
    temp = []
    for el in arr:
        if el == -1 or el == i:
            continue
        temp.append(el)
    arr = temp[:]

print(2**maxi)