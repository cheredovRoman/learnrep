#include "TDiagram.h"

// ���������
void TDiagram::S() {
	TypeLEX lex;				//������� 
	int type;					//��� �������
	int save_uk;				//������� � �������� ������. 
	
	do {
		save_uk = ts->GetUK();
		type = ts->Scan(lex);
		ts->SetUK(save_uk);
		if (type == TVoid) { F(); }
		else if (type != TEnd) { D(); }
	} while (type != TEnd);
}

// �������
void TDiagram::F() {
	TypeLEX lex; 

	if  (ts->Scan(lex) != TVoid)
		ts->PError(Errors::EVoid, lex);
	int type = ts->Scan(lex);
	if (type != TIdent && type != TMain)
		ts->PError(Errors::EIdent, lex);
	if (ts->Scan(lex) != TLS)
		ts->PError(Errors::ELS, lex);
	if (ts->Scan(lex) != TPS)
		ts->PError(Errors::EPS, lex);
	W();
}

//���������

// ��������
void TDiagram::O() {
	TypeLEX lex;
	int save_uk = ts->GetUK(); 
	int type = ts->Scan(lex);

	if (type == TTZpt) { return; }
	else if (type == TIf) { ts->SetUK(save_uk); I();}
	else if (type == TFLS) { ts->SetUK(save_uk); W(); }
	else if (type == TIdent) {
		type = ts->Scan(lex);
		ts->SetUK(save_uk);
		if (type == TLS) { G(); }
		else if (type == TSLS || type == TSave) { J(); }
		else {
			ts->Scan(lex);
			ts->PError(Errors::EOperator, lex);
		}
	}
	else 
		ts->PError(Errors::EOperator, lex);
}

// ��������: ����� �������
void TDiagram::G() {
	TypeLEX lex;
	if (ts->Scan(lex) != TIdent)
		ts->PError(Errors::EIdent, lex);
	if (ts->Scan(lex) != TLS)
		ts->PError(Errors::ELS, lex);
	if (ts->Scan(lex) != TPS)
		ts->PError(Errors::EPS, lex);
	if (ts->Scan(lex) != TTZpt)
		ts->PError(Errors::ETZpt, lex);
}

// ��������: IF
void TDiagram::I() {
	TypeLEX lex;
	if (ts->Scan(lex) != TIf) 
		ts->PError(Errors::EIf, lex);
	if (ts->Scan(lex) != TLS) 
		ts->PError(Errors::ELS, lex);
	Q();
	if (ts->Scan(lex) !=TPS) 
		ts->PError(Errors::EPS, lex);
	O();
	int save_uk = ts->GetUK();
	if (ts->Scan(lex) == TElse)
		O();
	else
		ts->SetUK(save_uk);
}

// ��������: ���������
void TDiagram::W() {
	TypeLEX lex;
	
	if (ts->Scan(lex) != TFLS)
		ts->PError(Errors::EFLS, lex);
	
	int type;
	do {
		int save_uk = ts->GetUK();
		type = ts->Scan(lex);

		if (type == TIdent || type == TIf
			|| type == TFLS || type == TTZpt) {
			ts->SetUK(save_uk);
			O();
		}
		else if (type != TFPS) {
			ts->SetUK(save_uk);
			D();
		}
	} while (type != TFPS);
}

// ��������: ������������
void TDiagram::J() {
	TypeLEX lex;
	if (ts->Scan(lex) != TIdent)
		ts->PError(Errors::EIdent, lex);
	if (ts->Scan(lex) == TSLS) {
		Q();
		if (ts->Scan(lex) != TSPS)
			ts->PError(Errors::ESPS, lex);
	}
	if (ts->Scan(lex) != TSave) 
		ts->PError(Errors::ESave, lex);
	Q();
	if (ts->Scan(lex) != TTZpt)
		ts->PError(Errors::ETZpt, lex);
}

//��������

// ��������: ���. ���������
void TDiagram::Q() {
	TypeLEX lex;
	int type;
	int save_uk;

	do {
		M();
		save_uk = ts->GetUK();
		type = ts->Scan(lex);
	} while (type == TEQ || type == TNEQ);
	ts->SetUK(save_uk);
}

