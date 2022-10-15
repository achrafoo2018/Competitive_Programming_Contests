n = int(input())
arr = [i for i in range(1, n+1)]
while(len(arr) > 2):
    n = len(arr)
    mid = n // 2 + (n % 2)
    question = "? " + str(mid) + " "
    for j in range(mid):
        question += str(arr[j]) + " ";
    nb_yes = 0
    nb_no = 0
    for q in range(8):
        print(question)
        ans = input()
        nb_yes += ans == "YES"
        nb_no += ans == "NO"
    if nb_yes >= nb_no:
        arr = arr[:mid]
    else:
        arr = arr[mid:]
print(f"! {arr[0]}")
ans = input()
if(ans == ":("):
    print(f"! {arr[1]}")
    ans = input()
