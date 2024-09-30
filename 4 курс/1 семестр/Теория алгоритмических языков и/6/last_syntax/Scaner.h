
#include "defs.h"


class Scaner {
private:
	TypeMod t; // �������� �����
	int uk; // ������� � �������� ������

	FILE* in;
public:
	Scaner(FILE*);
	~Scaner() {}
	//void SetUK(int posInText, int lineInText, int posInLine);
	void PutUK(int);
	int GetUK();

	void PrintError(string, string);
	int Scan(TypeLex l); // ��������� ��������� �������

	void GetData(FILE*); // ���� ������ �� ����� � �������� ������
};

#pragma once
