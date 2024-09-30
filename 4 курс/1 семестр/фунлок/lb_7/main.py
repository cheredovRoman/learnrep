
skolko = lambda bilet: sum(int(digit) for digit in str(bilet // 1000)) == sum(int(digit) for digit in str(bilet % 1000))
print(sum(1 for bilet in range(1, 600000) if skolko(bilet)))
