#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>

using namespace std;

void EntryMass(int N, float* A, float* ASave, FILE* in);//������� ���������� �� ����� �������
void EntryB(int N, float* B, float* BSave, FILE* in);//������� ���������� �� ����� ��������� ������

void OutPutMass(int N, float* A);//�������� ��������� ������
void OutPutB(int N, float* B);//�������� ���������� ������

void CreateE(int N, float* E); //������� ��������� �������

int MaxInColumn(int N, float* A, int col);//����������� ���������� �� ������ ������� � �������
int LineTrans(int N, float* A, float* B, float* E, int str, int col);//������ ������ �������

void Frontmove(int N, float* A, float* B, float* E, int* CountTrans);//������ ��� ������ ������

void ReverseMove(int N, float* A, float* B, float* X);//�������� ��� ������ ������
void ReverseMoveForE(int N, float* A, float* E, float* InvA);//�������� ��� ����� � ��������� �������� ��� ��������� �������� �������

float CalcDet(int N, float* A, int CountTrans);//����������� ������������ �������
void CaclNevyaz(int N, float* A, float* B, float* X, float* Nev);//����������� �������

void OutPutNevyaz(int N, float* Nev, FILE* out);//����� �������� � ��������� �� � ����
void OutPutX(int N, float* X, FILE* out);//����� ��������� ���������� � ��������� �� � ����
void OutPutDet(float det, FILE* out); // ����� ������������ � ��������� ��� � ����
void OutPutRevA(int N, float* InvA, FILE* out); // ����� �������� ������� � ��������� �� � ����
