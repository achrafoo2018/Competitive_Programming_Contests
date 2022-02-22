with open("lis.in", "r") as file:
    n = file.readline()
    n = int(n)
    if n < 20:
        print(9)
    else:
        print(100)