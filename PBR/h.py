from math import log,trunc
 
# function to check if power of 8
def checkPowerof8(n):
 
    # calculate log8(n)
    i = log(n, 8)
 
    # check if i is an integer or not
    return (i - trunc(i) < 0.000001);
 
for _ in range(int(input())):
    n = int(input())
    if checkPowerof8(n):
        print("Ala")
    else:
        print("Azer")

