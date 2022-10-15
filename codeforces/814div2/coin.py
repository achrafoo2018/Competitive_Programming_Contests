n, s = [int(i) for i in input().split(" ")]
arr = [1,]
for i in input().split(" "):
    arr.append(arr[-1]*int(i))

value = [10**9 *]
ready = [False for i in range(n+1)]
def solve(x):
    if x == 0:
        return 0
    if ready[x]:
        return value[x];
    best = 10**9
    for c in arr:
        best = min(best, solve(x-c)+1);
    value[x] = best
    ready[x] = True
    return best

print(solve(s))