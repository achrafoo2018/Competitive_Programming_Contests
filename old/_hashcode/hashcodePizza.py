def uniqueIngredient(team):
    res = []
    for i in range(len(team)):
        for j in range(len(team[i])):
            res.append(team[i][j])
    return len(list(set(res)))


def calculScore(team):
    return uniqueIngredient(team) ** 2


def listSplitter(pizzaList, T2, T3, T4):
    # pizzaList = pizzaList[::-1]
    res = []
    for j in range(0, T4 * 4, 4):
        if(len(pizzaList) < j + 4):
            break
        res.append(pizzaList[j:j+4])

    for j in range(T4*4, T3*3+T4 * 4, 3):
        if(len(pizzaList) < j + 3):
            break
        res.append(pizzaList[j:j+3])
    
    for j in range(T4*4+T3*3, T4 * 4+T3*3+T2*2, 2):
        if(len(pizzaList) < j + 2):
            break
        res.append(pizzaList[j:j+2])
    return res

import pdb
def listSort(teamList):
    for team in range(len(teamList)):
        if team % 10 == 0:
            pdb.set_trace()
        for pizza in teamList[team]:
            mem = 0
            for nextTeam in range(team+1, len(teamList)):
                for nextPizza in teamList[nextTeam]:
                    initialScore = calculScore(teamList[team]) + calculScore(teamList[nextTeam])
                    x = list(filter(lambda y: y != pizza, teamList[team])) + [nextPizza]
                    y = list(filter(lambda y: y != nextPizza, teamList[nextTeam])) + [pizza]
                    secScore = calculScore(x) + calculScore(y)
                    if mem == 0 or initialScore < secScore  and  secScore < (calculScore(mem[0]) + calculScore(mem[1][0])):
                        mem = [x, [y, nextTeam]]
            if mem != 0:
                teamList[team] = mem[0]
                teamList[mem[1][1]] = mem[1][0]
    return teamList


with open("c_many_ingredients.in", "r") as inputFile:
    D, T2, T3, T4 = inputFile.readline().split(" ")[:4]
    T2, T3, T4 = int(T2), int(T3), int(T4)
    list_ = list(map(lambda line: line.replace("\n", "").split(" "), inputFile.readlines()))
    for i in range(len(list_)):
        list_[i][0] = i
    # list_ = sorted(list_, key=len)
    res = listSplitter(list_, T2, T3, T4)
    # print(res)
    res = listSort(res)
    NteamsDeliveredWithPizzaPerPersonneBaguette = len(res)
    resultFile = open('resFile.in', 'a+')
    resultFile.write(str(NteamsDeliveredWithPizzaPerPersonneBaguette) + "\n")
    for team in res:
        teamLength = len(team)
        listOfIndexes = []
        for pizza in team:
            listOfIndexes.append(str(pizza[0]))
        pizzaIndexes = " ".join(listOfIndexes)
        resultFile.write(f"{teamLength} {pizzaIndexes}\n")
    resultFile.close()        
    # print(*res, sep="\n")
    # print(calculScore(res))

