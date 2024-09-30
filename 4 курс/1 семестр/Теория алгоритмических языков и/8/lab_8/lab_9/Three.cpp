#include "defs.h"
#include "Semant.h"

#define max(a,b) a<b? b : a


// ����������� ������� ����� ���� � ������� ������� � �������
Tree::Tree(Scaner* scan) {
	this->scan = scan;

	node = new Node();
	node->objType = ObjEmpty;
	node->dataType = UndefinedType;


	parent = NULL;
	left = NULL;
	right = NULL;

	Cur = this;
}

// ����������� ������� ���� � ��������� ������� � �������
Tree::Tree(Tree* l, Tree* r, Tree* u, Node* d) {
	node = new Node();

	parent = u; left = l; right = r; // ���������� ������

	memcpy(node, d, sizeof(Node)); // ���������� ������
}

// ������� ������ ������� �� ������� ������� this
void Tree::SetLeft(Node* Data) {
	left = new Tree(NULL, NULL, this, Data);
}

// ������� ������� ������� �� ������� ������� this
void Tree::SetRight(Node* Data) {
	Tree* a = new Tree(NULL, NULL, this, Data); // ����� �������
	right = a; // ������� this � ����� ��������
}

void Tree::SetRightT(Tree* node) {
	right = node;
}

Tree* Tree::GetRight() {
	return right;
}

Tree* Tree::FindRoot()
{
	Tree* i = Cur;

	while ((i != NULL) && (i->parent != NULL))
		i = i->parent;

	return i;
}

// ����� ������ � ������, ������� �� ������� ������� this
// �� ��� ����� ����� �� ������
Tree* Tree::FindUp(TypeLex id) {
	return FindUp(this, id);
}

// ����� ������ � ������ �� �������� ������� From
// �� ��� ����� ����� �� ������
Tree* Tree::FindUp(Tree* From, TypeLex id) {
	Tree* i = From; // ������� ������� ������
	while ((i != NULL) &&
		(memcmp(id, i->node->id, max(strlen(i->node->id), strlen(id))) != 0))
		i = i->parent; // ����������� ������ �� ������
	return i;
}

// ����� ������ �������� ������� ������� this
Tree* Tree::FindRightLeft(TypeLex id) {
	return FindRightLeft(this, id);
}

// ����� ������ �������� �������� ������� From
Tree* Tree::FindRightLeft(Tree* From, TypeLex id) {
	Tree* i = From->right; // ������� ������� ������
	while ((i != NULL) &&
		(memcmp(id, i->node->id, max(strlen(i->node->id), strlen(id))) != 0))
		i = i->left;
	// ������� ������ ������� �� ����� ������
	return i;
}

Tree* Tree::FindUpOneLevel(Tree* From, TypeLex id)
// ����� �������� id ����� �� ������ �� ������� ������� From.
// ����� �������������� �� ����� ������ ����������� �� ����� ������
{
	Tree* i = From; // ������� ������� ������
	while ((i != NULL) && (i->parent == NULL || i->parent->right != i))
	{
		if (memcmp(id, i->node->id, max(strlen(i->node->id), strlen(id))) == 0)
			return i; // �a��� ����������� �������������
		i = i->parent; // ����������� ������ �� ������
	}
	return NULL;
}

// ���������� ��������� ������ ������
void Tree::Print()
{
	if (node->objType != ObjEmpty)
		printf("    %-15s  ---->", node->id);
	else
		printf("    ������            ---->");

	if (left != NULL)
	{
		if (left->node->objType != ObjEmpty)
			printf("      ����� ��������� %s", left->node->id);
		else
			printf("      ����� ������");
	}


	if (right != NULL)
	{
		if (right->node->objType != ObjEmpty)
			printf("      ������ ��������� %s", right->node->id);
		else
			printf("      ������ ������");
	}

	printf("\n");

	if (left != NULL)
		left->Print();

	if (right != NULL)
	{
		printf("\n\n��������: ");
		if (node->objType != ObjEmpty)
			printf("������� ��� %s\n", node->id);
		else
			printf("������� ������\n");
		right->Print();
	}
}