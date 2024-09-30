#include "TScaner.h"

void TScaner::PError(const char* message, const char* error) {
	int error_uk = uk;
	printf(" # ОШИБКА\n");
	printf(" Строка: ");
	for (uk = row_uk; im[uk] != '\n' && im[uk] != '\0'; uk++)
		printf("%c", im[uk]);
	printf("\n Символ #%d: %s\n", error_uk - row_uk, error);
	printf(" Пояснение: %s\n", message);
	exit(0);
}

void TScaner::GetData(const char* FileName) {
	FILE* filestream = fopen(FileName, "r");	// Открыть файл для чтения
	if (filestream == NULL) {
		printf("Отсутствует входной файл");
		exit(1);
	}
	int i = 0;
	for (i = 0; !feof(filestream); i++) {
		if (i < MAX_TEXT) {
			fscanf(filestream, "%c", &im[i]);
		}
		else {
			printf("Превышина максимальная длинна исходного модуля");
			break;
		}
	}
	im[--i] = '\0';
}

bool TScaner::SetUK(int pos) {
	if (pos >= 0 && pos <= MAX_TEXT - 1) {
		uk = pos;
		return 1;
	}
	return 0;
}
int TScaner::GetUK() {
	return uk;
}

TScaner::TScaner(const char* FileName) {
	GetData(FileName);
	uk = 0;
	row_uk = 0;
}

// Ключевые слова
TypeLEX Keyword[MAX_KEYW] = {
	"if",		"else",		"void",
	"main",		"int",		"__int64",
	"long",		"short",	"char",
};
// Типы ключевых слов
int TypeKeyword[MAX_KEYW] = {
	TIf,		TElse,		TVoid,
	TMain,		TInt,		TInt64,
	TLong,		TShort,		TChar,
};

int TScaner::Scan(TypeLEX lex) {
	int legth_lex = 0;
	for (legth_lex = 0; legth_lex < MAX_LEX; lex[legth_lex++] = 0);
	legth_lex = 0;

start:
	// ПРОПУСК НЕЗНАЧАЩИХ ЭЛЕМЕНТОВ
	while ((im[uk] == ' ')
		|| (im[uk] == '\n')
		|| (im[uk] == '\t')) {
		if (im[uk] == '\n') {
			row_uk = uk + 1;
		}
		uk++;
	}
	if ((im[uk] == '/') && (im[uk + 1] == '/')) {
		while (im[uk] != '\n') uk++;
		goto start;
	}
	if (im[uk] == '\0') {
		lex[0] = '#';
		return TEnd;
	}

	// ЦЕЛОЕ ШЕСТНАДЦАТИРИЧНОЕ ЧИСЛО
	if ((im[uk] == '0')
		&& ((im[uk + 1] == 'x') || (im[uk + 1] == 'X'))) {
		// Запись 0x или 0X
		lex[legth_lex++] = im[uk++];
		lex[legth_lex++] = im[uk++];

		while ((im[uk] >= '0') && (im[uk] <= '9') 
			|| (im[uk] >= 'A') && (im[uk] <= 'F') 
			|| (im[uk] >= 'a') && (im[uk] <= 'f')) {
			lex[legth_lex++] = im[uk++];
		}
		return THexInt;
	}

	// ЦЕЛОЕ ДЕСЯТИЧНОЕ ЧИСЛО
	else if ((im[uk] >= '0') && (im[uk] <= '9')) {
		while ((im[uk] >= '0') && (im[uk] <= '9')) {
			lex[legth_lex++] = im[uk++];
		}
		return TDecInt;
	}
	// ИДЕНТИФИКАТОР
	else if ((im[uk] >= 'a') && (im[uk] <= 'z')
		|| (im[uk] >= 'A') && (im[uk] <= 'Z')
		|| (im[uk] == '_') && (im[uk + 1] == '_') && (im[uk + 2] != '_')) {
		while ((im[uk] >= 'a') && (im[uk] <= 'z')
			|| (im[uk] >= 'A') && (im[uk] <= 'Z')
			|| (im[uk] == '_')
			|| (im[uk] >= '0') && (im[uk] <= '9')) {
			// Обрезаем длинный индентификатор
			if (legth_lex < MAX_LEX - 1) {
				lex[legth_lex++] = im[uk++];
			}
			else {
				uk++;
			}
		}
		// проверка на ключевое слово
		for (int index_key = 0; index_key < MAX_KEYW; index_key++) {
			if (strcmp(lex, Keyword[index_key]) == 0) {
				return TypeKeyword[index_key];
			}
		}
		return TIdent;
	}
	else if (im[uk] == '\'' && im[uk + 2] >= '\'') {
		for (int i = 0; i < 3; i++) {
			lex[legth_lex++] = im[uk++];
		}
		return TConstChar;
	}
	// СПЕЦИАЛЬНЫЕ ЗНАКИ
	else if (im[uk] == ';') { lex[legth_lex++] = im[uk++]; return TTZpt; }
	else if (im[uk] == ',') { lex[legth_lex++] = im[uk++]; return TZpt; }
	else if (im[uk] == '(') { lex[legth_lex++] = im[uk++]; return TLS; }
	else if (im[uk] == ')') { lex[legth_lex++] = im[uk++]; return TPS; }
	else if (im[uk] == '{') { lex[legth_lex++] = im[uk++]; return TFLS; }
	else if (im[uk] == '}') { lex[legth_lex++] = im[uk++]; return TFPS; }
	else if (im[uk] == '[') { lex[legth_lex++] = im[uk++]; return TSLS; }
	else if (im[uk] == ']') { lex[legth_lex++] = im[uk++]; return TSPS; 
	}
	// ЗНАКИ ОПЕРАЦИЙ
	else if (im[uk] == '=') { 
		lex[legth_lex++] = im[uk++]; 
		if (im[uk] == '=') {
			lex[legth_lex++] = im[uk++];
			return TEQ;
		}
		return TSave;
	}
	else if (im[uk] == '<') {
		lex[legth_lex++] = im[uk++];
		if (im[uk] == '=') {
			lex[legth_lex++] = im[uk++];
			return TLE;
		}
		return TLT;
	}
	else if (im[uk] == '>') {
		lex[legth_lex++] = im[uk++];
		if (im[uk] == '=') {
			lex[legth_lex++] = im[uk++];
			return TGE;
		}
		return TGT;
	}
	else if (im[uk] == '+') { lex[legth_lex++] = im[uk++]; return TPlus; }
	else if (im[uk] == '-') { lex[legth_lex++] = im[uk++]; return TMinus; }
	else if (im[uk] == '*') { lex[legth_lex++] = im[uk++]; return TMult; }
	else if (im[uk] == '/') { lex[legth_lex++] = im[uk++]; return TDiv; }
	else if (im[uk] == '%') { lex[legth_lex++] = im[uk++]; return TMod; }
	else if ((im[uk] == '!') && (im[uk + 1] == '=')) { 
		lex[legth_lex++] = im[uk++]; 
		lex[legth_lex++] = im[uk++]; 
		return TNEQ;
	}
	while((im[uk] != ' ') && (im[uk] != '\n') && (im[uk] != '\t')
		&& im[uk] != '/' && im[uk + 1] != '/')
		lex[legth_lex++] = im[uk++];
	return TErr;
}