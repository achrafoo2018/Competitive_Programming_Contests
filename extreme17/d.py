    def smali_function(Input_A, Input_B, Input_C):
        v0 = Input_A
        v1 = Input_B
        v2 = Input_C
        v3 = 1
        v4 = 0
        v5 = -1
        v6 = 1
        v7 = -v1
        v8 = v0
        v9 = 2 * v0
        v10 = 0
        v11 = 0
        v12 = 1

        while v12 <= v2:
            v11 += v1
            v10 += v0
            v13 = v10
            v14 = 0
            v15 = 0
            while (2 * v13) > v1:
                v13 -= v1
                v14 += 1
                v15 += v1

            if v13 <= 0:
                v13 = -v13

            v17 = v13
            v18 = 1
            while v18 <= v6:
                v17 += v13
                v18 += 1
                v18 = 1

            while v18 <= v12:
                v17 -= v9
                v18 += 1

            if v17 < 0:
                v5 = v14
                v6 = v12
                v7 = v15
                v8 = v10
                v9 = v13

            v12 += 1

        return v6

    for _ in range(int(input())):
        a, b, c = [int(i) for i in input().split(" ")]
        print(smali_function(a, b, c))