#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

#define MAX_TEXT 10000 // ������������ ����� ������
#define MAX_LEX 100 // ������������ ����� �������
#define MAX_KEYW 10 // ����� �������� ����
typedef char TypeLex[MAX_LEX]; // ����������� �������
typedef char TypeMod[MAX_TEXT];

// �������� �����
#define TConst 1
#define TClass 2
#define TMain 3
#define TInt 4
#define TShort 5
#define TLong 6
#define TFloat 7
#define TReturn 8
#define TWhile 9


// �������������� � ���������
#define TIdent 20
#define TConstInt 30
#define TConstExp 31
#define TConstFloat 32


// ����������� �����
#define TDot 40
#define TComma 41
#define TSemicolon 42
#define TLeftBracket 43
#define TRightBracket 44
#define TLeftSquareBracket 45
#define TRightSquareBracket 46

// ����� ��������
#define TLess 50
#define TLessOrEqual 51
#define TMore 52
#define TGreatOrEqual 53
#define TEqual 54
#define TNotEqual 55
#define TOperatorEqvivalentnosti 56
#define TPlusEqual 57
#define TMinusEqual 58
#define TMultEqual 59
#define TDivEqual 60
#define TModeEqual 61

#define TSave 67
#define TLeftShift 69
#define TRightShift 70

#define TPlus 74
#define TMinus 75
#define TMult 76
#define TDiv 77
#define TMode 78

// ����� ��������� ������
#define TEnd 100
// ��������� ������
#define TErr 200
