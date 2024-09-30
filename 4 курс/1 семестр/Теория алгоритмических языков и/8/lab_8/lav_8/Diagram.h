
#include "defs.h"
#include "Semant.h"
#include "Scaner.h"



class Diagram {
private:
	Scaner* sc;
	Tree* Root;
	// ������� ��:
	void Class();
	void Main();
	void Dannie();
	void Operator();
	void SostOperator();
	void While();
	void Prisvaivanie();
	void Viraj();
	void Sravnenie();
	void Sdvig();
	void Slagaemoe();
	void Mnojitel();
	void ElemViraj();
	void Do();
public:
	Diagram(Scaner* s) { sc = s; Root = new	Tree(sc); }
	~Diagram() {}
	void Programm(); // ���������
	void Print();
};

#pragma once
