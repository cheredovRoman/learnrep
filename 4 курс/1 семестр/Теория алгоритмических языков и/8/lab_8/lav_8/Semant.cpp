#include <string.h>
#include "defs.h"
#include "Scaner.h"
#include "Semant.h"

Scaner* Tree::scan = (Scaner*)NULL;
Tree* Tree::Cur = (Tree*)NULL;


// ���������� ������� ���� ������
void Tree::SetCur(Tree* a) {
	Cur = a;
}

// �������� �������� �������� ���� ������
Tree* Tree::GetCur(void) {
	return Cur;
}

// ��������� �������������� a � ������� � ����� t
Tree* Tree::SemInclude(TypeLex a, TypeObject ob, PrimitiveDataType t, bool cons = 0) {
	if (DupControl(Cur, a))
		scan->PrintError("��� ������: �������� ������ �������������!", a);

	Tree* v; Node b;

	memcpy(b.id, a, strlen(a) + 1);
	b.objType = ob;
	b.dataType = t;
	b.Const = cons;

	if (this->node->objType == ObjEmpty && this->parent == NULL && this->left == NULL && this->right == NULL)
		memcpy(node, &b, sizeof(Node));
	else
	{
		Cur->SetLeft(&b);
		Cur = Cur->left;
	}

	if (ob == ObjMain || ob == ObjTypeClass)
	{
		v = Cur;
		memcpy(&b.id, &"", 2);
		b.objType = ObjEmpty;

		Cur->SetRight(&b);
		Cur = Cur->right;
		return v;
	}

	return Cur;
}

// ���������� ��� t ��� ���������� �� ������ Addr
void Tree::SemSetType(Tree* Addr, PrimitiveDataType t) {
	Addr->node->dataType = t;
}

// ���������� ��� ������� ��� ���������� �� ������ Addr
void Tree::SemSetObjType(Tree* Addr, TypeObject t) {
	Addr->node->objType = t;
}

Tree* Tree::SemGetType(TypeLex a)
// ����� � ������� ���������� � ������ a
// � ������� ������ �� ��������������� ������� ������
{
	Tree* v = FindUp(Cur, a);
	if (v == NULL)
		scan->PrintError("��� ������: ����������� �������� ��������������! ", a);
	return v;
}

Tree* Tree::SemNewLevel()
{
	Node n;

	memcpy(&n.id, &"", 2);
	n.objType = ObjEmpty;

	Cur->SetLeft(&n);
	Cur = Cur->left;
	Tree* v = Cur;

	Cur->SetRight(&n);
	Cur = Cur->right;

	return v;
}

// �������� �������������� � �� ��������� �������� ������ �����.
// ����� �������������� ����� �� ������� Addr.
int Tree::DupControl(Tree* Addr, TypeLex a) {
	if (FindUpOneLevel(Addr, a) == NULL) return 0;
	return 1;
}


PrimitiveDataType Tree::GetType(int lexType)
{
	if (lexType == TShort)
		return ShortType;

	if (lexType == TInt)
		return IntegerType;

	return UndefinedType;
}