import random
print(1000)
for i in range(1000):
    print(50)
    arr = [i for i in range(1, 51)]
    random.shuffle(arr)
    print(*arr, sep=" ")

