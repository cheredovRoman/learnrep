#include "parametrs.h"
//������� ���������� �� �����
void EntryMassiv(int n, float* A, float* ASave, FILE* input)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(input, "%f", &(*(A + i * n + j)));
			*(ASave + i * n + j) = *(A + i * n + j);
		}
	}
}//������� ���������� �� ����� �������
void EntryB(int n, float* B, float* BSave, FILE* input)
{
	for (int j = 0; j < n; j++)
	{
		fscanf(input, "%f", &(B[j]));
		BSave[j] = B[j];
	}
}
//����� �� ������� ������ �� �����
void OutPutMassiv(int n, float* A)
{
	cout << endl << "������� ������� ���������:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(A + i * n + j) << " ";
		}
		cout << std::endl;
	}
}
void OutPutB(int n, float* B)
{
	cout << endl << "������� ��������� ������:" << endl;
	for (int i = 0; i < n; i++) {
		cout << B[i] << "\n";
	}
}
//�������� ��������� �������
void CreateE(int n, float* E) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				*(E + i * n + j) = 1;
			else
				*(E + i * n + j) = 0;
		}
}
//����������� ����������� �������� � ������������ �����
int MaxInColumn(int n, float* A, int col)
{
	float max = fabs(*(A + col * n + col));//���������� ������� � �������
	int str = col;
	for (int i = col + 1; i < n; i++)
	{
		if (fabs(*(A + i * n + col)) > max)
		{
			max = *(A + i * n + col);
			str = i;
		}
	}

	return str;
}
int LineTrans(int n, float* A, float* B, float* E, int str, int col)
{
	if (str == col)//���� ���������� ��������� �������� �������, �� ������ ������ ������� �� �����
		return 0;
	else
	{
		float buffer;

		for (int i = 0; i < n; i++)
		{
			//������ ������ �������
			buffer = *(A + col * n + i);
			*(A + col * n + i) = *(A + str * n + i);
			*(A + str * n + i) = buffer;

			//������ ������ ��������� �������
			buffer = *(E + col * n + i);
			*(E + col * n + i) = *(E + str * n + i);
			*(E + str * n + i) = buffer;
		}
		//������ ������ ��������� �����
		buffer = *(B + col);
		*(B + col) = *(B + str);
		*(B + str) = buffer;

		return 1;
	}
}

//������ ��� ������ ������
void Frontmove(int n, float* A, float* B, float* E, int* CountTrans)
{
	float d;

	for (int col = 0; col < n col++)//������ �� ��������
	{
		*CountTrans += LineTrans(n, A, B, E, MaxInColumn(n, A, col), col);

		for (int str = col + 1; str < n; str++)//������ �� ������� ���� ��. ���������
		{
			d = *(A + str * n + col) / *(A + col * n + col); //����������� �����������

//�������� �� ����� ������� ������ �������� �������� ��. ���������, ���������� �� ����.
			for (int i = col; i < n; i++)
				*(A + str * n + i) = *(A + str * n + i) - d * *(A + col * n + i);

			//�������� �� ����� ��������� ������� ������ �������� �������� ��. ���������, ����������			�� ����.
			for (int i = 0; i < n; i++)
				*(E + str * n + i) = *(E + str * n + i) - d * *(E + col * n + i);

			//�������� �� ������ �������� ������� ��������� ������ ��������, 
			//������� ��������� � ������ �������� �������� ��. ���������, �����. �� ����.
			B[str] = B[str] - d * B[col]; // ������� (3)
		}
	}
}
void ReverseMoveForE(int n, float* A, float* E, float* InvA)
{
	float* d = new float[N];
	float s;

	for (int i = 0; i < N; i++)
		d[i] = 0;

	for (int str = N - 1; str >= 0; str--) // �������� ���
	{
		for (int i = 0; i < N; i++)
			d[i] = 0;

		//����������� ����� ����� ����� � ��� ���������� ���������� �������� �������
		for (int j = str + 1; j < N; j++)
		{
			for (int i = N - 1; i >= 0; i--) {
				s = *(A + str * N + j) * *(InvA + j * N + i);
				d[i] += s;
			}
		}
		//�������� �������� �������� �������
		for (int i = N - 1; i >= 0; i--)
			*(InvA + str * N + i) = (*(E + str * N + i) - d[i]) / *(A + str * N + str);
	}
}

//���������� ������������
float CalcDet(int n, float* A, int CountTrans) {
	float det;
	if (CountTrans % 2 == 0)//���� ������
		det = 1;
	else
		det = -1;

	//������������ �����. ������� ����� ������������ ��������� ��. ���������
	for (int i = 0; i < N; i++)
		det *= *(A + i * N + i);
	return det;
}

//���������� �������
void CaclNevyaz(int N, float* A, float* B, float* X, float* Nev) {

	for (int i = 0; i < N; i++) {
		float sum = 0;
		for (int j = 0; j < N; j++) {
			sum += *(A + i * N + j) * *(X + j);
		}
		*(Nev + i) = *(B + i) - sum;
	}
}

//����� ����������� � ������� � ������ �� � ����
void OutPutNevyaz(int N, float* Nev, FILE* out) {

	cout << endl << "�������: " << endl;
	fprintf(out, "\n�������: \n");

	for (int i = 0; i < N; i++)
	{
		fprintf(out, "r[%d] = %f \n", i + 1, Nev[i]);
		cout << "r[" << i + 1 << "]=" << *(Nev + i) << " " << endl;
	}
}
void OutPutX(int N, float* X, FILE* out)
{
	cout << endl << "������� �������: " << endl;
	fprintf(out, "������� �������: \n");

	for (int i = 0; i < N; i++)
	{
		fprintf(out, "x[%d] = %f \n", i + 1, X[i]);
		cout << "x[" << i + 1 << "]=" << X[i] << " " << endl;
	}
}
void OutPutDet(float det, FILE* out) {
	cout << endl << "������������ = " << det << endl;
	fprintf(out, "\n������������ = %f \n", det);
}
void OutPutRevA(int N, float* InvA, FILE* out) {
	cout << endl << "�������� �������: " << endl;
	fprintf(out, "\n�������� �������: \n");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			fprintf(out, "%.2f ", *(InvA + i * N + j));
			cout << *(InvA + i * N + j) << " ";
		}
		fprintf(out, "\n");
		cout << endl;
	}
}
