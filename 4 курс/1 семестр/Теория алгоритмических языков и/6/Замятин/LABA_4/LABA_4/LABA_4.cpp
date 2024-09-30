#include <iostream>
#include <Windows.h>
#include "Scaner.h"
#include "Diagram.h"
#define fileName "testCode.txt"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Scaner* scan = new Scaner(fileName);
	Diagram* diag = new Diagram(scan);
	diag->Programma();
	TypeLEX lex;
	int type;
	type = scan->codeScaner(lex);
	if (type == TEnd) printf("Синтаксических ошибок не обнаружено. \n");
	else scan->PrintError("Лишний текст в конце программы.", "");



	//do
	//{
	//	type = scan->codeScaner(lex);
	//	printf("lex: %s -> type: %d\n", lex, type);
	//} while (type != TEnd);

}
