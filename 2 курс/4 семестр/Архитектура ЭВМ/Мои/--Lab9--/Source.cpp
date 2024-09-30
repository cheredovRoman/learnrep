#include <iostream>
#include <omp.h>
#include <ctime>
#include <deque>
using namespace std;

class matrix {
	deque<int> ar;
	int row;
	int column;
public:
	// Конструктор. Принимает параметры row - количество строк и column - кол-во столбцов
	matrix(int row, int column) {
		this->row = row;
		this->column = column;
	}
	// Функция заполнения матрицы
	void input() {
		for (int i = 0; i < row * column; ++i) {
			ar.emplace_back(i+1);
		}
	}
	// Функция транспонирования матрицы
	void Trans() {
	
		deque<int> temp;	// Массив который мы заполняем в виде транспонированной матрицы
		int tempNum = 0;	// переменная для обмена числа столбцов и колонок местами
		for (int i = 0; i < column; ++i) {
			temp.emplace_back(ar[i]);					// Добавляем i элемент в массив
			for (int j = 1; j < row; ++j) {		
				temp.emplace_back(ar[j * column + i]);	// Добовляем следующий элемент колонки
			}
		}
		ar = temp;
		tempNum = row;
		row = column;
		column = tempNum;
	}
	// Вывод матрицы в консоль
	void print() {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				cout << ar[i * column + j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
	// Для тестов меняй эти жве переменные
	const int numRow = 5;		// Количество строк в матрице
	const int numColumn = 5;	// Количество столбцов в матрице

	double t1, t2, dt;			// Переменные для хранения времени выполнения
	matrix A(numRow, numColumn);// Матрица A для работы без openMP
	matrix B(numRow, numColumn);// Матрица B для работы c openMP
	cout << endl;
	t1 = omp_get_wtime();		// Запуск таймера
	A.input();					// Заполнение матрицы
	A.print();					// Вывод матрицы в консоль
	A.Trans();					// Транспонирование матрицы
	A.print();					// Вывод матрицы в консоль
	t2 = omp_get_wtime();		// Конец таймера
	dt = t2 - t1;				// Расчитываем время работы области программы
	cout << "Work time = " << dt << endl << endl;

	t1 = omp_get_wtime();		// Запуск таймера
	#pragma omp parallel					// Выполнения программы с использованием многопоточности
	{
		B.input();				// Заполнение матрицы
		B.print();				// Вывод матрицы в консоль
		B.Trans();				// Транспонирование матрицы
		B.print();				// Вывод матрицы в консоль
	}
	t2 = omp_get_wtime();		// Конец таймера
	dt = t2 - t1;				// Расчитываем время работы области программы
	cout << "Work time = " << dt << endl << endl;
}