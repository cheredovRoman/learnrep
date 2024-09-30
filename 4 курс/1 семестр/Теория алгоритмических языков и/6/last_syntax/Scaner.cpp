#include "Scaner.h"

Scaner::Scaner(FILE* fileName) {
	GetData(fileName);
	PutUK(0);
}

TypeLex Keyword[MAX_KEYW] = {
	"const", "class", "main", "int",
	"short", "long", "float",  "return","while"
};
int IndexKeyword[MAX_KEYW] = {
	TConst, TClass, TMain, TInt,
	TShort, TLong, TFloat, TReturn,TWhile
};

void Scaner::PutUK(int i) {
	uk = i;
}

int Scaner::GetUK() {
	return uk;
}

void Scaner::PrintError(string err, string lex) {
	int line = 1;
	int pos = 0;
	for (int i = 0; i < uk; i++) {
		if (t[i] != '\t')
			pos++;
		if (t[i] == '\n') {
			line++;
			pos = 0;
		}
	}
	pos -= lex.size() - 1;
	// ������ ��������� �� ������
	if (lex[0] == 0)
		cout << "����!\n��������!: " << err << "    (� ������ " << line << " � ������� " << pos << ')' << endl;
	else
		cout << "����!\n���������� ������: \'" << lex << "\' ��������!: " << err << "    (� ������ " << line << " � ������� " << pos << ')' << endl;

	exit(0);
}

