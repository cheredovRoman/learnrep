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
	if (t != TClass) sc->PrintError("ОЖИДАЛСЯ class (СД КЛАСС)", l);
	t = sc->Scan(l);
	if (t != TIdent) sc->PrintError("ОЖИДАЛСЯ ИДЕНТИФИКАТОР (СД КЛАСС)", l);
	t = sc->Scan(l);
	if (t != TLeftSquareBracket) sc->PrintError("ОЖИДАЛСЯ  \'{\'` (СД КЛАСС)", l);

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
	if (t != TSemicolon) sc->PrintError("ОЖИДАЛСЯ \';\' (СД КЛАСС)", l);
}

void Diagram::Main()
{
	TypeLex l;
	int t;
	t = sc->Scan(l);

	if (t != TInt) sc->PrintError("ОЖИДАЛСЯ int (СД МЕЙН)", l);
	t = sc->Scan(l);
	if (t != TMain) sc->PrintError("ОЖИДАЛСЯ main (СД МЕЙН)", l);
	t = sc->Scan(l);
	if (t != TLeftBracket) sc->PrintError("ОЖИДАЛСЯ \'(\' (СД МЕЙН)", l);
	t = sc->Scan(l);
	if (t != TRightBracket) sc->PrintError("ОЖИДАЛСЯ \')\' (СД МЕЙН)", l);
	SostOperator();
}

void Diagram::Dannie()
{
	TypeLex l;
	int t, uk1;
	uk1 = sc->GetUK(); t = sc->Scan(l);

	if (t != TConst) sc->PutUK(uk1);
	t = sc->Scan(l);
	if (t == TShort || t == TLong) {
		t = sc->Scan(l);
		if (t != TInt) sc->PrintError("ОЖИДАЛСЯ int (СД ДАННЫЕ)", l);

	}
	if (t != TInt && t != TFloat && t != TIdent) sc->PrintError("(СД ДАННЫЕ) ОЖИДАЛСЯ ТИП ИЛИ ИДЕНТИФИКАТОР А ПОЛУЧИЛИ", l);

	do {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("ОЖИДАЛСЯ ИДЕНТИФИКАТОР (СД ДАННЫЕ)", l);
		uk1 = sc->GetUK();
		t = sc->Scan(l);

		if (t == TSave) {
			Viraj();
			t = sc->Scan(l);
		}
	} while (t == TComma);

	if (t != TSemicolon) sc->PrintError("ОЖИДАЛСЯ \';\' (СД ДАННЫЕ)", l);
}


void Diagram::Operator()
{
	TypeLex l;
	int t, uk1;

	uk1 = sc->GetUK();
	t = sc->Scan(l);

	if (t == TLeftSquareBracket || t == TWhile) {
		sc->PutUK(uk1);
		if (t == TLeftSquareBracket) SostOperator();
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

		if (t != TSemicolon) sc->PrintError("ОЖИДАЛСЯ \';\' (СД ОПЕРАТОР)", l);
	}
}

void Diagram::SostOperator()
{
	TypeLex l;
	int t, t1, uk1;

	t = sc->Scan(l);
	if (t != TLeftSquareBracket) sc->PrintError("ОЖИДАЛСЯ \'{\' (СД СОСТАВНОЙ ОПЕРАТОР)", l);

	uk1 = sc->GetUK();
	t = sc->Scan(l);
	t1 = sc->Scan(l);
	sc->PutUK(uk1);
	while (t != TRightSquareBracket)
	{
		if (t == TConst || t == TShort ||
			t == TLong || t == TInt ||
			t == TFloat || (t == TIdent && t1 == TIdent)) Dannie();
		else Operator();
		uk1 = sc->GetUK(); t = sc->Scan(l); t1 = sc->Scan(l); sc->PutUK(uk1);
	}
	t = sc->Scan(l);
}

void Diagram::While()
{
	TypeLex l;
	int t, uk1;


	t = sc->Scan(l);

	if (t != TWhile) sc->PrintError("ОЖИДАЛСЯ while ", l);
	t = sc->Scan(l);
	if (t != TLeftBracket) sc->PrintError("ОЖИДАЛСЯ \'(\'", l);
	Viraj();
	t = sc->Scan(l);
	if (t != TRightBracket) sc->PrintError("ОЖИДАЛСЯ \')\'", l);
	Operator();
}

void Diagram::Prisvaivanie()
{
	TypeLex l;
	int t, t1;
	t = sc->Scan(l);

	if (t != TIdent) sc->PrintError("ОЖИДАЛСЯ ИДЕНТИФИКАТОР (СД ПРИСВАИВАНИЕ)", l);
	t = sc->Scan(l);
	while (t == TDot) {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("ОЖИДАЛСЯ идентификатор (СД ПРИСВАИВАНИЕ)", l);
		t = sc->Scan(l);
	}
	if (t < TPlusEqual || t >TSave) {
		sc->PrintError("Ожидался либо != либо = (СД ПРИСВАИВАНИЕ)", l);
	}
	Viraj();
}

void Diagram::Viraj()
{
	TypeLex l;
	int t, uk1;
	Sravnenie();
	uk1 = sc->GetUK(); t = sc->Scan(l);
	while ((t == TLeftShift || (t == TRightShift))){
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

	if (t == TConstExp || t == TConstInt || t==TConstFloat) return;

	if (t == TLeftBracket) {
		Viraj();
		t = sc->Scan(l);
		if (t != TRightBracket) sc->PrintError("ожидался символ \')\' (СД ЭЛ.ВЫРАЖЕНИЕ)", l);
		return;
	}

	if (t != TIdent) sc->PrintError("ожидался идентификатор (СД ЭЛ.ВЫРАЖЕНИЕ)", l);

	uk1 = sc->GetUK();
	t = sc->Scan(l);
	while (t == TDot) {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("Ожидался идентификатор (СД ЭЛ.ВЫРАЖЕНИЕ)", l);
		uk1 = sc->GetUK();
		t = sc->Scan(l);
	}
	sc->PutUK(uk1);
}