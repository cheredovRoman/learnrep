#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

// функция с алгоритмом двоичного поиска

static int Binary_Search(const double* array, double key, int size_array)

{
	int l = 0; // нижняя граница
	int u = size_array - 1; // верхняя граница
	while (l <= u) {
		int m = (l + u) / 2;
		if (abs(array[m] - key) <= 1e-6) return m;
		if (array[m] < key) l = m + 1;
		if (array[m] > key) u = m - 1;
	}
	return -1;
}

void hoarasort(double* a, int first, int last)

{
	int i = first, j = last;
	double tmp,
		x = a[(first + last) / 2]; //Выбор опорного элемента из массива
	do { //Этап разделения
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) //перестановка элементов
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} 
	while (i <= j);
	//Каждый раз при повторении преобразования очередная часть массива разбивается на два меньших и т.д., пока не получится массив из двух элементов.
	if (i < last)
		hoarasort(a, i, last);
	if (first < j)
		hoarasort(a, first, j);
}
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Введите размер массива: ";
	int size_array; // длина массива
	cin >> size_array;
	double* array = new double[size_array]; // одномерный динамический массив
	for (int i = 0; i < size_array; i++)
	{
		printf_s("Введите array[%d]: ", i);
		cin >> array[i];
	}
	cout << "Массив\n";
	for (int i = 0; i < size_array; i++)
	{
		cout << array[i] << " "; // вывод массива на экран
	}
	cout << "\n";
	cout << "Отсортированный массив\n";
	hoarasort(array, 0, size_array - 1); // вызов функции быстрой сортировки
	for (int i = 0; i < size_array; i++)

	{
		cout << array[i] << " "; // печать отсортированного массива
	}
	cout << "\n";
	cout << "Введите число, которое нужно найти: ";
	double key = 0;
	cin >> key;
	int index = 0;
	index = Binary_Search(array, key, size_array);
	cout << "\n";
	if (index >= 0)
	cout << "Указанное число находится в ячейке с индексом: " << index << "\n\n";
	else
	cout << "В массиве нет такого числа!\n\n";
	delete[] array; // высвобождаем память