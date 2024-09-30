#include "Header.h"

//������� ���������� �� �����
void EntryMass(int N, float* A, float* ASave, FILE* in)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fscanf(in, "%f", &(*(A + i * N + j)));
			*(ASave + i * N + j) = *(A + i * N + j);
		}
	}
}//������� ���������� �� ����� �������
void EntryB(int N, float* B, float* BSave, FILE* in)
{
	for (int j = 0; j < N; j++)
	{
		fscanf(in, "%f", &(B[j]));
		BSave[j] = B[j];
	}
}

//����� �� ������� ������ �� �����
void OutPutMass(int N, float* A)
{
	cout << endl << "������� ������� ���������:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << *(A + i * N + j) << " ";
		}
		cout << std::endl;
	}
}
void OutPutB(int N, float* B)
{
	cout << endl << "������� ��������� ������:" << endl;
	for (int i = 0; i < N; i++) {
		cout << B[i] << "\n";
	}
}

//�������� ��������� �������
void CreateE(int N, float* E) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (i == j)
				*(E + i * N + j) = 1;
			else
				*(E + i * N + j) = 0;
		}
}

//����������� ����������� �������� � ������������ �����
int MaxInColumn(int N, float* A, int col)
{
	float max = fabs(*(A + col * N + col));//���������� ������� � �������
	int str = col;

	for (int i = col + 1; i < N; i++)
	{
		if (fabs(*(A + i * N + col)) > max)
		{
			max = *(A + i * N + col);
			str = i;
		}
	}

	return str;
}
int LineTrans(int N, float* A, float* B, float* E, int str, int col)
{
	if (str == col)//���� ���������� ��������� �������� �������, �� ������ ������ ������� �� �����
		return 0;
	else
	{
		float buffer;

		for (int i = 0; i < N; i++)
		{
			//������ ������ �������
			buffer = *(A + col * N + i);
			*(A + col * N + i) = *(A + str * N + i);
			*(A + str * N + i) = buffer;

			//������ ������ ��������� �������
			buffer = *(E + col * N + i);
			*(E + col * N + i) = *(E + str * N + i);
			*(E + str * N + i) = buffer;
		}
		//������ ������ ��������� �����
		buffer = *(B + col);
		*(B + col) = *(B + str);
		*(B + str) = buffer;

		return 1;
	}
}

//������ ��� ������ ������
void Frontmove(int N, float* A, float* B, float* E, int* CountTrans)
{
	float d;

	for (int col = 0; col < N; col++)//������ �� ��������
	{
		*CountTrans += LineTrans(N, A, B, E, MaxInColumn(N, A, col), col);

		for (int str = col + 1; str < N; str++)//������ �� ������� ���� ��. ���������
		{
			d = *(A + str * N + col) / *(A + col * N + col); //����������� �����������

//�������� �� ����� ������� ������ �������� �������� ��. ���������, ���������� �� ����.
			for (int i = col; i < N; i++)
				*(A + str * N + i) = *(A + str * N + i) - d * *(A + col * N + i);

			//�������� �� ����� ��������� ������� ������ �������� �������� ��. ���������, ���������� �� ����.
			for (int i = 0; i < N; i++)
				*(E + str * N + i) = *(E + str * N + i) - d * *(E + col * N + i);

			//�������� �� ������ �������� ������� ��������� ������ ��������, 
			//������� ��������� � ������ �������� �������� ��. ���������, �����. �� ����.
			B[str] = B[str] - d * B[col]; // ������� (3)
		}
	}
}

//�������� ��� ��� ��������� ������� � ��� ��������� �������� �������
void ReverseMove(int N, float* A, float* B, float* X)
{
	float d, s;

	d = 0;

	for (int k = N - 1; k >= 0; k--) // �������� ���
	{
		d = 0;
		//����������� ����� ����� ����� � ��� ���������� �
		for (int j = k + 1; j < N; j++)
		{
			s = *(A + k * N + j) * X[j];
			d = d + s;
		}
		X[k] = (B[k] - d) / *(A + k * N + k); //�������� �������� �

	}
}
void ReverseMoveForE(int N, float* A, float* E, float* InvA)
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
float CalcDet(int N, float* A, int CountTrans) {
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
