t = int(input())
for _ in range(t):
    n = input()
    if(int(n[len(n)-1]) % 2 == 0):
        print(0)
    elif int(n[0]) % 2 == 0:
        print(1)
    else:
        pos = -1
        for i in range(len(n)):
            if int(n[i]) % 2 == 0:
                pos = i
        print(pos if pos == -1 else 2)