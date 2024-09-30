#include <iostream> 
#include "stdio.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
// Вывод матрицы в консоль
void print(int* arr, int row, int column) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << arr[i * column + j] << "\t";
		}
		cout << endl;
	}
}
int main() {
	const int row = 4;			// Кол-во строк матрицы
	const int column = 5;		// Кол-во столбцов матрицы
	int array_A[row][column];	// Исходная матрица
	int array_temp[row][column];// Матрица для копирования
	int row_fun = row, column_fun = column;	// Значения количества столбцов и колонок для циклов по типу for
	// Заполнение матрицы
	for (int i = 0; i < row_fun; ++i) {
		for (int j = 0; j < column_fun; ++j) {
			array_A[i][j] = i * column + j + 1;
		}
	}

	print(*array_A, row_fun, column_fun);	// Печать исходной матрицы
	cout << "Start matrix" << endl;
	// Очистка данных для корректной работы
	__asm {
		and ecx, 0FFFFh;
		mov eax, 0
		mov ebx, 0
	}
	// Транспонирование матрицы
	for (int i = 0; i < column; ++i) {
		for (int j = 0; j < row; ++j) {
			__asm {
				// Достаём нужные элементы из матрицы
				// В eax кладём отступ для нужного элемента матрицы
				mov eax, j
				mov ebx, column
				mul ebx
				mov ebx, 4
				mul ebx
				push eax
				mov eax,i
				mov ebx, 4
				mul ebx
				pop ebx
				add eax,ebx
				movd mm0, [array_A + eax]	// в mm0 кладём элемент
				
				// Сохраняем нужные элементы в матрицу
				// В eax кладём отступ на место куда будет сохранён нужный элемент матрицы
				mov eax, i
				mov ebx, row
				mul ebx
				mov ebx, j
				add eax,ebx
				mov ebx, 4
				mul ebx
				movd [array_temp + eax], mm0 // из mm0 сохраняем элемент во вторую матрицу
			}
		}
	}
	// Очистка данных для корректной работы программы
	__asm {
		and ecx, 0FFFFh;
		mov ebx, 16			// В регистр ebx кладём отступ для команд ммх
	}
	// Из временной матрицы копируем данные в основную матрицу
	for (int i = 0; i < column; ++i) {
		__asm {
			// Получаем индекс строки из которой достаются элементы
			mov eax, i
			mul ebx

			movups xmm0, [array_temp+eax]	// Кладём первые 4 элемента в xmm0
			movups [array_A+eax], xmm0		// Сохраняем эти 4 элемента в основную матрицу
		}
	}
	// Меняем количество столбцов и колонок местами
	row_fun = column;
	column_fun = row;
	
	cout << endl;
	print(*array_A, row_fun, column_fun);
	cout << "End matrix" << endl;
	system("pause");
}