// ��������: ���. ���������
void TDiagram::M() {
	TypeLEX lex;
	int type;
	int save_uk;

	do {
		A();
		save_uk = ts->GetUK();
		type = ts->Scan(lex);
	} while (type == TLE || type == TGE
		|| type == TLT || type == TGT);
	ts->SetUK(save_uk);
}

// ��������: ����������
void TDiagram::A() {
	TypeLEX lex;
	int type;
	int save_uk;

	do {
		X();
		save_uk = ts->GetUK();
		type = ts->Scan(lex);
	} while (type == TPlus || type == TMinus);
	ts->SetUK(save_uk);
}

// ��������: �����������������
void TDiagram::X() {
	TypeLEX lex;
	int type;
	int save_uk;

	do {
		L();
		save_uk = ts->GetUK();
		type = ts->Scan(lex);
	} while (type == TMult || type == TDiv
		|| type == TMod);
	ts->SetUK(save_uk);
}

// ���������� �������� 
void TDiagram::L() {
	TypeLEX lex;
	int type = ts->Scan(lex);
	
	if (type == TDecInt) { return; }
	else if (type == THexInt) { return; }
	else if (type == TConstChar) { return; }
	else if (type == TIdent) {
		int save_uk = ts->GetUK();
		if (ts->Scan(lex) == TSLS) {
			Q();
			if (ts->Scan(lex) != TSPS)
				ts->PError(Errors::ESPS, lex);
		}
		else
			ts->SetUK(save_uk);
	}
	else if (type == TLS) {
		Q();
		if (ts->Scan(lex) != TPS)
			ts->PError(Errors::EPS, lex);
	} 
	else {
		ts->PError(Errors::ESimpExp, lex);
	}
}

// �������� � ���������

// ������
void TDiagram::D() {
	TypeLEX lex;
	
	int save_uk = ts->GetUK();
	int type = ts->Scan(lex);
	// ��� ������ (��� �������������)
	if (type != TChar && type != TInt64 && type != TInt) {
		ts->SetUK(save_uk);
		N();
	}
	C();
	if (ts->Scan(lex) != TTZpt)
		ts->PError(Errors::ETZpt, lex);
}

// ��� ������ (� ���������������)
void TDiagram::N() {
	TypeLEX lex;

	int save_uk = ts->GetUK();
	int type = ts->Scan(lex);
	if (type == TLong || type == TShort) {
		if (ts->Scan(lex) != TInt)
			ts->PError(Errors::EInt, lex);
	}
	else 
		ts->PError(Errors::ETypeData, lex);
}

// ������
void TDiagram::C() {
	TypeLEX lex;
	int save_uk;
	int type;

	do {
		H();
		save_uk = ts->GetUK();
		type = ts->Scan(lex);
	} while (type == TZpt);
	ts->SetUK(save_uk);
}

// ����������
void TDiagram::H() {
	TypeLEX lex;
	int save_uk;
	int type;

	if (ts->Scan(lex) == TIdent) {
		save_uk = ts->GetUK();
		type = ts->Scan(lex);
		if (type == TSave) { Q(); } // ������������
		else if (type == TSLS) {	// ���������� ������
			type = ts->Scan(lex);
			if (type != TDecInt && type != THexInt)
				ts->PError(Errors::E�onstInt, lex);
			if (ts->Scan(lex) != TSPS)
				ts->PError(Errors::ESPS, lex);
			save_uk = ts->GetUK();
			if (ts->Scan(lex) == TSave) { 
				if (ts->Scan(lex) != TFLS)
					ts->PError(Errors::EFLS, lex);
				Z();
				if (ts->Scan(lex) != TFPS)
					ts->PError(Errors::EFPS, lex);
			} else
				ts->SetUK(save_uk);
		}
		else
			ts->SetUK(save_uk);
	}
	else
		ts->PError(Errors::EIdent, lex);
}

// ���������
void TDiagram::Z() {
	TypeLEX lex;
	int save_uk;
	int type;

	do {
		Q();
		save_uk = ts->GetUK();
		type = ts->Scan(lex);
	} while (type == TZpt);
	ts->SetUK(save_uk);
}

