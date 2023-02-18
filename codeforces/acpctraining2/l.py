s = input()
x, y = map(int, input().split(' '))
ans = eval(s)
arr = s.split('+')
res = x * s.count('+') + y * s.count('*')
r = 0
for j in range(len(arr)):
    i = arr[j]
    if '*' in i:
        pp = i.split('*')
        c = int(pp[0])
        res += len(str(c))
        for k in range(1, len(pp)):
            c *= int(pp[k])
            res += len(str(pp[k]))
            if len(arr) == 1 and k == len(pp)-1:
                continue
            res += len(str(c))
        r += c
    else:
        res += len(i)
        r += int(i)
    # print(res)
    if j == 0 or j == len(arr)-1:
        continue
    res += len(str(r))

print(f"{ans} {res}")