t = int(input())
for _ in range(t):
    k = int(input())
    n = input()
    found = False
    if k == 1:
        print(k)
        print(n)
    else:
        for i in n:
            if int(i) not in [2, 3, 5, 7]:
                print(len(i))
                print(i)
                found = True
                break
        if not found:
            print(2)
            for i in range(k-1):
                for j in range(i+1, k):
                    if int(n[i]+n[j]) not in [53, 23, 73, 37]:
                        print(n[i]+n[j])
                        found = True
                        break
                if found:
                    break
            
        
