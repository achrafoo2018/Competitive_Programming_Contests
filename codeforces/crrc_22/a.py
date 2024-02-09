def to_base10(num, base):
    result = 0
    for digit in num:
        result = result * base + me
    return result

def is_valid_addition(a, b, c, base):
    a_base10 = to_base10(a, base)
    b_base10 = to_base10(b, base)
    c_base10 = to_base10(c, base)
    return a_base10 + b_base10 == c_base10

def find_base(a, b, c):
    cnt = 0
    ans = 0
    for base in range(2, 37):
        if is_valid_addition(a, b, c, base):
            ans = base
            cnt += 1
    if cnt > 1: 
        return 0
    return ans

a = input()
b = input()
c = input()

print(find_base(a, b, c))
