import numpy as np

# Функции, определяющие систему
def f(x):
    return np.array([x[0] ** 2 + x[1] ** 2 / 4 - 1, (x[0] - a) ** 2 + (x[1] - b) ** 2 - R ** 2])


# Матрица Якоби
def jacobian(x):
    return np.array([[2 * x[0], x[1] / 2], [2 * (x[0] - a), 2 * (x[1] - b)]])


# Метод Ньютона
def newton_method(f, jacobian, x0, eps):
    k = 0
    xn = x0
    fn = f(xn)
    jn = jacobian(xn)
    delta = np.linalg.solve(jn, -fn)

    while np.linalg.norm(delta) > eps:
        xn = xn + delta
        fn = f(xn)
        jn = jacobian(xn)
        delta = np.linalg.solve(jn, -fn)
        k += 1
    print("k = ", str(k))
    return xn


# Точность вычислений и начальное приближение, а также необходимые переменные
x0 = np.array([float(input("Введите начальное приближение для x0: ")),
               float(input("Введите начальное приближение для x1: "))])
a = float(input("Введите a: "))
b = float(input("Введите b: "))
R = float(input("Введите r: "))
eps = float(input("Введите точность вычислений: "))

# Вычисление решения системы
x = newton_method(f, jacobian, x0, eps)
print("Решение системы нелинейных алгебраических уравнений методом Ньютона: ", np.around(x, 5))
