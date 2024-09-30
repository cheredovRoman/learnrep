#include <iostream>
#include <mpi.h>
#include <ctime>
#include <deque>
using namespace std;

// ������� ���������� �������
void input(int *arr, int row,int column) {
	for (int i = 0; i < row * column; ++i) {
		arr[i] = i+1;
	}
	
}
// ������� ���������������� �������
void Trans(int* arr, int &row, int &column) {
	int temp[100][100];
	int a;
	// ����������� ������
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			temp[i][j] = arr[i* column + j];
		}
	}
	// ����������������
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			arr[i + j * row] = temp[i][j];
		}
	}
	// row � column �������� �������
	a = row;
	row = column;
	column = a;
}
// ����� ������� � �������
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
	int numRow = 4;			// ���������� ����� � �������
	int numColumn = 2;		// ���������� �������� � �������
	const int size = 4;		// ���������� ����� size ������ ��� ������ ��� ����� ��� numRow � numColumn. 
							// ����������� size = 100 (���� ����� ������ ����� � ������� Trans ������ temp)

	double t1, t2, dt;		// ���������� ��� �������� ������� ����������
	int numtasks, rank;		

	int matrix[size][size];	// �������
	
	// ������������ MPI ����������
	MPI_Init(argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

	t1 = MPI_Wtime();	// ������ �������

	// ������� 0
	// ��������� ������� ���������� � ���������� � �������� 1 � 2
	if (rank == 0) {
		input(*matrix, numRow, numColumn);					// ���������� �������
		MPI_Send(matrix, numRow * numColumn, MPI_INT, 1, 1, MPI_COMM_WORLD);	// ������� ������������ 1 ��������
		MPI_Send(matrix, numRow * numColumn, MPI_INT, 2, 2, MPI_COMM_WORLD);	// ������� ������������ 2 ��������
		t2 = MPI_Wtime();	// ����� �������
		dt = t2 - t1;		// ����������� ����� ������ ������� ���������
		MPI_Send(&dt, 1, MPI_DOUBLE, 4, 6, MPI_COMM_WORLD);						// ����� ���������� ������ �������� ������������ 4 ��������
	}
	// ������� 1
	// �������� ������� � �������
	else if (rank == 1) {
		MPI_Recv(matrix, numRow * numColumn, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);	// ��������� ���������� ������� �� �������� 0
		print(*matrix, numRow, numColumn);												// ����� ������� � �������
		t2 = MPI_Wtime();	// ����� �������
		dt = t2 - t1;		// ����������� ����� ������ ������� ���������
		MPI_Send(&dt, 1, MPI_DOUBLE, 4, 7, MPI_COMM_WORLD);								// ����� ���������� ������ �������� ������������ 4 ��������		
	}
	// ������� 2
	// ������������� ������� � ���������� � �������� 3
	// ��� �� ���������� ����� �������� ����� (row) � ������� (column) �������� 3
	else if (rank == 2) {
		MPI_Recv(matrix, numRow * numColumn, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);	// ��������� ���������� ������� �� �������� 0
		Trans(*matrix, numRow, numColumn);												// ���������������� �������	
		MPI_Send(matrix, numRow * numColumn, MPI_INT, 3, 3, MPI_COMM_WORLD);			// ���������� ����������������� ������� �������� 3
		MPI_Send(&numRow, 1, MPI_INT, 3, 4, MPI_COMM_WORLD);							// ���������� ����� �������� ����� �������� 3
		MPI_Send(&numColumn, 1, MPI_INT, 3, 5, MPI_COMM_WORLD);							// ���������� ����� �������� ������� �������� 3
		t2 = MPI_Wtime();	// ����� �������
		dt = t2 - t1;		// ����������� ����� ������ ������� ���������
		MPI_Send(&dt, 1, MPI_DOUBLE, 4, 8, MPI_COMM_WORLD);								// ����� ���������� ������ �������� ������������ 4 ��������
	}
	// ������� 3
	// �������� ������� � �������
	else if (rank == 3) {
		MPI_Recv(&numRow, 1, MPI_INT, 2, 4, MPI_COMM_WORLD, &status);					// ��������� ����� �������� ����� �� �������� 2
		MPI_Recv(&numColumn, 1, MPI_INT, 2, 5, MPI_COMM_WORLD, &status);				// ��������� ����� �������� ����� �� �������� 2
		MPI_Recv(matrix, numRow * numColumn, MPI_INT, 2, 3, MPI_COMM_WORLD, &status);	// ��������� ���������� ������� �� �������� 2
		print(*matrix, numRow, numColumn);												// ����� ������� � �������	
		t2 = MPI_Wtime();	// ����� �������
		dt = t2 - t1;		// ����������� ����� ������ ������� ���������
		MPI_Send(&dt, 1, MPI_DOUBLE, 4, 9, MPI_COMM_WORLD);								// ����� ���������� ������ �������� ������������ 4 ��������
	}
	// ������� 4
	// �������� ����� ������ ������� �������� � ����� ���������� ���������� ���������
	if (rank == 4) {
		double time[4];
		MPI_Recv(&time[0], 1, MPI_DOUBLE, 0, 6, MPI_COMM_WORLD, &status);	// ��������� ����� ������ �������� 0
		MPI_Recv(&time[1], 1, MPI_DOUBLE, 1, 7, MPI_COMM_WORLD, &status);	// ��������� ����� ������ �������� 1
		MPI_Recv(&time[2], 1, MPI_DOUBLE, 2, 8, MPI_COMM_WORLD, &status);	// ��������� ����� ������ �������� 2
		MPI_Recv(&time[3], 1, MPI_DOUBLE, 3, 9, MPI_COMM_WORLD, &status);	// ��������� ����� ������ �������� 3
		// �������� ����� ������� ��������� ��������
		for (int i = 0; i < 4; ++i) {
			cout << "RunTime MPI Process " << i << " = " << time[i] << endl;
		}
		cout << "Total number of process: " << numtasks << endl << endl;
	}
	MPI_Finalize();	// ������������ MPI ���������
}