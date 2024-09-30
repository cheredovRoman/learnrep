#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
//Создание нового узла
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
//Добавление нового узла
struct Node* insert(Node* t, int x)
{
    // Возвращаем новый узел, если дерево пустое
    if (t == NULL) return newNode(x);

    // Проходим в нужное место и вставляет узел
    if (x < t->data)
        t->left = insert(t->left, x);
    else
        t->right = insert(t->right, x);

    return t;
}
//печать бинарного дерева в виде дерева повернутого на -90 градусов
void Pr90(Node* t, int l) {
    if (t == NULL)
        return;
    Pr90(t->right, l + 1);
    for (int i = 0; i < l; ++i)
        cout << "\t";
    cout << t->data << endl;
    Pr90(t->left, l + 1);
}
//печать бинарного дерева в ФАЙЛ в виде дерева повернутого на -90 градусов
void Pr90File(Node* t, ofstream& fout, int l) {
    if (t == NULL)
        return;
    Pr90File(t->right, fout, l + 1);
    for (int i = 0; i < l; ++i)
        fout << "\t";
    fout << t->data << endl;
    Pr90File(t->left, fout, l + 1);
}

// проверка пустоты бинарного дерева 
int isempty(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 0;
    }
    else
        return 1;
}

// поиск в бинарном дереве
Node* find(Node* t, int x, int& r) {
    r++;
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return find(t->left, x, r);
    else if (x > t->data)
        return find(t->right, x, r);
    else
        return t;
}
//Поиск корня из второго дерева в узлах первого
Node* Nach(Node* root1, Node* root2) {
    if (root1 == NULL)
        return NULL;

    else if (root1->data == root2->data)
        return root1;
    else if (root1->data > root2->data)
        Nach(root1->left, root2);
    else
        Nach(root1->right, root2);
}
//Проверка, содержится ли второе дерево в первом
int Sravn(Node* root1, Node* root2) {
    if (root2 == NULL)
        return -1;
    if (root1 == NULL && root2 != NULL)
        return 0;
    if (root1->data == root2->data) {
        if (Sravn(root1->left, root2->left) && Sravn(root1->right, root2->right))
            return 1;
    }
    else
        return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    struct Node* root1 = NULL;//1е дерево
    struct Node* root2 = NULL;//2е дерево
    string buf1, buf2;     //Строки из файла
    int INTbuf;            //Цифра строки
    int r = 0;             //Для определения уровня
    string word;           //слово строки
    stringstream sstream;  //строковый поток для её разделения на слов
    ifstream fin;          //файл для чтения
    ofstream fout;         //файл для записи

    fin.open("input.dat");
    getline(fin, buf1);
    sstream << buf1;
    while (sstream >> word) {
        INTbuf = stoi(word);  //перевод слова в число
        root1 = insert(root1, INTbuf);
    }

    getline(fin, buf2);
    sstream.clear();
    sstream << buf2;
    while (sstream >> word) {
        INTbuf = stoi(word);  //перевод слова в число
        root2 = insert(root2, INTbuf);
    }
    fin.close();

    cout << "Первое дерево:\n\n";
    Pr90(root1, 0);
    cout << "Второе дерево:\n\n";
    Pr90(root2, 0);

    sstream.clear();
    sstream << buf2;
    sstream >> word;


    if (Sravn(Nach(root1, root2), root2))
        printf("\n\n 2е дерево СОДЕРЖИТСЯ в 1м\n Уровень %d", r - 1);
    else
        printf("\n\n 2е дерево НЕ СОДЕРЖИТСЯ в 1м");

    fout.open("output.dat");
    fout << "Исходные данные:\n";
    fout << buf1;
    fout << endl;
    fout << buf2;
    fout << "\n\nПервое дерево:\n\n";
    Pr90File(root1, fout, 0);
    fout << "Второе дерево:\n\n";
    Pr90File(root2, fout, 0);
    if (Sravn(Nach(root1, root2), root2))
        fout << "\n\n 2е дерево СОДЕРЖИТСЯ в 1м\n Уровень " << r - 1;
    else
        fout << "\n\n 2е дерево НЕ СОДЕРЖИТСЯ в 1м";
    fout.close();

    return 0;
}
