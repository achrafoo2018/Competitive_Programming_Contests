for _ in range(int(input())):
    a, b, c = map(int, input().split(" "))
    if b-a == c-b or (a == b == c):
        print("YES")
        continue
    if ( a + c ) % (2 * b) == 0:
        print("YES")
        continue
    if (2*b - a) % c  == 0 and (2*b - a) > 0:
        print("YES")
        continue    
    if (2*b - c) % a  == 0 and (2*b - c) > 0:
        print("YES")
        continue    
    print("NO")
