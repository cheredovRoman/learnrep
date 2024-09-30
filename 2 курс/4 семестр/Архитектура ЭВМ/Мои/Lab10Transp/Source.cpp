#include <iostream>
#include <mpi.h>
#include <ctime>
#include <deque>
using namespace std;

// Функция заполнения матрицы
void input(int *arr, int row,int column) {
	for (int i = 0; i < row * column; ++i) {
		arr[i] = i+1;
	}
	
}
// Функция транспонирования матрицы
void Trans(int* arr, int &row, int &column) {
	int temp[100][100];
	int a;
	// Копирование данных
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			temp[i][j] = arr[i* column + j];
		}
	}
	// Транспонирование
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			arr[i + j * row] = temp[i][j];
		}
	}
	// row и column меняются местами
	a = row;
	row = column;
	column = a;
}
// Вывод матрицы в консоль
void print(int* arr, int row, int column) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << arr[i * column + j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}


int main(int* argc, char** argv) {
	int numRow = 4;			// Количество строк в матрице
	int numColumn = 2;		// Количество столбцов в матрице
	const int size = 4;		// Необходимо чтобы size всегда был больше или равен чем numRow и numColumn. 
							// Ограничение size = 100 (если нужно больше меняй в функции Trans размер temp)

	double t1, t2, dt;		// Переменные для хранения времени выполнения
	int numtasks, rank;		

	int matrix[size][size];	// Матрица
	
	// Обязательные MPI компоненты
	MPI_Init(argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

	t1 = MPI_Wtime();	// Запуск таймера

	// Процесс 0
	// Заполняет матрицу значениями и отправляет её процессу 1 и 2
	if (rank == 0) {
		input(*matrix, numRow, numColumn);					// Заполнение матрицы
		MPI_Send(matrix, numRow * numColumn, MPI_INT, 1, 1, MPI_COMM_WORLD);	// Матрица отправляется 1 процессу
		MPI_Send(matrix, numRow * numColumn, MPI_INT, 2, 2, MPI_COMM_WORLD);	// Матрица отправляется 2 процессу
		t2 = MPI_Wtime();	// Конец таймера
		dt = t2 - t1;		// Расчитываем время работы области программы
		MPI_Send(&dt, 1, MPI_DOUBLE, 4, 6, MPI_COMM_WORLD);						// Время выполнения работы процесса отправляется 4 процессу
	}
	// Процесс 1
	// Печатает матрицу в консоль
	else if (rank == 1) {
		MPI_Recv(matrix, numRow * numColumn, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);	// Принимает заполненую матрицу от процесса 0
		print(*matrix, numRow, numColumn);												// Вывод матрицы в консоль
		t2 = MPI_Wtime();	// Конец таймера
		dt = t2 - t1;		// Расчитываем время работы области программы
		MPI_Send(&dt, 1, MPI_DOUBLE, 4, 7, MPI_COMM_WORLD);								// Время выполнения работы процесса отправляется 4 процессу		
	}
	// Процесс 2
	// Транспонирует матрицу и отправляет её процессу 3
	// Так же отправляет новые значение строк (row) и колонок (column) процессу 3
	else if (rank == 2) {
		MPI_Recv(matrix, numRow * numColumn, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);	// Принимает заполненую матрицу от процесса 0
		Trans(*matrix, numRow, numColumn);												// Транспонирование матрицы	
		MPI_Send(matrix, numRow * numColumn, MPI_INT, 3, 3, MPI_COMM_WORLD);			// Отправляет транспонированную матрицу процессу 3
		MPI_Send(&numRow, 1, MPI_INT, 3, 4, MPI_COMM_WORLD);							// Отправляет новое значение строк процессу 3
		MPI_Send(&numColumn, 1, MPI_INT, 3, 5, MPI_COMM_WORLD);							// Отправляет новое значение колонок процессу 3
		t2 = MPI_Wtime();	// Конец таймера
		dt = t2 - t1;		// Расчитываем время работы области программы
		MPI_Send(&dt, 1, MPI_DOUBLE, 4, 8, MPI_COMM_WORLD);								// Время выполнения работы процесса отправляется 4 процессу
	}
	// Процесс 3
	// Печатает матрицу в консоль
	else if (rank == 3) {
		MPI_Recv(&numRow, 1, MPI_INT, 2, 4, MPI_COMM_WORLD, &status);					// Принимает новое значение строк от процесса 2
		MPI_Recv(&numColumn, 1, MPI_INT, 2, 5, MPI_COMM_WORLD, &status);				// Принимает новое значение строк от процесса 2
		MPI_Recv(matrix, numRow * numColumn, MPI_INT, 2, 3, MPI_COMM_WORLD, &status);	// Принимает заполненую матрицу от процесса 2
		print(*matrix, numRow, numColumn);												// Вывод матрицы в консоль	
		t2 = MPI_Wtime();	// Конец таймера
		dt = t2 - t1;		// Расчитываем время работы области программы
		MPI_Send(&dt, 1, MPI_DOUBLE, 4, 9, MPI_COMM_WORLD);								// Время выполнения работы процесса отправляется 4 процессу
	}
	// Процесс 4
	// Печатает время работы каждого процесса и общее количество запущенных процессов
	if (rank == 4) {
		double time[4];
		MPI_Recv(&time[0], 1, MPI_DOUBLE, 0, 6, MPI_COMM_WORLD, &status);	// Принимает время работы процесса 0
		MPI_Recv(&time[1], 1, MPI_DOUBLE, 1, 7, MPI_COMM_WORLD, &status);	// Принимает время работы процесса 1
		MPI_Recv(&time[2], 1, MPI_DOUBLE, 2, 8, MPI_COMM_WORLD, &status);	// Принимает время работы процесса 2
		MPI_Recv(&time[3], 1, MPI_DOUBLE, 3, 9, MPI_COMM_WORLD, &status);	// Принимает время работы процесса 3
		// Печатает время каждого принятого процесса
		for (int i = 0; i < 4; ++i) {
			cout << "RunTime MPI Process " << i << " = " << time[i] << endl;
		}
		cout << "Total number of process: " << numtasks << endl << endl;
	}
	MPI_Finalize();	// Обязательные MPI компонент
}