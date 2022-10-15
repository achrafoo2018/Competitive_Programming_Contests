from sys import stdout

found = False
a, b = 1, 2
for i in range(25):
    print(f"? {a} {b}")
    ans = input()
    if ans == "-1":
        print(f"! {b-1}")
        found = 1
        break
    stdout.flush()
    print(f"? {b} {a}")
    res = input()
    stdout.flush()
    if ans != res:
        ans, res = int(ans), int(res)
        ans += res
        print(f"! {ans}")
        found = True
        break
    b += 1
if not found:
    ans, res = int(ans), int(res)
    ans += res
    print(f"! {ans}")



