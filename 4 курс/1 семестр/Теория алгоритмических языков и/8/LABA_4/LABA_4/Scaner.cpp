#include "Scaner.h"
Scaner::Scaner(const char* fileName) 
{
	FILE* file_ptr = fopen(fileName, "r");
	if (file_ptr == NULL)
	{
		scanf("Error while opening file");

		exit(1);
	}
	int i = 0;
	for (i = 0; !feof(file_ptr); i++)
	{
		if (i < MAX_TEXT)
		{
			fscanf(file_ptr, "%c", &im[i]);
			this->codeSize++;
		}
		else
		{
			scanf(" Error: The maximum length of the source module has been exceeded");
			break;
		}
	}

	im[--i] = '\0'; //end Code Segment
	this->uk = 0;
	fclose(file_ptr);
}
// Ключевые слова
TypeLEX Keyword[MAX_KEYW] = {
	"float",		"char",		"do",
	"while",		"const",		"main",
	"void" ,		"int",		"string"
};
// Типы ключевых слов
int TypeKeyword[MAX_KEYW] = {
	Tfloat,		TConstChar,		TDo,
	Twhile,		TConst,		TMain,
	TVoid,		TConstInt, TConstString
};
int Scaner::codeScaner(TypeLEX lexic)
{
	
	int legth_lex;
	for (legth_lex = 0; legth_lex < MAX_LEX; legth_lex++)
		lexic[legth_lex] = 0;
	legth_lex = 0;


start:
	/*Пропуск*/
	while ((im[uk] == ' ')
		|| (im[uk] == '\n')
		|| (im[uk] == '\t'))
		uk++;
 	if (im[uk] == '/'&& im[uk + 1] == '/')
	{
		while (im[uk] != '\n') uk++;
		goto start;
	}
	if (im[uk] == '\0')
	{
		lexic[0] = '#';
		return TEnd;
	}

	// ЦЕЛОЕ ДЕСЯТИЧНОЕ ЧИСЛО
	 if ((im[uk] >= '1') && (im[uk] <= '9')) {
		while ((im[uk] >= '0') && (im[uk] <= '9')) {
			lexic[legth_lex++] = im[uk++];
		}
		return TConstInt;
	}
	 // ЧИСЛО ТИПА FLOAT
	 else if ((im[uk] >= '0') && (im[uk] <= '9')) {
			 while (((im[uk] >= '0') && (im[uk] <= '9')) || (im[uk] == '.')) {
				 lexic[legth_lex++] = im[uk++];
			 }
			 return Tfloat;
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
				lexic[legth_lex++] = im[uk++];
			}
			else {
				uk++;
			}
			// проверка на ключевое слово
			for (int index_key = 0; index_key < MAX_KEYW; index_key++) {
				if (strcmp(lexic, Keyword[index_key]) == 0) {
					return TypeKeyword[index_key];
				}
			}
		}
		return TIdent;
	}
	else if (im[uk] == '\'' && im[uk + 2] >= '\'') {
		 for (int i = 0; i < 3; i++) {
			 lexic[legth_lex++] = im[uk++];
		 }
		 return TConstChar;
	 }
	else if (im[uk] == '\"') 
	 {
		 for (int i = 0; ; i++)
		 {
			 lexic[legth_lex++] = im[uk++];

			 if (im[uk] == '\"')
			 {
				 lexic[legth_lex++] = im[uk++];
				 return TConstString;
				 break;
			 }
		 }
	 }
	 // СПЕЦИАЛЬНЫЕ ЗНАКИ
	else if (im[uk] == ';') { lexic[legth_lex++] = im[uk++]; return TSemiColon; }
	else if (im[uk] == ',') { lexic[legth_lex++] = im[uk++]; return TComma; }
	else if (im[uk] == '(') { lexic[legth_lex++] = im[uk++]; return TLeftBracket; }
	else if (im[uk] == ')') { lexic[legth_lex++] = im[uk++]; return TRightBracket; }
	else if (im[uk] == '{') { lexic[legth_lex++] = im[uk++]; return TLeftCurlyBracket; }
	else if (im[uk] == '}') { lexic[legth_lex++] = im[uk++]; return TRightCurlyBracket; }
	else if (im[uk] == '[') { lexic[legth_lex++] = im[uk++]; return TLeftSquareBracket; }
	else if (im[uk] == ']') {
		 lexic[legth_lex++] = im[uk++]; return TRightSquareBracket;
	 }
	 // ЗНАКИ ОПЕРАЦИЙ
	else if (im[uk] == '=') {
		 lexic[legth_lex++] = im[uk++];
		 if (im[uk] == '=') {
			 lexic[legth_lex++] = im[uk++];
			 return TEqual;
		 }
		 return TSave;
	 }
	else if (im[uk] == '<') {
		 lexic[legth_lex++] = im[uk++];
		 if (im[uk] == '=') {
			 lexic[legth_lex++] = im[uk++];
			 return TlessOrEqual;
		 }
		 return Tless;
	 }
	else if (im[uk] == '>') {
		 lexic[legth_lex++] = im[uk++];
		 if (im[uk] == '=') {
			 lexic[legth_lex++] = im[uk++];
			 return TGreatOrEqual;
		 }
		 return TGreat;
	 }
	else if (im[uk] == '+') { lexic[legth_lex++] = im[uk++]; return TPlus; }
	else if (im[uk] == '-') { lexic[legth_lex++] = im[uk++]; return TMinus; }
	else if (im[uk] == '*') { lexic[legth_lex++] = im[uk++]; return TMultiply; }
	else if (im[uk] == '/') { lexic[legth_lex++] = im[uk++]; return Tdivide; }
	else if (im[uk] == '%') { lexic[legth_lex++] = im[uk++]; return TMod; }
	else if ((im[uk] == '!') && (im[uk + 1] == '=')) {
		 lexic[legth_lex++] = im[uk++];
		 lexic[legth_lex++] = im[uk++];
		 return TNotEqual;
	 }

	while ((im[uk] != ' ') && (im[uk] != '\n') && (im[uk] != '\t')
		&& im[uk] != '/' && im[uk + 1] != '/')
		lexic[legth_lex++] = im[uk++];
	return TError;
}

void Scaner::getData()
{
	for (int i = 0; i < this->codeSize; i++) {
		std::cout << im[i] << "";
	}
	std::cout << std::endl;
}

int Scaner::getUk()
{
	return this-> uk;
}

void Scaner::setUk(int i)
{
	this->uk = i;
}

void Scaner::PrintError(std::string err, std::string lex)
{
	int line = 1;
	int pos = 0;
	for (int i = 0; i < uk; i++) {
		if (im[i] != '\t')
			pos++;
		if (im[i] == '\n') {
			line++;
			pos = 0;
		}
	}
	pos -= lex.size() - 1;
	// выдать сообщение об ошибке
	if (lex[0] == 0)
		std::cout << "Стоп!\nОшибочка!: " << err << "    (В строке " << line << " и позиции " << pos << ')' << std::endl;
	else
		std::cout << "Стоп!\nНепонятный символ: \'" << lex << "\' Ошибочка!: " << err << "    (В строке " << line << " и позиции " << pos << ')' << std::endl;

	exit(0);
}
