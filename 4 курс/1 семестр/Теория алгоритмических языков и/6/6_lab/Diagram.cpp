#include "Diagram.h"

void Diagram::Programm()
{
	TypeLex l;
	int t, t1, uk1;

	uk1 = sc->GetUK();
	t = sc->Scan(l);

	while (t != TEnd)
	{
		t1 = sc->Scan(l);
		sc->PutUK(uk1);
		if (t == TClass) Class();
		else if (t == TInt && t1 == TMain) Main();
		else Dannie();

		uk1 = sc->GetUK(); t = sc->Scan(l);
	}
}

void Diagram::Class()
{
	TypeLex l;
	int t, uk1;

	t = sc->Scan(l);
	if (t != TClass) sc->PrintError("�������� class (�� �����)", l);
	t = sc->Scan(l);
	if (t != TIdent) sc->PrintError("�������� ������������� (�� �����)", l);
	t = sc->Scan(l);
	if (t != TLeftSquareBracket) sc->PrintError("��������  \'{\'` (�� �����)", l);

	uk1 = sc->GetUK();
	t = sc->Scan(l);

	while (t != TRightSquareBracket)
	{
		sc->PutUK(uk1);
		Dannie();
		uk1 = sc->GetUK();
		t = sc->Scan(l);
	}
	t = sc->Scan(l);
	if (t != TSemicolon) sc->PrintError("�������� \';\' (�� �����)", l);
}

void Diagram::Main()
{
	TypeLex l;
	int t;
	t = sc->Scan(l);

	if (t != TInt) sc->PrintError("�������� int (�� ����)", l);
	t = sc->Scan(l);
	if (t != TMain) sc->PrintError("�������� main (�� ����)", l);
	t = sc->Scan(l);
	if (t != TLeftBracket) sc->PrintError("�������� \'(\' (�� ����)", l);
	t = sc->Scan(l);
	if (t != TRightBracket) sc->PrintError("�������� \')\' (�� ����)", l);
	SostOperator();
}

void Diagram::Dannie()
{
	TypeLex l;
	int t, uk1;
	uk1 = sc->GetUK(); t = sc->Scan(l);

	if (t != TConst) sc->PutUK(uk1);
	t = sc->Scan(l);
	if (t == TShort ) {
		t = sc->Scan(l);
		if (t != TInt) sc->PrintError("�������� int (�� ������)", l);

	}
	if (t != TInt && t != TDouble && t != TIdent) sc->PrintError("(�� ������) �������� ��� ��� ������������� � ��������", l);

	do {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("�������� ������������� (�� ������)", l);
		uk1 = sc->GetUK();
		t = sc->Scan(l);

		if (t == TSave) {
			Viraj();
			t = sc->Scan(l);
		}
	} while (t == TComma);

	if (t != TSemicolon) sc->PrintError("�������� \';\' (�� ������)", l);
}


void Diagram::Operator()
{
	TypeLex l;
	int t, uk1;

	uk1 = sc->GetUK();
	t = sc->Scan(l);

	if (t == TLeftSquareBracket || t == TWhile || t == TDo) {
		sc->PutUK(uk1);
		if (t == TLeftSquareBracket) SostOperator();
		if (t == TDo) Do();
		if (t == TWhile) While();

	}
	else {
		if (t == TIdent) {
			sc->PutUK(uk1);
			Prisvaivanie();
			t = sc->Scan(l);
		}
		if (t == TReturn) {
			Viraj();
			t = sc->Scan(l);
		}

		if (t != TSemicolon) sc->PrintError("�������� \';\' (�� ��������)", l);
	}
}

void Diagram::SostOperator()
{
	TypeLex l;
	int t, t1, uk1;

	t = sc->Scan(l);
	if (t != TLeftSquareBracket) sc->PrintError("�������� \'{\' (�� ��������� ��������)", l);

	uk1 = sc->GetUK();
	t = sc->Scan(l);
	t1 = sc->Scan(l);
	sc->PutUK(uk1);
	while (t != TRightSquareBracket)
	{
		if (t == TConst || t == TShort ||
			t == TInt ||t == TDouble || (t == TIdent && t1 == TIdent)) Dannie();
		else Operator();
		uk1 = sc->GetUK(); t = sc->Scan(l); t1 = sc->Scan(l); sc->PutUK(uk1);
	}
	t = sc->Scan(l);
}

