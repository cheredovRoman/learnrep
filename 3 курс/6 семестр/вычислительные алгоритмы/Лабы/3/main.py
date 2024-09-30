import numpy as np
import matplotlib.pyplot as plt
from numpy import *
from os import system


def langrange interpolation(x, y, x_interp):
# Вычисляем интерполяционный многочлен Ларгранжа
# Аргументы:
# x -- массив узлов интерполяции
# y -- массив значений функций в узлах интерполяции
# x_interp -- точка, в которой требуется вычислить значение интерполяционного многочлена
# Возвращает:
# Значение интерполяционного многочлена в точке x_interp

# Вычисляем количество узлов интерполяции
    n = len(x)
# Инициализируем массив базисных многочленов Лагранжа
    lj = np.ones(n)
# Вычисляем базисные многочлены Лагранжа
    for i in range(n):
        for j in range(n):
            if i!=j:
                lj[i]*=(x_interp - x[j])/(x[i]-x[j])
# Вычисляем значение интерполяционного многочлена Лагранжа
    y_interp = np.sum(y * lj)
    return y_interp
def read_file_x(filename):
    #Функция для чтения массива значений аргумента из файла
    with open(filename,"r") as f:
        x=[float(line) for line in f]
    return np,array(x)
def read_file_xy(filename):
    #Функция для чтения значений x,y из файла
    x=[]
    y=[]
    with open(filename,"r") as f:
        for line in f:
            data = line.split()
            x.append(float(data[0]))
            y.append(float(data[1]))
    return np.array(x), np.array(y)

def plot_graphs(x, y, x_interp, y_interp, x_intersect, y_intersect):
#Функция для построения графиков и вычисления максимального отклонения
    #Строим график исходной функции
    plt.plot(x,y,label="Исходная функция")
    #Строим график интерполяционного многочлена
    plt.plot(x_interp,y_interp,label = "Интерполяционный многочлен")
    #Отмечаем точки пересечения
    plt.plot(x_intersect,y_intersect,"o",color="red",label = "Узлы")
    #Определяем максимальное отклонение
    max_err=max_err(y_interp,y)
    print("Максимальное отклонение:",max_err)
    #Добавляем легенду и выводим график на экран
    plt.legend()
    plt.show()
def max_error(y1, y2):
#Функция для вычисления максимального отклонения между двумя массивами.
    max_err = 0
    for i in range(len(y1)):
        err = abs(y1[i] - y2[i])
        if err > max_err:
            max_err = err
    return max_err
while (True):
    _ = system('cls')
    #Выбираем режим работы программы
    mode = input('Выберите режим работы программы (a/b): ')
    if mode == 'a':
        #Считываем данные из файла
        filename = input('Введите имя файла с массивом значений аргумента: ')
        x1 = read_file_x(filename)
        #Запрашиваем ввод функции f(x)
        func = input('Введите выражение: ')
        #Вычисляем значения функции
        y1 = []
        for x in x1:
            y1.append(eval(func))
        #Создаем массивы с множеством точек для построения графика функции y = f(x)
        x_forgraph = np.arange(x1[0], x1[-1], 0.001)
        y_forgraph = []
        for x in x_forgraph:
            y_forgraph.append(eval(func))
        #Строим интерполяционный многочлен
        x_interp = np.arange(x1[0], x1[-1], 0.001)
        y_interp = []
        for xi in x_interp:
            y_interp.append(lagrange_interpolation(x1, y1, xi))
        #Строим графики
        plot_graphs(x_forgraph, y_forgraph, x_interp, y_interp, x1, y1)
    elif mode == 'b':
        #Считываем данные из файла
        filename = input('Введите имя файла со значениями x, y: ')
        #Задаем таблицу точек
        x2, y2 = read_file_xy(filename)
        #Задаем точку, в которой нужно вычислить значение многочлена
        x0 = float(input('Введите значение точки: '))
        #Строим интерполяционный многочлен
        y0 = lagrange_interpolation(x2, y2, x0)
        print('Приближенное значение функции в точке x0 =', x0, ':', y0)
    else:
        print('Некорректный ввод.')



