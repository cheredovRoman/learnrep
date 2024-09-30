
#include "defs.h"


class Scaner {
private:
	TypeMod t; // �������� �����
	int uk; // ������� � �������� ������
	int line_number;		//������
	int position;		//�������
	FILE* in;
public:
	Scaner(FILE*);
	~Scaner() {}
	void PutUK(int);
	int GetUK();

	void PrintError(string, string);
	int Scan(TypeLex l); // ��������� ��������� �������

	void GetData(FILE*); // ���� ������ �� ����� � �������� ������
};

#pragma once
