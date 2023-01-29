import re
inverse = dict()
inverse[" "] = " "

inverse["\\"] = "/"
inverse["/"] = "\\"

inverse[">"] = "<"
inverse["<"] = ">"

inverse[")"] = "("
inverse["("] = ")"

command_inverse = dict()
command_inverse["left hand to head"] = "right hand to head"
command_inverse["right hand to head"] = "left hand to head"

command_inverse["left hand to hip"] = "right hand to hip"
command_inverse["right hand to hip"] = "left hand to hip"

command_inverse["left hand to start"] = "right hand to start"
command_inverse["right hand to start"] = "left hand to start"

command_inverse["left leg in"] = "right leg in"
command_inverse["right leg in"] = "left leg in"

command_inverse["left leg out"] = "right leg out"
command_inverse["right leg out"] = "left leg out"


for _ in range(int(input())):
    state = [
    [" ", "o", " "],
    ["/", "|", "\\"],
    ["/", " ",  "\\"]]
    d = int(input())
    commands = []
    nb_turns = 0
    for i in range(d):
        commands.append(input())
    for cmd in commands:
        if "say" in cmd:
            print(cmd[4:])
            continue
        if "turn" in cmd:
            nb_turns += 1
            for i in range(3):
                state[i][0], state[i][2] = inverse[state[i][2]], inverse[state[i][0]]
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
            continue
        if nb_turns % 2 == 1:
            cmd = command_inverse[cmd]
        if "left" in cmd and "head" in cmd:
            state[1][2] = " "
            state[0][2] = ")"
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "left" in cmd and "hip" in cmd:
            state[0][2] = " "
            state[1][2] = '>'
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "left" in cmd and "start" in cmd:
            state[1][2] = "\\"
            state[0][2] = " "
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "left" in cmd and "leg" in cmd and "in" in cmd:
            state[2][2] = '>'
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "left" in cmd and "leg" in cmd and "out" in cmd:
            state[2][2] = "\\"
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "right" in cmd and "head" in cmd:
            state[1][0] = " "
            state[0][0] = "("
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "right" in cmd and "hip" in cmd:
            state[0][0] = " "
            state[1][0] = '<'
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "right" in cmd and "start" in cmd:
            state[1][0] = "/"
            state[0][0] = " "
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "right" in cmd and "leg" in cmd and "in" in cmd:
            state[2][0] = '<'
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
        elif "right" in cmd and "leg" in cmd and "out" in cmd:
            state[2][0] = "/"
            for i in range(3):
                for j in range(3):
                    print(state[i][j], end="")
                print()
