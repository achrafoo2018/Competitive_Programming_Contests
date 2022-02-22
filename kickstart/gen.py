from random import randint
for i in range(100):
    for j in range(100):
        if j % 2:
            print('B', end="")
        else:
            print('R', end="")
    print()
