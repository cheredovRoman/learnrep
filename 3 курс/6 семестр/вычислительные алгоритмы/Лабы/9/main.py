import numpy as np
import matplotlib.pyplot as plt
# Метод Рунге-Кутты
def rk4_meth(x, y, h1):
    k1 = h1 * eval(f, {"x": x}, {"y": y})
    k2 = h1 * eval(f, {"x": x + h1 / 2}, {"y": y + k1 / 2})
    k3 = h1 * eval(f, {"x": x + h1 / 2}, {"y": y + k2 / 2})
    k4 = h1 * eval(f, {"x": x + h1}, {"y": y + k3})
    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6


f = input("Введите дифференциальное уравнение:")
a = float(input("Введите a: "))
b = float(input("Введите b: "))
h = float(input("Введите h: "))
y = float(input("Введите y0: "))
e = float(input("Введите e: "))

print("Режим работы с постоянным шагом:")
xArr = []
res = []
xArr.append(a)
res.append(y)
i = 0
n = np.ceil((b - a) / h)
a0 = a
while i < n:
    print("\ni = " + str(i + 1))
    res.append(rk4_meth(a0, res[i], h))
    a0 += h
    xArr.append(a0)
    print("x" + str(i + 1) + " = " + str(np.around(a0, 1)) + "; y" + str(i + 1) + " = " + str(res[i + 1]))
    i += 1

print("\nРежим с автошагом:")

while True:
    y1 = []
    y1.append(y)
    y2 = []
    y2.append(y)
    i = 0
    a0 = a
    while a0 < b:
        y1.append(rk4_meth(a0, y1[i], h))
        a0 += h
        i += 1
    i = 0
    a0 = a
    while a0 < b:
        y2.append(rk4_meth(a0, y2[i], h / 2))
        a0 += h / 2
        i += 1
    print("y1 = " + str(y1[-1]) + "; y2 = " + str(y2[-1]))
    if (abs(y1[-1] - y2[-1]) / 15 < e):
        break
    else:
        h /= 2

print("Шаг = {0}, y = {1}".format(h / 2, y2[-1]))
# График
plt.plot(xArr, res)
plt.show()
