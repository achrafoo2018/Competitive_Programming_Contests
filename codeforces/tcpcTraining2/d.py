inp = open("dwarf.in", "r")
outp = open("dwarf.out", "w")

for line in inp.readlines():
    n, m = [int(i) for i in line.split(" ")]
    arr = [int(i) for i in input().split(" ")]
    crafts = []
    for i in range(m):
        crafts.append([int(i) for i in ])