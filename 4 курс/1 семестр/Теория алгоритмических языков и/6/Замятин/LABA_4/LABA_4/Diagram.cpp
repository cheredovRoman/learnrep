#pragma once
#include "Diagram.h"

void Diagram::Programma()
{
	TypeLEX l;
	int t, uk1;
	int save_uk;				//������� � �������� ������. 
	uk1 = sc->getUk();
	do
	{

		save_uk = sc->getUk();
		t = sc->codeScaner(l);
		sc->setUk(save_uk);

		if (t == TVoid) Funkciya();
		else Dannie();

		//t = sc->codeScaner(l);
		//printf("lex: %s -> type: %d\n", l, t);
	} while (t!=TEnd);

}

void Diagram::Funkciya()
{
	TypeLEX l;
	int t, uk1;
	if (sc->codeScaner(l) != TVoid) sc->PrintError("�������� Void (�� �������)", l);
	t = sc->codeScaner(l);
	if (t!=TMain && t!=TIdent) sc->PrintError("�������� main ��� ������������� (�� �������)", l);
	t = sc->codeScaner(l);
	if (t != TLeftBracket) sc->PrintError("��������  \'(\'` (�� �������)", l);
	t = sc->codeScaner(l);
	if (t != TRightBracket) sc->PrintError("��������  \')\'` (�� �������)", l);
	SostOperator();
}
void Diagram::SostOperator()
{
	TypeLEX l;
	if (sc->codeScaner(l) != TLeftCurlyBracket) sc->PrintError("�������� \'{\'  (�� ��������� ��������)", l);

	int type;
	do
	{
		int save_uk = sc->getUk();
		type = sc->codeScaner(l);
		if (type == TIdent || type == TDo || type == Twhile
			|| type == TLeftCurlyBracket || type == TSemiColon) {
			sc->setUk(save_uk);
			Operator();
		}
		else if (type != TRightCurlyBracket) {
			sc->setUk(save_uk);
			Dannie();
		}

	} while (type != TRightCurlyBracket);

}

void Diagram::Dannie()
{

	TypeLEX lex;

	int save_uk = sc->getUk();
	int type = sc->codeScaner(lex);
	if (type == TEnd) return;

	if (type == TConst) {
		int type = sc->codeScaner(lex);
		if (type != TConstString && type != TConstChar && type != TConstInt && type != Tfloat) sc->PrintError("(�� ������) �������� ��� � ��������", lex);
		save_uk = sc->getUk();

	}
	else {
		sc->setUk(save_uk);
		if (type != TConstString && type != TConstChar && type != TConstInt && type != Tfloat) sc->PrintError("(�� ������) �������� ��� ��� ������������� � ��������", lex);
		type = sc->codeScaner(lex);

	}
	do
	 {
		Peremennaya();
		save_uk = sc->getUk();
		type = sc->codeScaner(lex);

	 } while (type == TComma);

	sc->setUk(save_uk);
}
void Diagram::Peremennaya()
{
	TypeLEX lex;
	int save_uk;
	int type;
	if (sc->codeScaner(lex) == TIdent) {
		save_uk = sc->getUk();
		type = sc->codeScaner(lex);
		if (type == TSave)
			Virojeniya();
		else if (type == TLeftSquareBracket)
		{
			type = sc->codeScaner(lex);
			if (type != TConstInt) sc->PrintError("�������� Const int (�� ����������)", lex);
			if (sc->codeScaner(lex) != TRightSquareBracket) sc->PrintError("�������� \']\' (�� ����������)", lex);
			save_uk = sc->getUk();
			if (sc->codeScaner(lex) == TSave)
			{
				save_uk = sc->getUk();
				if (sc->codeScaner(lex) == TConstString)
				{
					type = sc->codeScaner(lex);
					return;
				}
				else
					sc->setUk(save_uk);
				if (sc->codeScaner(lex) != TLeftCurlyBracket ) sc->PrintError("�������� \'{\' (�� ����������)", lex);
					SpisokZnach();
				if (sc->codeScaner(lex) != TRightCurlyBracket) sc->PrintError("�������� \'}\' (�� ����������)", lex);

			}
			else
				sc->setUk(save_uk);

		}
	}else 
		sc->PrintError("�������� ������������� (�� ����������)", lex);
	
}
void Diagram::Operator()
{
	TypeLEX lex;
	int save_uk = sc->getUk();
	int type = sc->codeScaner(lex);

	if (type == TSemiColon) { return; }
	else if (type == TDo) { /*sc->setUk(save_uk);*/ Cycle(); }
	else if (type == Twhile) {
		type = sc->codeScaner(lex);
		if (type != TLeftBracket)sc->PrintError("��������  \'(\'` (�� ��������)", lex);
		//type = sc->codeScaner(lex);
		Virojeniya();
		if (sc->codeScaner(lex) != TRightBracket)sc->PrintError("��������  \')\'` (�� ��������)", lex);
	}
	else if (type == TLeftCurlyBracket) { sc->setUk(save_uk); SostOperator(); }
	else if (type == TIdent) {
		type = sc->codeScaner(lex);
		sc->setUk(save_uk);
		if (type == TLeftBracket)
			VizovFunkcii();
		else if (type == TLeftSquareBracket || type == TSave) { Prisvoeniya(); }
		else
		{
			sc->codeScaner(lex);
			sc->PrintError("(�� ��������) �������� ��������", lex);

		}

	}
	else
		sc->PrintError("(�� ��������) �������� ��������", lex);
}
void Diagram::SpisokZnach()
{
	TypeLEX lex;
	int save_uk;
	int type;

	do {
		Virojeniya();
		save_uk = sc->getUk();
		type = sc->codeScaner(lex);
	} while (type == TComma);
	sc->setUk(save_uk);

}

