#pragma once
#ifndef __SCANER
#define __SCANER
#include "Defs.h"

class TScaner
{
private:
	TypeIM im;	// �������� ������
	int row_uk;	// ������� � ������
	int uk;		// ��������� ������� � �������� ������

public:
	TScaner(const char* FileName);
	~TScaner() {};

	void PError(const char* message, const char* error);

	bool SetUK(int position); 
	int GetUK();

	void GetData(const char* FileName);
	int Scan(TypeLEX Lex);

};

#endif // __SCANER
