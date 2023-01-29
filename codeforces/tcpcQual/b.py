# Given a string of digits, 
# insert commas to create a sequence of strictly increasing numbers so as to minimize the magnitude of the last number.
# For this problem, leading zeros are allowed in front of a number.
# For example, given the string 123456789, the output should be 1,2,3,4,5,6,7,8,9.
# Given the string 3526, the output should be 3,5,26.

# For each instance, output the comma separated strictly increasing sequence,
# with no spaces between commas or numbers. If there are several such sequences, pick the one which has the largest first value; if there's a tie, the largest second number, etc.

# Input
# Input will consist of multiple test cases. Each case will consist of one line, containing a string of digits of maximum length 80. A line consisting of a single 0 terminates input.

# Output
# For each instance, output the comma separated strictly increasing sequence, with no spaces between commas or numbers. If there are several such sequences, pick the one which has the largest first value; if there's a tie, the largest second number, etc.

# Sample Input
# 3456
# 3546
# 3526
# 0001
# 100000101
# 0

# Sample Output
# 3,4,5,6
# 35,46
# 3,5,26
# 0001
# 100,000101

# Solution

def main():
    while True:
        s = input()
        if s == '0':
            break
        print(','.join(solve(s)))

def solve(s):
    if len(s) == 1:
        return [s]
    if len(s) == 2:
        return [s] if int(s) > int(s[0]) else [s[0], s[1]]
    if int(s[:2]) > int(s[0]):
        return [s[:2]] + solve(s[2:])
    return [s[0]] + solve(s[1:])

if __name__ == '__main__':
    main()