void Diagram::Cycle()
{
	Operator();
}

void Diagram::Prisvoeniya()
{
	TypeLEX lex;
	if (sc->codeScaner(lex) != TIdent)
		sc->PrintError("(�� ����������) �������� ������������� � ��������", lex);
	int save_uk = sc->getUk();
	if (sc->codeScaner(lex) == TLeftSquareBracket) {
		Virojeniya();
		if (sc->codeScaner(lex) != TRightSquareBracket)
			sc->PrintError("(�� ����������)  \']\'  � ��������", lex);
	}
	else
		sc->setUk(save_uk);
	if (sc->codeScaner(lex) != TSave)
		sc->PrintError("(�� ����������)  \'=\'  � ��������", lex);
	Virojeniya();
	if (sc->codeScaner(lex) != TSemiColon)
		sc->PrintError("(�� ����������)  \';\'  � ��������", lex);

}

void Diagram::Virojeniya()
{
	TypeLEX lex;
	int type;
	int save_uk;

	do {
		VirojeniyaOtnosh();
		save_uk = sc->getUk();
		type = sc->codeScaner(lex);
	} while (type == TEqual || type == TNotEqual);
	sc->setUk(save_uk);

}

void Diagram::VizovFunkcii()
{
	TypeLEX lex;
	if (sc->codeScaner(lex) != TIdent)
		sc->PrintError("�������� �������������", lex);
	if (sc->codeScaner(lex) != TLeftBracket)
		sc->PrintError("�������� c����� (", lex);
	if (sc->codeScaner(lex) != TRightBracket)
		sc->PrintError("�������� c����� )", lex);
	if (sc->codeScaner(lex) != TSemiColon)
		sc->PrintError("�������� c����� ;", lex);
}

void Diagram::VirojeniyaOtnosh()
{
	TypeLEX lex;
	int type;
	int save_uk;

	do {
		Slogaemoe();
		save_uk = sc->getUk();
		type = sc->codeScaner(lex);
	} while (type == TlessOrEqual || type == TGreatOrEqual
		|| type == Tless || type == TGreat);
	sc->setUk(save_uk);

}

void Diagram::Slogaemoe()
{
	TypeLEX lex;
	int type;
	int save_uk;

	do {
		Mnojitel();
		save_uk = sc->getUk();
		type = sc->codeScaner(lex);
	} while (type == TPlus || type == TMinus);
	sc->setUk(save_uk);
}

void Diagram::Mnojitel()
{
	TypeLEX lex;
	int type;
	int save_uk;

	do {
		Elviraj();
		save_uk = sc->getUk();
		type = sc->codeScaner(lex);
	} while (type == TMultiply || type == Tdivide
		|| type == TMod);
	sc->setUk(save_uk);

}

void Diagram::Elviraj()
{
	TypeLEX lex;
	int type = sc->codeScaner(lex);

	if (type == TConstInt) { return; }
	else if (type == TConstChar) { return; }
	else if (type == Tfloat) { return; }
	else if (type == TConstString) { return; }
	else if (type == TIdent) {
		int save_uk = sc->getUk();
		if (sc->codeScaner(lex) == TLeftSquareBracket) {
			Virojeniya();
			if (sc->codeScaner(lex) != TRightSquareBracket)
				sc->PrintError("(�� ��.���������) ��������  \']\' � ��������", lex);
		}
		else
			sc->setUk(save_uk);
	}
	else if (type == TLeftBracket) {
		Virojeniya();
		if (sc->codeScaner(lex) != TRightBracket)
			sc->PrintError("(�� ��.���������) ��������  \')\' � ��������", lex);
	}
	else {
		sc->PrintError("(�� ��.���������) �������� ���������� ���������", lex);
	}

}

