#include <iostream> #include "stdio.h"
#define _CRT_SECURE_NO_WARNINGS using namespace std;

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
	{	mov ebx,00
		mov ecx, [n]
		cmp cx, 000
		jz END
		Start:cmp ecx, 000
		jz starta
		mov eax, ecx
		imul word ptr[a]
		add ebx, eax
		dec ecx
		jmp Start
		starta: mov ecx, [n]
		DB:cmp ecx, 000
		jz END
		mov eax, ecx
		imul eax,[b]
		add ebx, eax
		dec ecx
		jmp DB
		END:mov [y], ebx
		


	}
	printf_s("\nY: %d", y);

	scanf_s("%1c", &s);

	return 0;
}
