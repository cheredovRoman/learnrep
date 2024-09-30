#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
//Вычисление [lg y/x]
int f(int x, int y) {
    int z = 0;
    while ((z <=log(y)/x) && (log(y) / x >= (z + 1) * (z + 1)))
        z++;
    return z;
}

int main()
{
    do {
        system("chcp 1251");
        system("cls");
        int x, y;
        cout << "Введите значения для f(x,y):" << endl << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;

        cout << endl << "Вычисление: ";
        cout << f(x, y);

        cout << endl << endl << "Esc - выйти, иначе - заново...";
    } while (_getch() != 27);
}
