# Произвольный список
letters = ['a', 'b', 'c']

# Числовой список
numbers = [1, 2, 3]

# Использование функции map и zip
mapped_list = list(map(lambda x, y: [x] * y, letters, numbers))

# Использование спискового включения (list comprehension)
list_comprehension = [[x] * y for x, y in zip(letters, numbers)]

print("Mapped list:", mapped_list)
print("List comprehension:", list_comprehension)