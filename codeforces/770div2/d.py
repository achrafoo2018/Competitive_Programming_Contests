from sys import stdout
for _ in range(int(input())):
    n = int(input())
    arr = list(range(1, n+1))*2
    answers = []
    for i in range(n):
        question = [arr[i], arr[(i+1)], arr[(i+2)]]
        print("? "+" ".join(map(str, question)))
        stdout.flush()
        answers.append([question, input()])
    