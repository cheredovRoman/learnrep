#include <iostream> 
#include "stdio.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
// ����� ������� � �������
void print(int* arr, int row, int column) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << arr[i * column + j] << "\t";
		}
		cout << endl;
	}
}
int main() {
	const int row = 4;			// ���-�� ����� �������
	const int column = 5;		// ���-�� �������� �������
	int array_A[row][column];	// �������� �������
	int array_temp[row][column];// ������� ��� �����������
	int row_fun = row, column_fun = column;	// �������� ���������� �������� � ������� ��� ������ �� ���� for
	// ���������� �������
	for (int i = 0; i < row_fun; ++i) {
		for (int j = 0; j < column_fun; ++j) {
			array_A[i][j] = i * column + j + 1;
		}
	}

	print(*array_A, row_fun, column_fun);	// ������ �������� �������
	cout << "Start matrix" << endl;
	// ������� ������ ��� ���������� ������
	__asm {
		and ecx, 0FFFFh;
		mov eax, 0
		mov ebx, 0
	}
	// ���������������� �������
	for (int i = 0; i < column; ++i) {
		for (int j = 0; j < row; ++j) {
			__asm {
				// ������ ������ �������� �� �������
				// � eax ����� ������ ��� ������� �������� �������
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
				movd mm0, [array_A + eax]	// � mm0 ����� �������
				
				// ��������� ������ �������� � �������
				// � eax ����� ������ �� ����� ���� ����� ������� ������ ������� �������
				mov eax, i
				mov ebx, row
				mul ebx
				mov ebx, j
				add eax,ebx
				mov ebx, 4
				mul ebx
				movd [array_temp + eax], mm0 // �� mm0 ��������� ������� �� ������ �������
			}
		}
	}
	// ������� ������ ��� ���������� ������ ���������
	__asm {
		and ecx, 0FFFFh;
		mov ebx, 16			// � ������� ebx ����� ������ ��� ������ ���
	}
	// �� ��������� ������� �������� ������ � �������� �������
	for (int i = 0; i < column; ++i) {
		__asm {
			// �������� ������ ������ �� ������� ��������� ��������
			mov eax, i
			mul ebx

			movups xmm0, [array_temp+eax]	// ����� ������ 4 �������� � xmm0
			movups [array_A+eax], xmm0		// ��������� ��� 4 �������� � �������� �������
		}
	}
	// ������ ���������� �������� � ������� �������
	row_fun = column;
	column_fun = row;
	
	cout << endl;
	print(*array_A, row_fun, column_fun);
	cout << "End matrix" << endl;
	system("pause");
}