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
	// �����������. ��������� ��������� row - ���������� ����� � column - ���-�� ��������
	matrix(int row, int column) {
		this->row = row;
		this->column = column;
	}
	// ������� ���������� �������
	void input() {
		for (int i = 0; i < row * column; ++i) {
			ar.emplace_back(i+1);
		}
	}
	// ������� ���������������� �������
	void Trans() {
	
		deque<int> temp;	// ������ ������� �� ��������� � ���� ����������������� �������
		int tempNum = 0;	// ���������� ��� ������ ����� �������� � ������� �������
		for (int i = 0; i < column; ++i) {
			temp.emplace_back(ar[i]);					// ��������� i ������� � ������
			for (int j = 1; j < row; ++j) {		
				temp.emplace_back(ar[j * column + i]);	// ��������� ��������� ������� �������
			}
		}
		ar = temp;
		tempNum = row;
		row = column;
		column = tempNum;
	}
	// ����� ������� � �������
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
	// ��� ������ ����� ��� ��� ����������
	const int numRow = 5;		// ���������� ����� � �������
	const int numColumn = 5;	// ���������� �������� � �������

	double t1, t2, dt;			// ���������� ��� �������� ������� ����������
	matrix A(numRow, numColumn);// ������� A ��� ������ ��� openMP
	matrix B(numRow, numColumn);// ������� B ��� ������ c openMP
	cout << endl;
	t1 = omp_get_wtime();		// ������ �������
	A.input();					// ���������� �������
	A.print();					// ����� ������� � �������
	A.Trans();					// ���������������� �������
	A.print();					// ����� ������� � �������
	t2 = omp_get_wtime();		// ����� �������
	dt = t2 - t1;				// ����������� ����� ������ ������� ���������
	cout << "Work time = " << dt << endl << endl;

	t1 = omp_get_wtime();		// ������ �������
	#pragma omp parallel					// ���������� ��������� � �������������� ���������������
	{
		B.input();				// ���������� �������
		B.print();				// ����� ������� � �������
		B.Trans();				// ���������������� �������
		B.print();				// ����� ������� � �������
	}
	t2 = omp_get_wtime();		// ����� �������
	dt = t2 - t1;				// ����������� ����� ������ ������� ���������
	cout << "Work time = " << dt << endl << endl;
}