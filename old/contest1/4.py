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
        if len(answers) > 1 and answers[-1][1] != answers[-2][1]:
            break
    grid = ["ma nedrouch"] * n
    imposter, crew = -1, -1
    if answers[-1][1] == '1':
        crew = answers[-1][0][2]
        imposter = answers[-2][0][0]
        grid[crew-1] = 'C' # Crew
        grid[imposter-1] = 'I' # Imposter
    else:
        imposter = answers[-1][0][2]
        crew = answers[-2][0][0]
        grid[crew-1] = 'C' # Crew
        grid[imposter-1] = 'I' # Imposter
    for i in range(n):
        if grid[i] == "ma nedrouch":
            question = [crew, imposter, (i+1)]
            print("? "+" ".join(map(str, question)))
            stdout.flush()
            ans = input()
            if ans == '1':
                grid[i] = 'C'
            else:
                grid[i] = 'I'
    print(f"! {grid.count('I')} ", end="")
    for i in range(n):
        if grid[i] == 'I':
            print(f"{i+1} ", end="")
    print()
    stdout.flush()



    
