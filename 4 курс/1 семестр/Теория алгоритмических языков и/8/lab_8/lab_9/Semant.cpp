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

// �������� ��� ������� ����
TypeObject Tree::GetObjType(Tree* Addr) {
	return Addr->node->objType;
}

// �������� ��� ������ ����
PrimitiveDataType Tree::GetDataType(Tree* Addr) {
	return Addr->node->dataType;
}

// ��������� �������������� a � �������
Tree* Tree::SemInclude(TypeLex a, TypeObject ob, PrimitiveDataType t, bool cons = 0) {
	if (DupControl(Cur, a))
		scan->PrintError("��������� �������� ��������������", a);

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

// ����� ���������� �� ��������������
Tree* Tree::SemFindVar(TypeLex a)
{
	Tree* v = FindUp(Cur, a);

	if (v == NULL) scan->PrintError("����������� �������� ����������", a);
	if (v->node->Const) scan->PrintError("������ ����������� ���������", a);
	return v;
}

// ����� ����� �� ��������������
Tree* Tree::SemFindClass(TypeLex a)
{
	Tree* v = FindUp(Cur, a);
	if (v == NULL) scan->PrintError("����������� �������� ������", a);
	return v;
}

// ����� ���� � ������
Tree* Tree::SemFindClassVar(TypeLex a)
{
	Tree* v = FindRightLeft(a);
	if (!v)	scan->PrintError("������ ���� ����������� � ������", a);
	return v;
}

// ��������� �������� (��� � ������������ � ���� �������� ������� ���������� �����!)
PrimitiveDataType Tree::GetTypeResult(PrimitiveDataType op1, PrimitiveDataType op2, int operation, TypeLex a) {
	if (operation >= TLess && operation <= TOperatorEqvivalentnosti)
		return ShortType;

	if ((operation >= TLeftShift && operation <= TRightShift || operation == TMode) && (op1 == FloatType || op2 == FloatType))
		scan->PrintError("��������� �������� ������ �������� ������ � ������ �������", a);

	if (op1 == IntegerType && op2 == IntegerType)
		return IntegerType;

	if (op1 == ShortType && op2 == ShortType)
		return ShortType;

	if (op1 == IntegerType && op2 == ShortType)
		return IntegerType;

	if (op1 == ShortType && op2 == IntegerType)
		return IntegerType;

	if (op1 == FloatType || op2 == FloatType)
		return FloatType;
}


// �������� �������������� � �� ��������� �������� ������ �����.
// ����� �������������� ����� �� ������� Addr.
int Tree::DupControl(Tree* Addr, TypeLex a) {
	if (FindUpOneLevel(Addr, a) == NULL) return 0;
	return 1;
}

// �������� ��� � ���� PrimitiveDataType
PrimitiveDataType Tree::GetType(int lexType)
{
	if (lexType == TShort)
		return ShortType;

	if (lexType == TInt)
		return IntegerType;

	if (lexType == TDouble)
		return FloatType;

	return UndefinedType;
}