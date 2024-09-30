
#include "defs.h"


class Scaner {
private:
	TypeMod t; // исходный текст
	int uk; // позиция в исходном тексте

	FILE* in;
public:
	Scaner(FILE*);
	~Scaner() {}
	//void SetUK(int posInText, int lineInText, int posInLine);
	void PutUK(int);
	int GetUK();

	void PrintError(string, string);
	int Scan(TypeLex l); // выделение очередной лексемы

	void GetData(FILE*); // ввод текста из файла с заданным именем
};

#pragma once