void Diagram::Do()
{
	TypeLex l;
	int t, uk1;


	t = sc->Scan(l);

	if (t != TDo) sc->PrintError("�������� do ", l);
	t = sc->Scan(l);
	if (t != TLeftSquareBracket) sc->PrintError("�������� \'{\'", l);
	Operator();
	t = sc->Scan(l);
	if (t != TRightSquareBracket) sc->PrintError("�������� \'}\'", l);
	Operator();
}

void Diagram::While()
{
	TypeLex l;
	int t, uk1;


	t = sc->Scan(l);

	if (t != TWhile) sc->PrintError("�������� while ", l);
	t = sc->Scan(l);
	if (t != TLeftBracket) sc->PrintError("�������� \'(\'", l);
	Viraj();
	t = sc->Scan(l);
	if (t != TRightBracket) sc->PrintError("�������� \')\'", l);
	Operator();
}

void Diagram::Prisvaivanie()
{
	TypeLex l;
	int t, t1;
	t = sc->Scan(l);

	if (t != TIdent) sc->PrintError("�������� ������������� (�� ������������)", l);
	t = sc->Scan(l);
	while (t == TDot) {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("�������� ������������� (�� ������������)", l);
		t = sc->Scan(l);
	}
	if (t < TPlusEqual || t >TSave) {
		sc->PrintError("�������� ���� != ���� = (�� ������������)", l);
	}
	Viraj();
}

void Diagram::Viraj()
{
	TypeLex l;
	int t, uk1;
	Sravnenie();
	uk1 = sc->GetUK(); t = sc->Scan(l);
	while ((t == TLeftShift || (t == TRightShift))) {
		Sravnenie();
		uk1 = sc->GetUK(); t = sc->Scan(l);
	}
	sc->PutUK(uk1);
}


void Diagram::Sravnenie()
{
	TypeLex l;
	int t, uk1;
	Sdvig();
	uk1 = sc->GetUK(); t = sc->Scan(l);
	while ((t >= TLess) && (t <= TOperatorEqvivalentnosti)) {
		Sdvig();
		uk1 = sc->GetUK(); t = sc->Scan(l);
	}
	sc->PutUK(uk1);
}

void Diagram::Sdvig()
{
	TypeLex l;
	int t, uk1;
	Slagaemoe();
	uk1 = sc->GetUK(); t = sc->Scan(l);
	while ((t == TLeftShift) || (t == TRightShift)) {
		Slagaemoe();
		uk1 = sc->GetUK(); t = sc->Scan(l);
	}
	sc->PutUK(uk1);
}

void Diagram::Slagaemoe()
{
	TypeLex l;
	int t, uk1;
	Mnojitel();
	uk1 = sc->GetUK(); t = sc->Scan(l);
	while ((t == TPlus) || (t == TMinus)) {
		Mnojitel();
		uk1 = sc->GetUK(); t = sc->Scan(l);
	}
	sc->PutUK(uk1);
}

void Diagram::Mnojitel()
{
	TypeLex l;
	int t, uk1;
	ElemViraj();
	uk1 = sc->GetUK(); t = sc->Scan(l);
	while ((t == TDiv) || (t == TMult) || (t == TMode)) {
		ElemViraj();
		uk1 = sc->GetUK(); t = sc->Scan(l);
	}
	sc->PutUK(uk1);
}


void Diagram::ElemViraj()
{
	TypeLex l;
	int t, uk1;

	t = sc->Scan(l);

	if ( t == TConstInt ) return;

	if (t == TLeftBracket) {
		Viraj();
		t = sc->Scan(l);
		if (t != TRightBracket) sc->PrintError("�������� ������ \')\' (�� ��.���������)", l);
		return;
	}

	if (t != TIdent) sc->PrintError("�������� ������������� (�� ��.���������)", l);

	uk1 = sc->GetUK();
	t = sc->Scan(l);
	while (t == TDot) {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("�������� ������������� (�� ��.���������)", l);
		uk1 = sc->GetUK();
		t = sc->Scan(l);
	}
	sc->PutUK(uk1);
}