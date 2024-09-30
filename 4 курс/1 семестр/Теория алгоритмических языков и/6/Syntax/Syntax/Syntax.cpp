#include "TDiagram.h"
#include <Windows.h>
#include <iostream>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TScaner* scan = new TScaner("example.txt");
    TDiagram* diag = new TDiagram(scan);
    
    diag->S();
    TypeLEX lex;
    int type = scan->Scan(lex);
    if (type == TEnd)
        printf(" Ошибок не обнаруженно\n");
    else
        scan->PError(" Лишний текст в конце файла\n", "");

}
