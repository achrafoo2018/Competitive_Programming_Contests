print(f"{10**5} {10**5}")
import random
for i in range(10**5):
    print(random.randint(1, 10**5), end=" ")
for i in range(10**5):
    l = random.randint(0, 10**5-1)
    r = random.randint(l, 10**5-1)
    h = random.randint(0, 10**5)
    print(f'{l} {r} {h}')
    