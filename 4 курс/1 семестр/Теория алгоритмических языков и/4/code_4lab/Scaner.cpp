#include "Scaner.h"

void Scaner::GetData(const char* FileName) {
	FILE* filestream = fopen(FileName, "r");	// ������� ���� ��� ������
	if (filestream == NULL) {
		printf("����������� ������� ����");
		exit(1);
	}
	int i = 0;
	for (i = 0; !feof(filestream); i++) {
		if (i < MAX_TEXT) {
			fscanf(filestream, "%c", &im[i]);
		}
		else {
			printf("��������� ������������ ������ ��������� ������");
			break;
		}
	}
	im[--i] = '\0';
}

Scaner::Scaner(const char* FileName) {
	GetData(FileName);
	uk = 0;
}

// �������� �����
TypeLEX Keyword[MAX_KEYW] = {
	"short",	"double",	"int",
	"do",		"while",	"const",
	"main",		"return",	"class",
	"void",
};
// ���� �������� ����
int TypeKeyword[MAX_KEYW] = {
	TShort,		TDouble,	TInt,
	Tdo,		Twhile,		TConst,
	TMain,		TReturn,	TClass,
	TVoid,
};

int Scaner::Scan(TypeLEX lex) {
	int legth_lex = 0;
	for (legth_lex = 0; legth_lex < MAX_LEX; lex[legth_lex++] = 0);
	legth_lex = 0;

start:
	// ������� ���������� ���������
	while ((im[uk] == ' ')
		|| (im[uk] == '\n')
		|| (im[uk] == '\t'))
		uk++;
	if ((im[uk] == '/') && (im[uk + 1] == '/')) {
		while (im[uk] != '\n') uk++;
		goto start;
	}
	if (im[uk] == '\0') {
		lex[0] = '#';
		return TEnd;
	}

	// ����� ���������� �����
	 if ((im[uk] >= '0') && (im[uk] <= '9')) {
		while ((im[uk] >= '0') && (im[uk] <= '9')) {
			lex[legth_lex++] = im[uk++];
		}
		return TconstInt;
	}
	// �������������
	else if ((im[uk] >= 'a') && (im[uk] <= 'z')
		|| (im[uk] >= 'A') && (im[uk] <= 'Z')
		|| (im[uk] == '_') && (im[uk + 1] == '_') && (im[uk + 2] != '_')) {
		while ((im[uk] >= 'a') && (im[uk] <= 'z')
			|| (im[uk] >= 'A') && (im[uk] <= 'Z')
			|| (im[uk] == '_')
			|| (im[uk] >= '0') && (im[uk] <= '9')) {
			// �������� ������� ��������������
			if (legth_lex < MAX_LEX - 1) {
				lex[legth_lex++] = im[uk++];
			}
			else {
				uk++;
			}
			// �������� �� �������� �����
			for (int index_key = 0; index_key < MAX_KEYW; index_key++) {
				if (strcmp(lex, Keyword[index_key]) == 0) {
					return TypeKeyword[index_key];
				}
			}
		}
		return TIdent; 
	}
	// ����������� �����
	else if (im[uk] == '.') { lex[legth_lex++] = im[uk++]; return TDot; }
	else if (im[uk] == ',') { lex[legth_lex++] = im[uk++]; return TComma; }
	else if (im[uk] == '(') { lex[legth_lex++] = im[uk++]; return TLeftBracket; }
	else if (im[uk] == ')') { lex[legth_lex++] = im[uk++]; return TRightBracket; }
	else if (im[uk] == '{') { lex[legth_lex++] = im[uk++]; return TLeftSquareBracket; }
	else if (im[uk] == '}') { lex[legth_lex++] = im[uk++]; return TRightSquareBracket; }
	else if (im[uk] == ';') { lex[legth_lex++] = im[uk++]; return TSemiColon; }
	else if (im[uk] == ':') { lex[legth_lex++] = im[uk++]; return TColon; 
	}
	// ����� ��������
	else if (im[uk] == '=') { 
		lex[legth_lex++] = im[uk++]; 
		if (im[uk] == '=') {
			lex[legth_lex++] = im[uk++];
			return TEqual;
		}
		return TSave;
	}
	else if (im[uk] == '<') {
		lex[legth_lex++] = im[uk++];
		if (im[uk] == '=') {
			lex[legth_lex++] = im[uk++];
			return TLessOrEqual;
		}
		return TLess;
	}
	else if (im[uk] == '>') {
		lex[legth_lex++] = im[uk++];
		if (im[uk] == '=') {
			lex[legth_lex++] = im[uk++];
			return TGreatOrEqual;
		}
		return TGreat;
	}
	else if (im[uk] == '+') { lex[legth_lex++] = im[uk++]; return TPlus; }
	else if (im[uk] == '-') { lex[legth_lex++] = im[uk++]; return TMinus; }
	else if (im[uk] == '*') { lex[legth_lex++] = im[uk++]; return TMultiply; }
	else if (im[uk] == '/') { lex[legth_lex++] = im[uk++]; return TDivide; }
	else if (im[uk] == '%') { lex[legth_lex++] = im[uk++]; return TMod; }
	else if ((im[uk] == '!') && (im[uk + 1] == '=')) { 
		lex[legth_lex++] = im[uk++]; 
		lex[legth_lex++] = im[uk++]; 
		return TNotEqual;
	}
	while((im[uk] != ' ') && (im[uk] != '\n') && (im[uk] != '\t')
		&& im[uk] != '/' && im[uk + 1] != '/')
		lex[legth_lex++] = im[uk++];
	return TError;
}