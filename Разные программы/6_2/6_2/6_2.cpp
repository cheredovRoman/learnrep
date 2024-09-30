#include <iostream> 
#include "stdio.h"
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

int main() {
	int a, b, d, c, result;

	char s;
	printf_s("\n\rInput A: "); 
	scanf_s("%d", &a); 
	printf_s("\n\rInput B: "); 
	scanf_s("%d", &b); 
	printf_s("\n\rInput C: "); 
	scanf_s("%d", &d);
	printf_s("\n\rInput D: "); 
	scanf_s("%d", &c);
	_asm
	{
		mov ebx, [a]
		imul ebx,[b]
		mov eax, [d]
		imul eax, [c]
		cmp eax,00
		jz exid
		mov eax, ebx
		imul eax, [c]
		cwd
		idiv [d]
		mov ebx, eax
		jmp exid
		exid:mov result, ebx


	}
	printf_s("\nResult: %d", result); 
	scanf_s("%1c", &s);
	return 0;
}
