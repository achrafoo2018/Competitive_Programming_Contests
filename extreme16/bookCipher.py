import re
p = int(input())
n = int(input())
r, c = [int(i) for i in input().split(",")]
position = input()
arr = []
for i in range(p):
    s = input()
    arr.append(s)

encoded = ""
for i in range(n):
    s = input()
    s = re.sub('<[^>]+>', '', s)
    encoded += s

book = []
i = 0
j = c
while len(book) < r:
    book.append(encoded[i:j])
    i = j
    j += c


def search(cc, cond):
    if cond:
        for k in range(r):
            for l in range(c):
                if book[k][l] == cc:
                    return (k+1, l+1)
    else:
        for k in range(r-1, -1, -1):
            for l in range(c-1, -1, -1):
                if book[k][l] == cc:
                    return (k+1, l+1)

    return (-1, -1)

def ssearch(ss, cond):
    s = ""
    for j in ss:
        res = search(j, cond)
        if res[0] == -1:
            return "-1"
        else:
            s += str(res[0]) + "," + str(res[1]) + ','
    return s 



for i in arr:
    res = ssearch(i, position == 'S')
    if res == "-1":
        print(0)
    elif res:
        print(res[:-1])
    else:
        print(0)
    exit()
    
