s = input()
a = s.count('a')
print(len(s) if a > (len(s) // 2) else a*2-1)