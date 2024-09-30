#pragma once
#ifndef DEFS_H
#define DEFS_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define MAX_TEXT	10000	// Максимальная длина текста
#define MAX_LEX		100		// Максимальная длинна лексемы
#define MAX_KEYW	9

typedef char TypeLEX[MAX_LEX];	// Тип лексемы
typedef char TypeIM[MAX_TEXT];	// Тип исходного модуля
//Ключевые слова
#define Tfloat 1
#define TDo 3
#define Twhile 4
#define TConst 5
#define TMain 6
#define TVoid	7

//Константы & идентификаторы
#define TIdent 10
#define TConstString 9
#define TConstChar 2
#define TConstInt 8

//Специальные знаки
#define TDot 30
#define TSemiColon 31
#define TComma 32
#define TLeftBracket 35
#define TRightBracket 36
#define TLeftCurlyBracket 37
#define TRightCurlyBracket 38
#define TLeftSquareBracket 39
#define TRightSquareBracket 40
//Знаки операций
#define TPlus 50
#define TMinus 51
#define TMultiply 52
#define Tdivide 53
#define TMod 54
#define TSave 55
#define TEqual 56
#define Tless 57
#define TlessOrEqual 58
#define TGreat 59
#define TGreatOrEqual 60
#define TNotEqual 61
#define TIncrement 62
#define TDecrement 63
//Дополнительные знаки
#define TError 100
#define TEnd 200

#endif // !1
