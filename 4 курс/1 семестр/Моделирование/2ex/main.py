import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import matplotlib.patches as patches
import random

# Массив с маршрутами двух деталей
name = [['A', 'B', 'C', 'D'],
        ['A', 'C', 'B', 'D']]

# Время обработки на каждом станке по заданном маршруту
value = [[5, 3, 4, 5],
         [3, 5, 2, 4]]

allX = []  # Массив всех маршрутов по оси X
allY = []  # Массив всех маршрутов по оси Y
Lenght = []  # Массив всех длин получившихся маршрутов

X = []  # Массив текущего маршрута по оси X
Y = []  # Массив текущего маршрута по оси Y
N = sum(value[0])  # Количество точек на оси X
M = sum(value[1])  # Количество точек на оси Y

# Массивы с суммарным временем для каждого станка
summaX = [0 for _ in range(len(value[0]) + 1)]
summaY = [0 for _ in range(len(value[0]) + 1)]
for i in range(1, len(value[0]) + 1):
    summaX[i] = summaX[i - 1] + value[0][i - 1]
    summaY[i] = summaY[i - 1] + value[1][i - 1]

# Аналог всех точек графика, по этому массиму происходит рекурсия и строются маршруты
Graph = [[0 for _ in range(M + 1)] for i in range(N + 1)]


# Добавление зон исключений в массив по которому ищутся маршруты
def AddExceptions():
    # Значение:
    # 0 - пустая клетка
    # 1 - запретная клетка
    # 2 - граница перед запретной клеткой (на неё можно наступать)
    x = 0
    for i in range(len(name[0])):
        y = 0
        for j in range(len(name[0])):
            if name[0][i] == name[1][j]:
                for i2 in range(x, summaX[i + 1] + 1):
                    for j2 in range(y, summaY[j + 1] + 1):
                        if i2 == x or i2 == summaX[i + 1] or j2 == y or j2 == summaY[j + 1]:
                            Graph[i2][j2] = 2
                        else:
                            Graph[i2][j2] = 1
                break
            y += value[1][j]
        x += value[0][i]

    # Рекурсивный поиск маршрутов


def FindRoute(x, y):
    X.append(x)  # Добавляем точки x в текущий маршрут
    Y.append(y)  # Добавляем точки y в текущий маршрут
    if x == N and y == M:  # Если дошли до конца
        Lenght.append(len(X) - 1)
        allX.append(X[:])
        allY.append(Y[:])
        X.pop()  # Убираем текущую точку x из маршрута
        Y.pop()  # Убираем текущую точку y из маршрута
        return

    if x == N:  # Если первая деталь закончила обработку
        FindRoute(x, y + 1)

    elif y == M:  # Если вторая деталь закончила обработку
        FindRoute(x + 1, y)

    else:
        if Graph[x + 1][y + 1] != 1 and (
                Graph[x][y] != 2 or Graph[x + 1][y + 1] != 2 or Graph[x][y + 1] == 0 or Graph[x + 1][y] == 0):
            FindRoute(x + 1, y + 1)

        if Graph[x + 1][y] != 1 and (Graph[x][y] == 2 or Graph[x][y] == -1 or (x == 0 and y == 0)):
            if Graph[x + 1][y] != 0 and (Graph[x + 1][y] != 2 or Graph[x + 1][y + 1] != 2) or Graph[x][y - 1] != 2 or \
                    Graph[x][y + 1] != 2:
                # Если следующая точка 0, чтобы дальше идти вправо добавляем дополнительно точку -1 вместо 0
                if Graph[x + 1][y] == 0:
                    Graph[x + 1][y] = -1

                FindRoute(x + 1, y)

                # После поиска маршрута возвращаем обратно 0 вместо -1
                if Graph[x + 1][y] == -1:
                    Graph[x + 1][y] = 0

        if Graph[x][y + 1] != 1 and (Graph[x][y] == 2 or Graph[x][y] == -2 or (x == 0 and y == 0)):
            if Graph[x][y + 1] != 0 and (Graph[x][y + 1] != 2 or Graph[x + 1][y + 1] != 2) or Graph[x - 1][y] != 2 or \
                    Graph[x + 1][y] != 2:
                # Если следующая точка 0, чтобы дальше идти вверх добавляем дополнительно точку -2 вместо 0
                if Graph[x][y + 1] == 0:
                    Graph[x][y + 1] = -2

                FindRoute(x, y + 1)

                # После поиска маршрута возвращаем обратно 0 вместо -2
                if Graph[x][y + 1] == -2:
                    Graph[x][y + 1] = 0

    X.pop()  # Убираем текущую точку x из маршрута
    Y.pop()  # Убираем текущую точку y из маршрута


