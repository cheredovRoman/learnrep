from prettytable import PrettyTable
# Метод северо-западного угла
def north_west(A, B):
    n = len(A)
    m = len(B)
    result = [[None] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if A[i] == 0:
                break
            elif B[j] == 0:
                continue
            elif A[i] == B[j] and j != m-1:
                if i == n-1:
                    result[i][j+1] = 0
                else:
                    result[i+1][j] = 0
            min_AB = min(A[i], B[j])
            result[i][j] = min_AB
            A[i] -= min_AB
            B[j] -= min_AB
    return result
# Метод наименьшей стоимости
def min_price(A, B, tariff):
    n = len(A)
    m = len(B)
    tariff_copy = [[True] * m for _ in range(n)]
    result = [[None] * m for _ in range(n)]
    while max(A) > 0 or max(B) > 0:
        min_el = (9999999, 0, 0)
        for i in range(n):
            for j in range(m):
                if tariff_copy[i][j]:
                    if tariff[i][j] < min_el[0] and A[i] != 0 and B[j] != 0:
                        min_el = (tariff[i][j], i, j)
        i, j = min_el[1], min_el[2]
        tariff_copy[i][j] = False
        min_AB = min(A[i], B[j])
        result[i][j] = min_AB
        A[i] -= min_AB
        B[j] -= min_AB
    return result
# Метод потенциалов (поиск отрицательных потенциалов)
def potential_method(base_matrix, A, B, tariff_matrix):
    n = len(A)
    m = len(B)
    count = 0
    for i in range(n):
        for j in range(m):
            if base_matrix[i][j] != None:
                count+=1
    if count != n+m-1:
        return False
    ocenki = []
    V = [None] * m
    U = [None] * n
    U[0] = 0
    while None in V or None in U:
        for i in range(n):
            for j in range(m):
                if (U[i] == None and V[j] == None) or (U[i] != None and V[j] != None):
                    continue
                elif U[i] != None and base_matrix[i][j] != None:
                    V[j] = tariff_matrix[i][j] - U[i]
                elif base_matrix[i][j] != None and V[j] != None:
                    U[i] = tariff_matrix[i][j] - V[j]
    for i in range(n):
        for j in range(m):
            if base_matrix[i][j] == None:
                ocenki.append((i, j, tariff_matrix[i][j] - (U[i] + V[j])))
    table = PrettyTable()
    field_names = ["Карьер \\ Дорога"]
    for i in range(m):
        field_names.append("B{}".format(i+1))
    field_names.append("U")
    table.field_names = field_names
    for i in range(n):
        table_row = []
        table_row.append("A{}".format(i+1))
        for j in range(m):
            if base_matrix[i][j] != None:
                table_row.append(str(base_matrix[i][j]) + ' / ' + str(tariff_matrix[i][j]))
            else:
                table_row.append(' ' + ' / ' + str(tariff_matrix[i][j]))
        table_row.append(U[i])
        table.add_row(table_row)
    table_row = []
    table_row.append("V")
    for i in range(m):
        table_row.append(V[i])
    table_row.append('')
    table.add_row(table_row)
    print("\nМетод потенциалов:")
    print(table)
    return [value for value in ocenki if value[2] < 0]
# Конвертация матрицы в граф
def matrix_to_graph(matrix, start):
    graph = {}
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if matrix[i][j] is not None:
                neighbors = []
 # Добавляем всех соседей в пределах матрицы
                for x in range(len(matrix)):
                    if matrix[x][j] != None and (x, j) != (i, j):
                        neighbors.append((x, j))
                for y in range(len(matrix[i])):
                    if matrix[i][y] is not None and (i, y) != (i, j):
                        neighbors.append((i, y))
                graph[(i, j)] = neighbors
    neighbors = []
    i, j = start[0], start[1]
 # Добавляем всех соседей в пределах матрицы
    for x in range(len(matrix)):
        if matrix[x][j] != None and (x, j) != (i, j):
            neighbors.append((x, j))
    for y in range(len(matrix[i])):
        if matrix[i][y] is not None and (i, y) != (i, j):
            neighbors.append((i, y))
    graph[(i, j)] = neighbors
    return graph, neighbors
# Поиск пути в графе
def find_path(graph, start, target):
    stack = [(start, [start])]
    visited = set()
    while stack:
        (vertex, path) = stack.pop()
        if vertex not in visited:
            for neighbor in graph[vertex]:
                if neighbor == target and len(path) < 3:
                    continue
                if (len(path) > 1 and ((vertex[0] == neighbor[0] and neighbor[0] ==path[len(path)-2][0]) or (vertex[1] == neighbor[1] and neighbor[1] == path[len(path)-2][1]))):
                    continue
                if neighbor == target:
                    return path + [neighbor]
                else:
                    stack.append((neighbor, path + [neighbor]))
            visited.add(vertex)
    return None
# Главный цикл (Поиск подходящего пути)
def main_cycle(base_matrix, start):
    n = len(base_matrix)
    m = len(base_matrix[0])
    start = start[:-1]
    graph, targets = matrix_to_graph(base_matrix, start)
    paths = []
    for target in targets:
        path = find_path(graph, start, target)
        if path:
            paths.append(path)
    for path in paths:
        even = [path[i] for i in range(1, len(path), 2)]
        min_idx = min(even, key=lambda x: base_matrix[x[0]][x[1]])
        min_even = base_matrix[min_idx[0]][min_idx[1]]
        if min_even == 0:
            continue
        one_None = True
        base_matrix[start[0]][start[1]] = min_even
        for i in range(1, len(path)):
            if i % 2 != 0:
                base_matrix[path[i][0]][path[i][1]] -= min_even
                if base_matrix[path[i][0]][path[i][1]] == 0 and one_None:
                    one_None = False
                    base_matrix[path[i][0]][path[i][1]] = None
            else:
                base_matrix[path[i][0]][path[i][1]] += min_even
        return base_matrix, path
    return False
A = [50, 55, 60, 20]
B = [30, 60, 40, 20, 15, 20]
A_copy = A.copy()
B_copy = B.copy()
tariff_matrix = [
[3, 7, 3, 4, 0, 0],
[6, 2, 5, 7, 4, 0],
[8, 5, 8, 3, 4, 0],
[1, 3, 6, 5, 3, 0]
]
base = min_price(A_copy, B_copy, tariff_matrix)
#base = north_west(A_copy, B_copy)
table = PrettyTable()
field_names = ["Карьер \\ Дорога"]
for i in range(len(B)):
    field_names.append("B{}".format(i+1))
field_names.append("Запас")
table.field_names = field_names
for i in range(len(A)):
    table_row = []
    table_row.append("A{}".format(i+1))
    for j in range(len(B)):
        if base[i][j] != None:
            table_row.append(str(base[i][j]) + ' / ' + str(tariff_matrix[i][j]))
        else:
            table_row.append(' ' + ' / ' + str(tariff_matrix[i][j]))
    table_row.append(A[i])
    table.add_row(table_row)
table_row = []
table_row.append("Потребность")
for i in range(len(B)):
    table_row.append(B[i])
table_row.append('')
table.add_row(table_row)
print("Начальное решение:")
print(table)
result = 0
for i in range(len(A)):
    for j in range(len(B)):
        if base[i][j] != None:
            result += base[i][j] * tariff_matrix[i][j]
print("S = " + str(result))
while True:
    ocenki = potential_method(base, A, B, tariff_matrix)
    print()
    if ocenki:
        print("Есть отрицательные оценки.")
        for value in ocenki:
            print("A{}B{} = {}".format(value[0]+1, value[1]+1, value[2]))
        print("\nПереходим к поиску пути.")
    else:
        print("Отрицательных оценок нет.\nКонец.")
        break
    start = min(ocenki, key=lambda x: x[2])
    test = main_cycle(base, start)
    while not test:
        index = ocenki.index(start)
        ocenki.pop(index)
        if len(ocenki) == 0:
            break
        else:
            start = min(ocenki, key=lambda x: x[2])
            test = main_cycle(base, start)
    if not test:
        print("Невозможно найти путь!")
        break
    base = test[0]
    print("Путь найден:")
    for value in test[1]:
        print("A{}B{} -> ".format(value[0]+1, value[1]+1), end="")
    print("A{}B{}\n".format(test[1][0][0]+1, test[1][0][1]+1))
    print("Новое решение:")
    table.clear_rows()
    for i in range(len(A)):
        table_row = []
        table_row.append("A{}".format(i+1))
        for j in range(len(B)):
            if base[i][j] != None:
                table_row.append(str(base[i][j]) + ' / ' + str(tariff_matrix[i][j]))
            else:
                table_row.append(' ' + ' / ' + str(tariff_matrix[i][j]))
        table_row.append(A[i])
        table.add_row(table_row)
    table_row = []
    table_row.append("Потребность")
    for i in range(len(B)):
        table_row.append(B[i])
    table_row.append('')
    table.add_row(table_row)
    print(table)
result = 0
for i in range(len(A)):
    for j in range(len(B)):
        if base[i][j] != None:
            result += base[i][j] * tariff_matrix[i][j]
print()
print("Smin = " + str(result))