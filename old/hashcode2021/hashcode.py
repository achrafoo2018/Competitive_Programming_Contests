import sys

def fun1():
    pass


def fun2():
    pass


def fun3():
    pass


def fun4():
    pass

import random 
def scheduler(inp):
    schedules = []
    for intersection in range(len(inp)):
        for street in range(len(inp[intersection][0])):
            try:
                schedules[intersection].append([inp[intersection][0][street], "1"])
            except:
                schedules.append([[inp[intersection][0][street], '1']])
    return schedules

# [ [S1, S2, ...], [S1, S3, ...], [S3, S2, ...] ]
if len(sys.argv) == 3:
    with open(sys.argv[1], 'r') as inputFile: # reading input file
        simulationDuration, intersections, streets, cars, scorePerCar = list(map(lambda y: int(y), inputFile.readline().split(" ")[:5]))
        streetsDescription = []
        pathsOfCars = []
        for _ in range(streets):
            streetsDescription.append(inputFile.readline().replace("\n", '').split(" "))
        
        for _ in range(cars):
            pathsOfCars.append(inputFile.readline().replace("\n", '').split(" "))
        # print(*streetsDescription, sep="\n")
        # print("==================")
        # print(*pathsOfCars, sep="\n")
        intersectionList = [[[], []] for i in range(intersections)]
        for street in streetsDescription:
            intersectionList[int(street[0])][1].append(street[2])
            intersectionList[int(street[1])][0].append(street[2])
        # print("==================")
        # print(*intersectionList, sep="\n")
        newPathOfCars = [[] for _ in range(len(pathsOfCars))]
        # for car in range(len(pathsOfCars)):
        #     for street in range(1, len(pathsOfCars[car])):
        #         for intersection in range(len(intersectionList)):
        #             if pathsOfCars[car][street] in intersectionList[intersection][0]:
        #                 newPathOfCars[car].append(intersection)
        #                 break
        schedules = scheduler(intersectionList)
        # print(schedules)
                   
        resultFile = open(sys.argv[2], 'a+') # output file
        resultFile.write(str(len(schedules))+ '\n')
        for i in range(len(schedules)):
            resultFile.write(str(i)+"\n")
            resultFile.write(str(len(schedules[i]))+"\n")
            for j in range(len(schedules[i])):
                resultFile.write(" ".join(schedules[i][j])+"\n")
        # generate output here

        resultFile.close()

else:
    print('Usage : '+ sys.argv[0] + ' input_file output_file')