# Построение графика
def DrawGraph(X, Y):
    n = len(name[0])  # Количество станков

    fig, ax = plt.subplots()
    # Ограничение значений x от 0 до времени обработки всех деталей
    ax.set_xlim(-0.1, N + 0.1)
    # Ограничение значений y
    ax.set_ylim(-0.1, M + 0.1)
    # На оси X и Yглавные линии будут каждое 1 значение
    ax.xaxis.set_major_locator(ticker.MultipleLocator(1))
    ax.yaxis.set_major_locator(ticker.MultipleLocator(1))
    # Стиль сетки
    ax.grid(linestyle=':')

    # Подписи цифр у границ каждого станка
    labelX = ['' for _ in range(sum(value[0]) + 2)]
    labelY = ['' for _ in range(sum(value[1]) + 2)]
    for i in range(n + 1):
        labelX[summaX[i] + 1] = str(summaX[i])
        labelY[summaY[i] + 1] = str(summaY[i])

    # Добавление на оси сформированные подписи
    ax.set_xticklabels(labelX)
    ax.set_yticklabels(labelY)

    x = 0
    for i in range(n):
        y = 0
        for j in range(n):
            if name[0][i] == name[1][j]:
                # Добавление запретных зон
                ax.add_patch(patches.Rectangle((x, y), value[0][i], value[1][j], edgecolor='black', facecolor='grey'))
                # Добавление подписи станка
                plt.text(x + value[0][i] / 2 - 0.2, -1.5, name[0][i] + '1')
                plt.text(-1.5, y + value[1][j] / 2, name[1][j] + '2')
                break
            y += value[1][j]
        x += value[0][i]

        # Добавление текущего маршрута
    ax.plot(X, Y, color='r', linewidth=3)
    plt.show()


# Получение пути в виде очередности обработки на станках
def ConvertRoute(X, Y):
    route = ""
    number1 = 0  # Номер станка у первой детали
    number2 = 0  # Номер станка у второй детали

    n = len(X)  # Длина маршрута
    # На каждой точке маршрута получаем буквенную запись этой точки
    for i in range(1, n):
        if X[i] > X[i - 1] and Y[i] > Y[i - 1]:
            current = ' ' + name[0][number1] + '1' + name[1][number2] + '2 '
        elif X[i] > X[i - 1]:
            current = ' ' + name[0][number1] + '1 '
        elif Y[i] > Y[i - 1]:
            current = ' ' + name[1][number2] + '2 '

        # Если такой буквенной записи еще нет в маршруте, то добавляем её
        if current not in route:
            route += current + '-'

        if X[i] == summaX[number1 + 1] and summaX[number1 + 1] < X[n - 1]:
            number1 += 1

        if Y[i] == summaY[number2 + 1] and summaY[number2 + 1] < Y[n - 1]:
            number2 += 1

    route = route[:-2]  # Убираем в конце пробел и штрих
    route = route[1:]  # Убираем в начале пробел
    return route


# Вывод на экран маршрута
def OutputRoute(X, Y, i):
    print("№" + str(i).ljust(4) + " Маршрут: " + ConvertRoute(X, Y).ljust(52) + " Время обработки: " + str(len(X) - 1))
    DrawGraph(X, Y)


# Вывод таблицы на экран
def OutputTable(value):
    n = len(value[0])  # Количество станков
    for i in range(2):
        print("№".ljust(5), end="")
        for j in range(n):
            print("Станок " + name[i][j].ljust(5), end="")

        print("\n" + str(i + 1).ljust(9), end="")
        for j in range(n):
            print(str(value[i][j]).ljust(12), end="")
        print("\n")


def main():
    print("Исходная таблица:")
    OutputTable(value)

    AddExceptions()  # Добавление зон исключений
    FindRoute(0, 0)  # Поиск маршрутов

    m = min(Lenght)  # Минимальная длина из всех маршрутов
    closeX = []  # Массив со значениями X для близких решений
    closeY = []  # Массив со значениями Y для близких решений
    k = 1
    print("Оптимальные решения:")
    for i in range(len(allX)):
        if Lenght[i] == m:
            OutputRoute(allX[i], allY[i], k)
            k += 1
        # Заполнение массива близких к оптимальному решений
        elif Lenght[i] == m + 1:
            closeX.append(allX[i][:])
            closeY.append(allY[i][:])

    print("\nБлизкие к оптимальному решения:")
    for i in range(2):
        number = random.randint(0, len(closeX) - 1)  # Рандомно выбираются
        OutputRoute(closeX[number], closeY[number], i + 1)

    print("\nМаксимальное время обработки при работе станков лишь поочередно:", M + N)


if __name__ == '__main__':
    main()
