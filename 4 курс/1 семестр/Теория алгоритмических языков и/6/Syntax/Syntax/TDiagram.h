#pragma once
#ifndef __DIAGRAM
#define __DIAGRAM
#include "TScaner.h"
#include "Errs.h"



class TDiagram
{
private:
	TScaner* ts;
public:
	TDiagram(TScaner* ts) { this->ts = ts; };
	~TDiagram() {};

	void S(); // ���������
	void F(); // �������

	// ���������
	void O(); // ��������
	void G(); // ��������: ����� �������
	void I(); // ��������: IF
	void W(); // ��������: ���������
	void J(); // ��������: ������������

	// ��������
	void Q(); // ��������: ���. ���������
	void M(); // ��������: ���. ���������
	void A(); // ��������: ����������
	void X(); // ��������: �����������������
	void L(); // ���������� �������� 

	// �������� � ���������
	void D(); // ������ 
	void N(); // ��� ������ (� ���������������)
	void C(); // ������
	void H(); // ����������
	void Z(); // ���������

};

#endif //__DIAGRAM

