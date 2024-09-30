#include "parametrs.h"

int main()
{
    setlocale(0, "Russian");
    int n;//Размерность матрицы

    FILE* input; // Файл с исходными данными
    FILE* output;// Файл для вывода результата

    input = fopen("input.txt", "rt");//Файл чтения
    output = fopen("result.txt", "wt");//Файл записи

    fscanf_s(input, "%d", &n); //Считали n - размерность
	
	float* A = new float[n * n];//Матрица системы уравнений
	float* B = new float[n];//Столбец свободных членов
	float* ASave = new float[n * n];//Изначальная матрица системы уравнений
	float* BSave = new float[n];//Изначальный столбец свободных членов
	float* X = new float[n];//Столбец иксов
	float* InvA = new float[n * n];//Обратная матрица системы уравнений
	float* E = new float[n * n]; //Единичная матрица
	float* Nev = new float[n]; //Невязки
	int CountTrans = 0; //Кол-во перестановок строк
	float det; //Определитель
	
	CreateE(n, E); //Создаем единичную матрицу
	EntryMassiv(n, A, ASave, input); //Считываем массив системы из файла
	EntryB(n, B, BSave, input); //Считываем столбец свободных членов из файла
	//Выводим массив и стоблец свободных членов
	OutPutMassiv(n, A);
	OutPutB(n, B);
	//Прямой ход метода Гауса
	FrontMove(n, A, B, E, &CountTrans);
	//Вычисляем определитель матрицы
	det = CalcDet(n, A, CountTrans);
	if (det == 0) {
		cout << endl << "Матрица вырожденная" << endl;
		fprintf(output, "Матрица вырожденная");
	}
	else {
		ReverseMove(n, A, B, X); //Обратный ход метода Гауса
		OutPutX(n, X, output); //Выводим решение системы

		CaclNevyaz(n, ASave, BSave, X, Nev); //Подсчитываем невязки
		OutPutNevyaz(n, Nev, output);

		OutPutDet(det, output); //Выводим значение определителя

		//Сокращаем точность выводимых значений до 2 знаков после запятой
		cout << fixed;
		cout.precision(2);

		//Обратный ход Гауса с единичной матрицей для получения обратной матрицы
		ReverseMoveForE(n, A, E, InvA);

		//Вывод обратной матрицы
		OutPutRevA(n, InvA, output);
	}

	//Освобождаем память
	delete[] A;
	delete[] B;
	delete[] ASave;
	delete[] BSave;
	delete[] InvA;
	delete[] X;
	delete[] Nev;
	fclose(input);
	fclose(output);

}

