#define _CRT_SECURE_NO_WARNINGS
#include <list>
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list<int>spisok;
    int N, number;

    cout << "Количество чисел:";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "Число: ";
        cin >> number;
        spisok.push_back(number);
    }

    list <int> ::iterator it;

    cout << "Ваш список: ";
    for (it = spisok.begin(); it != spisok.end(); it++) {
        cout << (*it) << " ";
    }

    spisok.unique();

    cout << "\nВаш список после удаления чисел: ";
    for (it = spisok.begin(); it != spisok.end(); it++) {
        cout << (*it) << " ";
    }
}
