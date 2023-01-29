t = int(input())
for _ in range(t):
    n = int(input())
    if n & 1:
        n -= 1
        if (n//2) & 1:
            print(f"{n//2-2} {n//2+2} 1")
        else:
            print(f"{n//2-1} {n//2+1} 1")
    else:
        print(f"{n//2} {n//2-1} 1")