int Scaner::Scan(TypeLex l) {
	int i; // ������� ����� �������
	for (i = 0; i < MAX_LEX; i++)
		l[i] = 0; //�������� ���� �������

	i = 0; // ������� ����������� � ������� I

start:

	// ���������� �� ��� ���� ������������ ���������:
	while ((t[uk] == ' ') || (t[uk] == '\n') || (t[uk] == '\t')) uk++;

	// ������� ���������� ���������
	if ((t[uk] == '/') && (t[uk + 1] == '/')) { // ������� �����������, ���� ���������� ����� �� '\n'
		uk = uk + 2;
		while (t[uk] != '\n' && t[uk] != '\0') uk++;
		goto start;
	}

	if (t[uk] == '\0') { l[0] = '#'; return TEnd; } // ����� ������

	// ��������� ���������
	if ((t[uk] <= '9') && (t[uk] >= '0'))
	{
		l[i++] = t[uk++];
		while ((t[uk] <= '9') && (t[uk] >= '0'))
			if (i < MAX_LEX - 1)
				l[i++] = t[uk++];
			else
				uk++;

		if (t[uk] == '.') {
			l[i++] = t[uk++];
			goto N1;
		}
		if ((t[uk] == 'E') || (t[uk] == 'e')) {
			l[i++] = t[uk++];
			goto N2;
		}
		return TConstInt;
	}

	// ��������� �������������� � �������� ����
	else if ((t[uk] >= 'a') && (t[uk] <= 'z') ||
		(t[uk] >= 'A') && (t[uk] <= 'Z')) { // ���������� �������������

		l[i++] = t[uk++];
		while ((t[uk] <= '9') && (t[uk] >= '0') ||
			(t[uk] >= 'a') && (t[uk] <= 'z') ||
			(t[uk] >= 'A') && (t[uk] <= 'Z'))
			if (i < MAX_LEX - 1)
				l[i++] = t[uk++];
			else
				uk++;

		int j; // �������� �� �������� �����:
		for (j = 0; j < MAX_KEYW; j++) {
			if (strcmp(l, Keyword[j]) == 0)
				return IndexKeyword[j];
		}
		return TIdent;
	}

	// ��������� ����������� ������
	else if (t[uk] == '.') {
		l[i++] = t[uk++];
		if ((t[uk] <= '9') && (t[uk] >= '0')) {
			l[i++] = t[uk++];
			goto N1;
		}
		return TDot;
	}
	else if (t[uk] == ',') {
		l[i++] = t[uk++]; return TComma;
	}
	else if (t[uk] == ';') {
		l[i++] = t[uk++]; return TSemicolon;
	}
	else if (t[uk] == '(') {
		l[i++] = t[uk++]; return TLeftBracket;
	}
	else if (t[uk] == ')') {
		l[i++] = t[uk++]; return TRightBracket;
	}
	else if (t[uk] == '{') {
		l[i++] = t[uk++]; return TLeftSquareBracket;
	}
	else if (t[uk] == '}') {
		l[i++] = t[uk++]; return TRightSquareBracket;
	}

	// ��������� ������ ��������
	else if (t[uk] == '~') {
		l[i++] = t[uk++]; 
		PrintError("�� �������������� ������", l);
		return TErr;
	}
	else if (t[uk] == '<') {
		l[i++] = t[uk++];

		if (t[uk] == '=' && t[uk + 1] == '>') {
			l[i++] = t[uk++];
			l[i++] = t[uk++];
			return TOperatorEqvivalentnosti;
		}
		else if (t[uk] == '=') {
			l[i++] = t[uk++];
			return TLessOrEqual;
		}
		else if (t[uk] == '<') {
			l[i++] = t[uk++];
			return TLeftShift;
		}
		return TLess;
	}
	else if (t[uk] == '>') {
		l[i++] = t[uk++];

		
		if (t[uk] == '=') {
			l[i++] = t[uk++];
			return TGreatOrEqual;
		}
		else if (t[uk] == '>') {
			l[i++] = t[uk++];
			return TRightShift;
		}
		return TMore;
	}
	else if (t[uk] == '=') {
		l[i++] = t[uk++];

		if (t[uk] == '=') {
			l[i++] = t[uk++];
			return TEqual;
		}
		return TSave;
	}
	else if (t[uk] == '!' && t[uk + 1] == '=') {
		l[i++] = t[uk++];
		l[i++] = t[uk++];

		return TNotEqual;
	}
	else if (t[uk] == '+') {
		l[i++] = t[uk++];

		if (t[uk] == '=') {
			l[i++] = t[uk++];
			return TPlusEqual;
		}
		
		return TPlus;
	}
	else if (t[uk] == '-') {
		l[i++] = t[uk++];

		if (t[uk] == '=') {
			l[i++] = t[uk++];
			return TMinusEqual;
		}
		return TMinus;
	}
	else if (t[uk] == '*') {
		l[i++] = t[uk++];

		if (t[uk] == '=') {
			l[i++] = t[uk++];
			return TMultEqual;
		}
		return TMult;
	}
	else if (t[uk] == '/') {
		l[i++] = t[uk++];

		if (t[uk] == '=') {
			l[i++] = t[uk++];
			return TDivEqual;
		}
		return TDiv;
	}
	else if (t[uk] == '%') {
		l[i++] = t[uk++];

		if (t[uk] == '=') {
			l[i++] = t[uk++];
			return TModeEqual;
		}
		return TMode;
	}
	else if (t[uk] == '&') {
		l[i++] = t[uk++];

		PrintError("�� �������������� ������", l);
		return TErr;
	}
	else if (t[uk] == '^') {
		l[i++] = t[uk++];

		PrintError("�� �������������� ������", l);
		return TErr;
	}
	else if (t[uk] == '|') {
		l[i++] = t[uk++];

		PrintError("�� �������������� ������", l);
		return TErr;
	}
	else {
		l[i++] = t[uk++];

		PrintError("�� �������������� ������", l);
		return TErr;
	}

N1: // ����������� �������� ��������� ����� �����
	while ((t[uk] <= '9') && (t[uk] >= '0'))
		if (i < MAX_LEX - 1)
			l[i++] = t[uk++];
		else
			uk++;
	if ((t[uk] == 'e') || (t[uk] == 'E')) {
		l[i++] = t[uk++];
		goto N2;
	}
	
	return TConstFloat;

N2: // ����������� �������� ��������� ����� "E"
	if ((t[uk] == '+') || (t[uk] == '-'))
	{
		l[i++] = t[uk++];
		if ((t[uk] <= '9') && (t[uk] >= '0')) {
			if (i < MAX_LEX - 1)
				l[i++] = t[uk++];
			else
				uk++;
			goto N3;
		}
		else {
			PrintError("�������� ���������", l); // ������
			return TErr;
		}
	}
N3: // ����������� ������� �������� ���������
	while ((t[uk] <= '9') && (t[uk] >= '0'))
		if (i < MAX_LEX - 1)
			l[i++] = t[uk++];
		else
			uk++;
	return TConstExp;
}

void Scaner::GetData(FILE* in) {
	if (in == NULL) {
		PrintError("����������� ������� ����", "");
		exit(1);
	}
	char aa;
	int i = 0;
	while (!feof(in))
	{
		fscanf(in, "%c", &aa);

		if (!feof(in))
			t[i++] = aa;

		if (i >= MAX_TEXT - 1) {
			PrintError("������� ������� ������ ��������� ������", "");
			break;
		}
	}

	t[i] = '\0'; // ����������� ���� '\0'� ����� ������

	fclose(in);
}