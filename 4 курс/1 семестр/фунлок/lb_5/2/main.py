import random

# Генерация списка со случайными числами от -5 до 5
random_numbers = [random.randint(-5, 5) for _ in range(10)]

# Генерация списка с повторяющейся последовательностью
repeating_sequence = [2, 3, 4] * 10

# Определение функции для возведения элементов одного списка в степень другого
def exponentiation(base, power):
    return base ** power

# Применение функции к спискам с использованием map и lambda
result = list(map(lambda x, y: exponentiation(x, y), random_numbers, repeating_sequence))

print(result)