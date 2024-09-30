
#include "Scaner.h"
#include <Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Scaner* scan = new Scaner("input.txt");
	int type;
	TypeLEX lex;
	do {
		type = scan->Scan(lex);
		printf("lex: %s -> type: %d\n", lex, type);
	} while (type != TEnd);
}

