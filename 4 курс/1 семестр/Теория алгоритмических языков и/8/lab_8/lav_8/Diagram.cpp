#include "Diagram.h"
#include "Semant.h"
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
	if (t != TClass) sc->PrintError("ÎÆÈÄÀËÑß class (ÑÄ ÊËÀÑÑ)", l);
	t = sc->Scan(l);
	if (t != TIdent) sc->PrintError("ÎÆÈÄÀËÑß ÈÄÅÍÒÈÔÈÊÀÒÎÐ (ÑÄ ÊËÀÑÑ)", l);
	Tree* v = Root->SemInclude(l, ObjTypeClass, UndefinedType, false);
	t = sc->Scan(l);
	if (t != TLeftSquareBracket) sc->PrintError("ÎÆÈÄÀËÑß  \'{\'` (ÑÄ ÊËÀÑÑ)", l);

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
	if (t != TSemicolon) sc->PrintError("ÎÆÈÄÀËÑß \';\' (ÑÄ ÊËÀÑÑ)", l);
	Root->SetCur(v);
}

void Diagram::Main()
{
	TypeLex l;
	int t;
	t = sc->Scan(l);

	if (t != TInt) sc->PrintError("ÎÆÈÄÀËÑß int (ÑÄ ÌÅÉÍ)", l);
	t = sc->Scan(l);
	if (t != TMain) sc->PrintError("ÎÆÈÄÀËÑß main (ÑÄ ÌÅÉÍ)", l);
	t = sc->Scan(l);
	if (t != TLeftBracket) sc->PrintError("ÎÆÈÄÀËÑß \'(\' (ÑÄ ÌÅÉÍ)", l);
	t = sc->Scan(l);
	if (t != TRightBracket) sc->PrintError("ÎÆÈÄÀËÑß \')\' (ÑÄ ÌÅÉÍ)", l);
	Tree* v = Root->SemInclude((char*)"main", ObjMain, IntegerType, false);
	SostOperator();
	Root->SetCur(v);
}

void Diagram::Dannie()
{
	TypeLex l;
	int t, uk1;

	TypeObject tob = ObjEmpty;
	PrimitiveDataType tda = UndefinedType;
	bool itConst = false;

	uk1 = sc->GetUK(); t = sc->Scan(l);

	if (t != TIdent) {
		if (t != TConst)
			sc->PutUK(uk1);
		else
			itConst = true;

		t = sc->Scan(l);
		if (t == TShort ) {
			if (t == TShort)
				tda = ShortType;
			t = sc->Scan(l);
			if (t != TInt) sc->PrintError("Îæèäàëñÿ int (ÑÄ ÄÀÍÍÛÅ)", l);
		}

		if (t != TInt && t != TDouble) sc->PrintError("Îæèäàëñÿ int/float (ÑÄ ÄÀÍÍÛÅ)", l);

		tob = ObjVar;
	}
	else
		tob = ObjClass;

	if (tda != ShortType)
		tda = Root->GetType(t);

	do {
		t = sc->Scan(l);

		if (t != TIdent) sc->PrintError("Îæèäàëñÿ èäåíòåôèêàòîð (ÑÄ ÄÀÍÍÛÅ)", l);

		Tree* v = Root->SemInclude(l, tob, tda, itConst);

		if (tda == UndefinedType) {
			Tree* cl = Root->SemGetType(l);
			v->SetRightT(cl->GetRight());
		}

		uk1 = sc->GetUK();
		t = sc->Scan(l);

		if (t == TSave) {
			Viraj();
			t = sc->Scan(l);
		}
	} while (t == TComma);

	if (t != TSemicolon) sc->PrintError("Îæèäàëñÿ ñèìâîë \';\' (ÑÄ ÄÀÍÍÛÅ)", l);
}

