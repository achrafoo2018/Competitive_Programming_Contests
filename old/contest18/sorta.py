n = int(input())
arr = [int(i) for i in input().split(" ")]
l, r = -1, -1
cond = False
for i in range(1 ,n):
    if arr[i-1] > arr[i] and not cond:
        l = i-1
        cond = True
    elif arr[i-1] < arr[i] and cond:
        r = i - 1
        break
if l == r:
    print("yes\n1 1")
else:
    if r == -1:
        r = n-1
    if sorted(arr) == (arr[:l]+(arr[l:r+1])[::-1]+arr[r+1:]):
        print(f"yes\n{l+1} {r+1}")
    else:
        print("no")
