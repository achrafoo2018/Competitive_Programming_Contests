a, b = map(int, input().split(" "))
if abs(a-b) <= 1:
    print("Equal")
elif a > b:
    print("Masha")
else:
    print("Dasha")