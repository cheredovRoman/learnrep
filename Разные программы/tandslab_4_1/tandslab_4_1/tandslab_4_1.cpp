#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

struct list {
    int num;
    list* next;
};

void MakeList(int n, list** begin) {
    if (n > 0) {
        (*begin) = new list();
        cout << "Число: ";
        cin >> (*begin)->num;
        (*begin)->next = NULL;
        MakeList(n - 1, &((*begin)->next));
    }
}

void PrintList(list* begin) {
    if (begin != NULL) {
        cout << begin->num << "\t"; PrintList(begin->next);
    }
    else cout << "\n";
}

void Deletething(list*& lst) {
    list* t, * i, * j, * p = lst;
    while (p != NULL) {
        i = p->next;
        while ((i != NULL) && (i->num == p->num))
            i = i->next;
        if (i != p->next) {
            j = p->next;
            while (j != i) {
                t = j;
                j = j->next;
                delete t;
            }
            p = p->next = i;
            continue;
        }
        p = p->next;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int colvo;
    list* begin = NULL;
    begin = new list;
    cout << "Количество чисел: ";
    cin >> colvo;
    MakeList(colvo, &begin);
    PrintList(begin);
    Deletething(begin);
    PrintList(begin);
    return 0;
}