/*
void Diagram::Dannie()
{
	TypeLex l;
	int t, uk1;

	TypeObject tob = ObjEmpty;
	PrimitiveDataType tda = UndefinedType;
	bool itConst = false;


	uk1 = sc->GetUK(); t = sc->Scan(l);

	if (t != TConst)
	{
		sc->PutUK(uk1);
	}
	else {
			itConst = true;
	}
	t = sc->Scan(l);
	if (t == TShort || t == TLong) {
		if (t == TShort) {
			tda = ShortType;
		}
		t = sc->Scan(l);
		if (t != TInt) sc->PrintError("ÎÆÈÄÀËÑß int (ÑÄ ÄÀÍÍÛÅ)", l);

	}
	if (t != TInt && t != TFloat && t != TIdent) sc->PrintError("(ÑÄ ÄÀÍÍÛÅ) ÎÆÈÄÀËÑß ÒÈÏ ÈËÈ ÈÄÅÍÒÈÔÈÊÀÒÎÐ À ÏÎËÓ×ÈËÈ", l);
	tob = ObjVar;
	do {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("ÎÆÈÄÀËÑß ÈÄÅÍÒÈÔÈÊÀÒÎÐ (ÑÄ ÄÀÍÍÛÅ)", l);
		uk1 = sc->GetUK();
		t = sc->Scan(l);

		if (t == TSave) {
			Viraj();
			t = sc->Scan(l);
		}
	} while (t == TComma);

	if (t != TSemicolon) sc->PrintError("ÎÆÈÄÀËÑß \';\' (ÑÄ ÄÀÍÍÛÅ)", l);
}
*/


void Diagram::Operator()
{
	TypeLex l;
	int t, uk1;

	uk1 = sc->GetUK();
	t = sc->Scan(l);

	if (t == TLeftSquareBracket || t == TWhile || t == TDo) {
		sc->PutUK(uk1);
		if (t == TDo) Do();
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

		if (t != TSemicolon) sc->PrintError("ÎÆÈÄÀËÑß \';\' (ÑÄ ÎÏÅÐÀÒÎÐ)", l);
	}
}

void Diagram::SostOperator()
{
	TypeLex l;
	int t, t1, uk1;

	t = sc->Scan(l);
	if (t != TLeftSquareBracket) sc->PrintError("ÎÆÈÄÀËÑß \'{\' (ÑÄ ÑÎÑÒÀÂÍÎÉ ÎÏÅÐÀÒÎÐ)", l);

	uk1 = sc->GetUK();
	t = sc->Scan(l);
	t1 = sc->Scan(l);
	sc->PutUK(uk1);
	while (t != TRightSquareBracket)
	{
		if (t == TConst || t == TShort ||
			t == TDouble || t == TInt ||
			(t == TIdent && t1 == TIdent)) Dannie();
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

	if (t != TWhile) sc->PrintError("ÎÆÈÄÀËÑß while ", l);
	t = sc->Scan(l);
	if (t != TLeftBracket) sc->PrintError("ÎÆÈÄÀËÑß \'(\'", l);
	Viraj();
	t = sc->Scan(l);
	if (t != TRightBracket) sc->PrintError("ÎÆÈÄÀËÑß \')\'", l);
	Operator();
}
void Diagram::Do()
{
	TypeLex l;
	int t, uk1;


	t = sc->Scan(l);

	if (t != TDo) sc->PrintError("ÎÆÈÄÀËÑß do ", l);
	Operator();
}

void Diagram::Prisvaivanie()
{
	TypeLex l;
	int t, t1;
	t = sc->Scan(l);

	if (t != TIdent) sc->PrintError("ÎÆÈÄÀËÑß ÈÄÅÍÒÈÔÈÊÀÒÎÐ (ÑÄ ÏÐÈÑÂÀÈÂÀÍÈÅ)", l);
	t = sc->Scan(l);
	while (t == TDot) {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("ÎÆÈÄÀËÑß èäåíòèôèêàòîð (ÑÄ ÏÐÈÑÂÀÈÂÀÍÈÅ)", l);
		t = sc->Scan(l);
	}
	if (t < TPlusEqual || t >TSave) {
		sc->PrintError("Îæèäàëñÿ ëèáî != ëèáî = (ÑÄ ÏÐÈÑÂÀÈÂÀÍÈÅ)", l);
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
		if (t != TRightBracket) sc->PrintError("îæèäàëñÿ ñèìâîë \')\' (ÑÄ ÝË.ÂÛÐÀÆÅÍÈÅ)", l);
		return;
	}

	if (t != TIdent) sc->PrintError("îæèäàëñÿ èäåíòèôèêàòîð (ÑÄ ÝË.ÂÛÐÀÆÅÍÈÅ)", l);

	uk1 = sc->GetUK();
	t = sc->Scan(l);
	while (t == TDot) {
		t = sc->Scan(l);
		if (t != TIdent) sc->PrintError("Îæèäàëñÿ èäåíòèôèêàòîð (ÑÄ ÝË.ÂÛÐÀÆÅÍÈÅ)", l);
		uk1 = sc->GetUK();
		t = sc->Scan(l);
	}
	sc->PutUK(uk1);
}

void Diagram::Print() {
	Root->Print();
}
