#include <iostream>
#include "stdio.h"
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

int main() {
	int a, b, n, y;

	char s;
	printf_s("\n\rInput A: ");
	scanf_s("%d", &a);
	printf_s("\n\rInput B: ");
	scanf_s("%d", &b);
	printf_s("\n\rInput N: ");
	scanf_s("%d", &n);
	_asm
	{
		mov ecx, [n]
		mov ebx, 00
		cycl:mov eax, ecx
		imul eax, [a]
		add ebx, eax
		mov eax, ecx
		imul eax, [b]
		add ebx, eax
		loop cycl
		mov[y], ebx


	}
	printf_s("\nY: %d", y);

	scanf_s("%1c", &s);

	return 0;
}

