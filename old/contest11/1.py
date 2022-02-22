alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
with open('collectingofficer.in', 'r') as file:
    t = int(file.readline())
    for _ in range(t):
        n = int(file.readline())
        s = file.readline()
        i = 0
        for j in range(n):
            i = j
            a, r = 0, 0
            while s[i] != 'A' and i < n:
                i += 1
            if i < n:
                a += 1
                r += 1
                i += 1
            else:
                break
            for c in alpha:
                while s[i] != c and i < n:
                    i += 1
                    r += 1
                if i 
