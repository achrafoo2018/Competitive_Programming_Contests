# TODO: Complete the get_ruler function
def get_ruler(kingdom):
    ruler = 'nobody'
    if kingdom[-1] in "aeiuoAEUIO":
        ruler = "Alice"
    elif kingdom[-1] not in "Yy":
        ruler = "Bob"
    return ruler

def main():
    # Get the number of test cases
    T = int(input())
    for t in range(T):
        # Get the kingdom
        kingdom = input()
        print('Case #%d: %s is ruled by %s.' % (t + 1, kingdom, get_ruler(kingdom)))

if __name__ == '__main__':
    main()