import numpy as np
import matplotlib.pyplot as plt
from numpy import *
from os import system

def langrange interpolation(x,y,x_interp):
    #Вычисляем интерполяционный многочлен Ларгранжа
    #Аргументы:
    #x -- массив узлов интерполяции
    #y -- массив значений функций в узлах интерполяции
    #x_interp -- точка, в которой требуется вычислить значение интерполяционного многочлена
    #Возвращает:
    #Значение интерполяционного многочлена в точке x_interp
