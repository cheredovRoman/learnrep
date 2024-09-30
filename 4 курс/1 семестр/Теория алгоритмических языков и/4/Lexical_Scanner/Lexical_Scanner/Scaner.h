#pragma once
#ifndef __SCANER
#define __SCANER
#include "Defs.h"

class Scaner
{
private:
	TypeIM im;	// �������� ������
	int uk;		// ��������� ������� � �������� ������
public:
	Scaner(const char* FileName);
	~Scaner() {};

	void PrintError(const char* err, const char* c);
	void GetData(const char* FileName);
	int Scan(TypeLEX Lex);

};

#endif // __SCANER
