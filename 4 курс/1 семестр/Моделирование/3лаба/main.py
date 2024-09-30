import math
from prettytable import PrettyTable

limitations = [
    [-2, -6, 1, 0, 0],
    [-5, -4, 0, 1, 0],
    [-2, -3, 0, 0, 1]
]

n = len(limitations)
m = len(limitations[0])

F = [-12, -16, 0, 0, 0]

base = [3, 4, 5]

free_terms = [-24, -31, -18, 0]

table = PrettyTable()
field_names = ["Базис", "Свободный член"]
for i in range(m):
    field_names.append("x{}".format(i+1))
field_names.append("Оценочное отношение")
table.field_names = field_names

print("Исходная таблица:")
while max(F) > 0 or min(free_terms) < 0:
    inf = [False] * n

    minus_flag = False
    row = min((i for i, num in enumerate(free_terms[:-1]) if num < 0), default=None,key=lambda x: free_terms[x])
    col = -1
    ocen_otn = [0] * n
    if row != None:
        print("\nЕсть отрицательные свободные члены!")
        ocen_otn = [0] * m
        inf = [False] * m
        minus_flag = True
    else:
        col = max((i for i, num in enumerate(F) if num > 0), default=None, key=lambda x: F[x])
        #col = max((i for i, num in enumerate(F) if num > 0), default=None, key=lambda x: abs(F[x]))
    if not minus_flag:
        for i in range(n):
            if limitations[i][col] == 0 or (limitations[i][col] < 0 and free_terms[i] == 0) or (limitations[i][col] > 0 and free_terms[i] < 0) or (limitations[i][col] < 0 and free_terms[i] > 0):
                inf[i] = True
            elif free_terms[i] == 0 and limitations[i][col] > 0:
                ocen_otn[i] = 0
            else:
                ocen_otn[i] = free_terms[i] / limitations[i][col]
    else:
        for j in range(m):
            if limitations[row][j] == 0 or (limitations[row][j] < 0 and F[j] == 0) or (limitations[row][j] > 0 and F[j] < 0) or (limitations[row][j] < 0 and F[j] > 0):
                inf[j] = True
            elif F[j] == 0:
                ocen_otn[j] = 0
            else:
                ocen_otn[j] = F[j] / limitations[row][j]
# Вывод таблицы
for i in range(n):
    table_row = ["x{}".format(base[i]), free_terms[i]]
    for j in range(m):
        table_row.append(limitations[i][j])
    if minus_flag:
        table_row.append(" ")
    elif inf[i]:
        table_row.append("inf")
    else:
        table_row.append(ocen_otn[i])
    table.add_row(table_row)

table_row = ["F", free_terms[n]]
for i in range(m):
    table_row.append(F[i])
table_row.append(" ")
table.add_row(table_row)
if minus_flag:
    table_row = ["Оценочное отношение", ""]
    for i in range(m):
        if inf[i]:
            table_row.append("inf")
        else:
            table_row.append(ocen_otn[i])
    table_row.append("")
    table.add_row(table_row)
print(table)
table.clear_rows()
if not minus_flag:
    biais = [(i, num) for i, num in enumerate(ocen_otn) if (num > 0 or num < 0) and not inf[i]]
    if len(biais) == 0:
        print("Конечного минимума нет!")
        break
    min_biais = min(biais, key=lambda x: x[1])
    row = min_biais[0]
else:
    biais = [(i, num) for i, num in enumerate(ocen_otn) if (num > 0 or num < 0) and not inf[i]]
    if len(biais) == 0:
        print("Конечного минимума нет!")
        break
    min_biais = min(biais, key=lambda x: x[1])
    col = min_biais[0]

new_limitations = [[0] * m for _ in range(n)]
new_free_terms = [0] * (n+1)
new_F = [0] * m
base[row] = col + 1
new_free_terms[row] = free_terms[row] / limitations[row][col]
for i in range(m):
    if i+1 in base:
        new_F[i] = 0
    else:
        new_F[i] = F[i] - (F[col] * limitations[row][i]) / limitations[row][col]
        #print(F[i], F[col], limitations[row][j], limitations[row][col])
for i in range(n):
    for j in range(m):
        if base[i] == j+1:
            new_limitations[i][j] = 1
        elif j+1 in base:
            new_limitations[i][j] = 0
        elif i == row:
            new_limitations[i][j] = limitations[i][j] / limitations[row][col]
        else:
            new_limitations[i][j] = limitations[i][j] -(limitations[i][col] * limitations[row][j]) / limitations[row][col]
for i in range(n):
    if i == row: continue
    new_free_terms[i] = free_terms[i] - (limitations[i][col] * free_terms[row]) / limitations[row][col]
    new_free_terms[n] = free_terms[n] - (F[col] * free_terms[row]) / limitations[row][col]

limitations = new_limitations
F = new_F
free_terms = new_free_terms
# Вывод последней таблицы
print("\nРезультат:")
for i in range(n):
    table_row = ["x{}".format(base[i]), free_terms[i]]
    for j in range(m):
        table_row.append(limitations[i][j])
    table_row.append("")
    table.add_row(table_row)

table_row = ["F", free_terms[n]]
for i in range(m):
    table_row.append(F[i])
table_row.append(" ")
table.add_row(table_row)
print(table)