#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>

using namespace std;

void EntryMass(int N, float* A, float* ASave, FILE* in);//Функция считывания из файла матрицы
void EntryB(int N, float* B, float* BSave, FILE* in);//Функция считавания из файла свободных членов

void OutPutMass(int N, float* A);//Печатаем двумерный массив
void OutPutB(int N, float* B);//Печатаем одномерный массив

void CreateE(int N, float* E); //Создаем единичную матрицу

int MaxInColumn(int N, float* A, int col);//Определеяем наибольший по модулю элемент в столбце
int LineTrans(int N, float* A, float* B, float* E, int str, int col);//Меняем строки местами

void Frontmove(int N, float* A, float* B, float* E, int* CountTrans);//Прямой ход метода Гаусса

void ReverseMove(int N, float* A, float* B, float* X);//Обратный ход метода Гаусса
void ReverseMoveForE(int N, float* A, float* E, float* InvA);//Обратный ход Гауса с единичной матрицей для получения обратной матрицы

float CalcDet(int N, float* A, int CountTrans);//Высчитываем определитель матрицы
void CaclNevyaz(int N, float* A, float* B, float* X, float* Nev);//Высчитываем невязки

void OutPutNevyaz(int N, float* Nev, FILE* out);//Вывод невязоки и занесение их в файл
void OutPutX(int N, float* X, FILE* out);//Вывод результат вычислений и занесение их в файл
void OutPutDet(float det, FILE* out); // Вывод определителя и занесение его в файл
void OutPutRevA(int N, float* InvA, FILE* out); // Вывод обратной матрицы и занесение ее в файл
