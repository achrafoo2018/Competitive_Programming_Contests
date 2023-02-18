x, y = input().split(" ")
if x.isnumeric() and y.isnumeric():
    print(int(x)-int(y))
else:
    print("NaN")