#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>

using namespace std;

void EntryMassiv(int n, float* A, float* ASave, FILE* input);//Функция считывания из файла матрицы
void EntryB(int n, float* B, float* BSave, FILE* input);//Функция считавания из файла свободных членов

void OutPutMassiv(int n, float* A);//Печатаем двумерный массив
void OutPutB(int n, float* B);//Печатаем одномерный массив

void CreateE(int n, float* E); //Создаем единичную матрицу

int MaxInColumn(int n, float* A, int col);//Определеяем наибольший по модулю элемент в столбце
int LineTrans(int n, float* A, float* B, float* E, int str, int col);//Меняем строки местами

void FrontMove(int n, float* A, float* B, float* E, int* CountTrans);//Прямой ход метода Гаусса

void ReverseMove(int n, float* A, float* B, float* X);//Обратный ход метода Гаусса
void ReverseMoveForE(int n, float* A, float* E, float* InvA);//Обратный ход Гауса с единичной матрицей для получения обратной матрицы

float CalcDet(int n, float* A, int CountTrans);//Высчитываем определитель матрицы
void CaclNevyaz(int n, float* A, float* B, float* X, float* Nev);//Высчитываем невязки

void OutPutNevyaz(int n, float* Nev, FILE* output);//Вывод невязоки и занесение их в файл
void OutPutX(int n, float* X, FILE* output);//Вывод результат вычислений и занесение их в файл
void OutPutDet(float det, FILE* output); // Вывод определителя и занесение его в файл
void OutPutRevA(int n, float* InvA, FILE* output); // Вывод обратной матрицы и занесение ее в файл
