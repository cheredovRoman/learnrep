#include "Header.h"

int main()
{
	setlocale(0, "Russian");

	int N;	//Размерность матрицы
	FILE* in;	//Файл с исходными данными
	FILE* out;	//Файл для вывода результата

	in = fopen("input.txt", "rt");//Файл чтения
	out = fopen("result.txt", "wt");//Файл записи

	fscanf_s(in, "%d", &N); //взяли N - размерность

	float* A = new float[N * N];//Матрица системы уравнений
	float* B = new float[N];//Столбец свободных членов
	float* ASave = new float[N * N];//Изначальная матрица системы уравнений
	float* BSave = new float[N];//Изначальный столбец свободных членов
	float* X = new float[N];//Столбец иксов
	float* InvA = new float[N * N];//Обратная матрица системы уравнений

	float* E = new float[N * N]; //Единичная матрица
	float* Nev = new float[N]; //Невязки
	int CountTrans = 0; //Кол-во перестановок строк
	float det; //Определитель

	CreateE(N, E); //Создаем единичную матрицу

	EntryMass(N, A, ASave, in); //Считываем массив системы из файла

	EntryB(N, B, BSave, in); //Считываем столбец свободных членов из файла

	//Выводим массив и стоблец свободных членов
	OutPutMass(N, A);
	OutPutB(N, B);

	//Прямой ход метода Гауса
	Frontmove(N, A, B, E, &CountTrans);

	//Вычисляем определитель матрицы
	det = CalcDet(N, A, CountTrans);

	if (det == 0) {
		cout << endl << "Матрица вырожденная" << endl;
		fprintf(out, "Матрица вырожденная");
	}
	else {
		ReverseMove(N, A, B, X); //Обратный ход метода Гауса
		OutPutX(N, X, out); //Выводим решение системы

		CaclNevyaz(N, ASave, BSave, X, Nev); //Подсчитываем невязки
		OutPutNevyaz(N, Nev, out);

		OutPutDet(det, out); //Выводим значение определителя

		//Сокращаем точность выводимых значений до 2 знаков после запятой
		cout << fixed;
		cout.precision(2);

		//Обратный ход Гауса с единичной матрицей для получения обратной матрицы
		ReverseMoveForE(N, A, E, InvA);

		//Вывод обратной матрицы
		OutPutRevA(N, InvA, out);
	}

	//Освобождаем память
	delete[] A;
	delete[] B;
	delete[] ASave;
	delete[] BSave;
	delete[] InvA;
	delete[] X;
	delete[] Nev;
	fclose(in);
	fclose(out);
}
