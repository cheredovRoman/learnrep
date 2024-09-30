#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
//функция факториала
int factor(int a) {
    int FA = 1;
    for (int i = a; i > 1; i--)
        FA *= i;
    return FA;
}
//функция g
int g(int x) {
    x = factor(x);
       return x;
}
//функция h
int h(int x, int y,int t) { 
    if (x>2*y)
        return x - 2 * y + 4 * t; 
    else
        return 4*t;
 
}
//Рекурсивное вычисление
int f(int x, int y) {
    if (y == 0)
        return g(x);
    return h(x, y - 1, f(x, y - 1));
}
//Итерационное вычисление
int f1(int x, int y) {
    int q = g(x);
    for (int i = 0; i < y; i++)
        q = h(x, i,q);
    return q;
}

int main()
{
    system("chcp 1251");
    system("cls");
    int x, y;
    cout << "Введите значения для f(x,y):" << endl << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << endl << "Рекурсивное вычисление: ";
    cout << f(x, y);
    cout << endl << "Нерекурсивное вычисление: ";;
    cout << f1(x, y) << endl;
}
