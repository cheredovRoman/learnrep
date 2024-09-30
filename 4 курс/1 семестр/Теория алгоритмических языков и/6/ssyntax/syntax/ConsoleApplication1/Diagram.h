
#include "Defs.h"
#include "Scaner.h"


class Diagram {
private:
	Scaner* sc;
	// ������� ��:
	void Class();
	void Main();
	void Dannie();
	void Operator();
	void SostOperator();
	void Do();
	void While();
	void Prisvaivanie();
	void Viraj();
	void Sravnenie();
	void Sdvig();
	void Slagaemoe();
	void Mnojitel();
	void ElemViraj();

public:
	Diagram(Scaner* s) { sc = s; }
	~Diagram() {}
	void Programm(); // ���������
};

#pragma once
