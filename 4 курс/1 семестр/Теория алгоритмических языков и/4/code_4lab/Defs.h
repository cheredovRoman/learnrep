/*
Модуль Defs.h 
Общие типы данных и кароопределения
*/
#pragma once
#ifndef __DEFS
#define __DEFS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define MAX_TEXT	10000	// Максимальная длина текста
#define MAX_LEX		100		// Максимальная длинна лексемы
#define MAX_KEYW	10

typedef char TypeLEX[MAX_LEX];	// Тип лексемы
typedef char TypeIM[MAX_TEXT];	// Тип исходного модуля

// Ключевые слова
#define TShort	1
#define TDouble	2
#define TInt	3
#define Tdo		4
#define Twhile	5
#define TConst	6
#define TMain	7
#define TReturn	8
#define TClass	9
#define TVoid	10
// Идентификаторы и констаны
#define TIdent		20
#define TconstInt	30
// Специальные знаки
#define TDot	40
#define TSemiColon	41
#define TComma		42
#define TColon		43
#define TLeftBracket	44
#define TRightBracket 	45
#define TLeftSquareBracket	46
#define TRightSquareBracket	47
// Знаки операций
#define TPlus		50
#define TMinus	51
#define TMultiply		52
#define TDivide		53
#define TMod		54
#define TSave		55
#define TEqual	56
#define TLess	57
#define TLessOrEqual	58
#define TGreat	59
#define TGreatOrEqual	60
#define TLeftShift	61
#define TRightShift	62
#define TNotEqual	63
#define TIncrement	64
#define TDecrement	65
// Конец исходного модуля
#define TEnd	200
// Ошибочный символ
#define TError	100

#endif // __DEFS
