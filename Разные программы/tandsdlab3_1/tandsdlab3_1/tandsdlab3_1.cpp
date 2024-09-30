#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <fstream>
#include<map>
#include<string>
using namespace std;
map<unsigned char, unsigned char> fDict()
{
    map<unsigned char, unsigned char> Dict;
    int tmp = 0;
    int i = 0;

    for (i = 0; i < 33; i++)
    {
        Dict[(unsigned char)(i)] = (unsigned char)(i);
    }

    for (i = 33; i < 256; i++)
    {
        if (i + 5 > 255)
            tmp = (i + 5) - 255 + 32;
        else
            tmp = (i + 5);

        Dict[(unsigned char)(i)] = (unsigned char)(tmp);
    }// Создание словаря

    return Dict;//возвращение словаря
}
bool WriteT(string FN, string txt)//Заполнение строк и проверка создался ли файл.
{
    bool Res = true;

    ofstream fout(FN);

    if (fout.is_open())
    {
        // запись строк в файл
        fout << txt << endl;

        fout.close();// закрываем файл
    }
    else
    {
        Res = false;
    }

    return Res;
}
bool WriteTC(string FN, string txt, map<unsigned char, unsigned char> Dictionary)//Заполнение строк с помощью шифра
{
    bool Res = true;

    ofstream fout(FN);

    if (fout.is_open())
    {
        string temp = "";

        // Замена кодов символов
        for (int i = 0; i < txt.size(); i++)
        {
            temp += Dictionary[txt[i]];
        }

        // запись строк в файл
        fout << temp << endl;

        fout.close();// закрываем файл
    }
    else
    {
        Res = false;
    }

    return Res;
}
string ReadF(string FN)//открываем файл для чтение и если файл пуст возвращается пустая строка
{
    string res = "";

    ifstream fin(FN); // открыли файл для чтения

    if (fin.is_open())
    {
        string temp = "";

        while (!fin.eof())
        {
            temp = "";

            fin >> temp;

            temp += " ";

            if (temp.length() > 0)
            {
                res += temp;
            }
        }
    }

    return res;
}
unsigned char FVINDICT(map<unsigned char, unsigned char> Dictionary, unsigned char vl)//составление массива с номерами элемента
{
    unsigned char Res = 0;

    for (int i = 0; i < 256; i++)
    {
        if (Dictionary[i] == vl)
            Res = i;
    }

    return Res;
}
string Rcrypto(string FN, map<unsigned char, unsigned char> Dictionary)//Чтение зашифрованного файла,передача имя и словарь, возвращается строка с расшифрованным текстом или пустая строка
{
    string res = "";

    ifstream fin(FN); // открыли файл для чтения

    if (fin.is_open())
    {
        string temp = "";

        while (!fin.eof())
        {
            temp = "";

            fin >> temp;

            temp += " ";

            unsigned char index = 0;

            // Замена кодов символов
            for (int i = 0; i < temp.size(); i++)
            {
                index = 0;
                index = FVINDICT(Dictionary, temp[i]);
                if (index > 0)
                    res += unsigned char(index);
                else
                    res += " ";
            }

        }
    }

    return res;
}
// Вывод текста по четыре предложения
void Dtxt(string note)
{
    int count = 0;
    for (int i = 0; i < note.size(); i++)
    {

        if ((unsigned char(note[i]) >= 192) && (unsigned char(note[i]) <= 223))
        {
            if (count == 5)
            {
                cout << endl << endl;
                count = 0;
            }
            cout << endl << note[i];
            count++;
        }
        else
            cout << note[i];
    }
}







int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    map<unsigned char, unsigned char> Dictionary = fDict();
    int i=0;
    string TEXT = "Скажика дядя ведь не даром \n\ Москва спаленная пожаром Французу отдана\n\  Ведь были ж схватки боевые\n\ Да говорят еще какие Недаром\n\
        помнит вся Россия Про день \n\
        Бородина";
    if (WriteT("1.txt", TEXT))
        cout << "Файл создан!" << endl;
    else
        cout << "Файл не создан!" << endl;
    string RS = "";
    RS = ReadF("1.txt");
    if (WriteTC("2.txt", RS, Dictionary))
        cout << "Файл с шифром создан!" << endl;
    else
        cout << "Файл с шифром не создан!" << endl;
    string RCR = "";
    RCR = Rcrypto("2.txt", Dictionary);
    if (RCR.size() > 0)
    {
        cout << "Файл расшифрован!" << endl;
        cout << endl << endl;

        // Вывести текст

        // Вывести текст по 5 предложений
        Dtxt(RCR);
    }
    else
        cout << "Файл пустой!" << endl;

    cout << endl << endl;
}


        
    


