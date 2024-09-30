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
#define MAX_KEYW	9

typedef char TypeLEX[MAX_LEX];	// Тип лексемы
typedef char TypeIM[MAX_TEXT];	// Тип исходного модуля

// Ключевые слова
#define TIf		1
#define TElse	2
#define TMain	3
#define TInt	4
#define TInt64	5
#define TLong	6
#define TShort	7
#define TChar	8
#define TVoid	9
// Идентификаторы и констаны
#define TIdent		60
#define TDecInt		61
#define THexInt		62
#define TConstChar	63
// Специальные знаки
#define TTZpt	90
#define TZpt	91
#define TLS		92
#define TPS		93
#define TFLS	94
#define TFPS	95
#define TSLS	96
#define TSPS	97
// Знаки операций
#define TEQ		120
#define TNEQ	121
#define TLE		122
#define TGE		123
#define TLT		124
#define TGT		125
#define TPlus	126
#define TMinus	127
#define TMult	128
#define TDiv	129
#define TMod	130
#define TSave	131
// Конец исходного модуля
#define TEnd	200
// Ошибочный символ
#define TErr	300

#endif // __DEFS
