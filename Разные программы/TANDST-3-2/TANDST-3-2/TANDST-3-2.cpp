#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <stack>
using namespace std;
void Del(stack <int> st) {
    st.pop();
    while (st.empty());
    cout << "Стек очищен";
}



int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int n; 
    cout << "Введите размер массива: ";
    cin >> n;
    stack <int> st;
    cout << "Введите массив\n";
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        st.push(array[i]);
    }
    cout << "\n";
    int* top = new int();
    cout << "Введенный массив:\n";
    for (int i = 0; i < n; i++)
    {
        *top = st.top();
        st.pop();
        array[i] = *top;
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "  "; 
        st.push(array[n - i - 1]);
    }

    cout << "\n";
    Del(st);
    cout << "\n\n";

}

