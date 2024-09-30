#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;
int* m;//указатель на область свободной памяти
int* dwn;//указатель на нижняю границу стека
int* top;//Указатель на вершину стека
 void pushst(int i) //Занесение элемента в стек
{
        if (m > dwn) 
        {
            printf("Стек полон\n");
            return;
        }   
        *m = i;
        m++;
}
 int popst(void)//Получение верхнего элемента из стека
 {
     m--;
     if (m < top)
     {
         printf("Стек пуст");
         return 0;
     }
     return *m;
 
 }
 void Delst()//Очистка стека
 {
     while (m >= top)
         m--;
     cout << "Стек очищен\n";
 }
   
int main()
{   
    setlocale(LC_ALL, "RUSSIAN");
    int n; //размер массива
    int* t;
    cout << "Введите размер массива: ";
    cin >> n;
    m = (int*)malloc(n * sizeof(int));
    if (!m)
    {
        printf("Ошибка при выделении памяти");
        exit (1);
    }
    top = m;
    dwn = m + n - 1;
    cout << "Введите массив\n";
    //Ввод одномерного динамического массива в стек
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        pushst(array[i]);
    }

    t = m - 1;
    //Вывод значений из стека в массив
    cout << "\nВведенный массив:\n";
    for (int i = 0; i < n; i++)
    {
        cout << *t << " ";
        t--;
    }

    cout << "\n";
    Delst();
    popst();

    cout << "\n\n";

    system("pause");


    
}

