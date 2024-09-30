#pragma once
#include "Defs.h"
#include "Scaner.h"
class Diagram
{
private:
	Scaner* sc;
	void Funkciya();
	void Dannie();
	void Peremennaya();
	void SpisokZnach();
	void Operator();
	void SostOperator();
	void Cycle();
	void Prisvoeniya();
	void Virojeniya();
	void VizovFunkcii();
	void VirojeniyaOtnosh();
	void Slogaemoe();
	void Mnojitel();
	void Elviraj();
public:
	Diagram(Scaner* s) { sc = s; };
	void Programma();
	~Diagram() {};

};
