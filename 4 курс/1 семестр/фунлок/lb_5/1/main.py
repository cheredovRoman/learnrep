n = 6# порядок матрицы

matrix = [[i*n + j + 1 if i % 2 == 0 else (i+1)*n - j for j in range(n)] for i in range(n)]

if len(matrix) != len(matrix[0]):
    print("Матрица не является квадратной")
else:
    print("Матрица:")
    for row in matrix:
        print(row)

    if n % 2 == 0:
        result = [(lambda row: (row[len(row)//2] + row[len(row)//2-1])/2)(row) for row in matrix]
    else:
        result = [(lambda row: row[len(row)//2])(row) for row in matrix]
    output = list(map(lambda x: x, result))
    print("Результат:")
    print(output)