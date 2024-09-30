#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>

using namespace std;

void EntryMassiv(int n, float* A, float* ASave, FILE* input);//������� ���������� �� ����� �������
void EntryB(int n, float* B, float* BSave, FILE* input);//������� ���������� �� ����� ��������� ������

void OutPutMassiv(int n, float* A);//�������� ��������� ������
void OutPutB(int n, float* B);//�������� ���������� ������

void CreateE(int n, float* E); //������� ��������� �������

int MaxInColumn(int n, float* A, int col);//����������� ���������� �� ������ ������� � �������
int LineTrans(int n, float* A, float* B, float* E, int str, int col);//������ ������ �������

void FrontMove(int n, float* A, float* B, float* E, int* CountTrans);//������ ��� ������ ������

void ReverseMove(int n, float* A, float* B, float* X);//�������� ��� ������ ������
void ReverseMoveForE(int n, float* A, float* E, float* InvA);//�������� ��� ����� � ��������� �������� ��� ��������� �������� �������

float CalcDet(int n, float* A, int CountTrans);//����������� ������������ �������
void CaclNevyaz(int n, float* A, float* B, float* X, float* Nev);//����������� �������

void OutPutNevyaz(int n, float* Nev, FILE* output);//����� �������� � ��������� �� � ����
void OutPutX(int n, float* X, FILE* output);//����� ��������� ���������� � ��������� �� � ����
void OutPutDet(float det, FILE* output); // ����� ������������ � ��������� ��� � ����
void OutPutRevA(int n, float* InvA, FILE* output); // ����� �������� ������� � ��������� �� � ����
