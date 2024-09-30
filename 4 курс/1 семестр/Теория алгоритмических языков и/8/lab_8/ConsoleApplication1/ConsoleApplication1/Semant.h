#pragma once
#include "defs.h"
#include "Scaner.h"

enum TypeObject {
    ObjEmpty = 0,   // ������ �������
    ObjVar,         // ����������
    ObjClass,      // ������ ���� ������
    ObjTypeClass,  // ���  ������ 
    ObjMain         // main
};

enum PrimitiveDataType {
    UndefinedType = 0,   // ��� ������ �������
    IntegerType,
    ShortType,
    FloatType
};
static const char* PrimitiveDataTypeStrings[] = { "undef", "int", "short", "float" };

struct Node {
    TypeLex id;                 // ������������� �������
    TypeObject objType = ObjEmpty;         // ���  �������
    PrimitiveDataType dataType = UndefinedType; // ��� ������
    bool  Const = 0;            // ���������
};

class Tree {
private:
    Node* node; // ������ �������
    Tree* parent, * left, * right; // ��������, ����� � ������ �������
public:
    static Scaner* scan;
    static Tree* Cur; // ������� ������� ������

    Tree(Tree* l, Tree* r, Tree* u, Node* Data);
    Tree(Scaner* scan);

    // ����������� �������  ������ � ��������:
    void SetLeft(Node* Data);
    void SetRight(Node* Data);
    void SetRightT(Tree* node);

    Tree* GetRight();

    Tree* FindRoot();
    Tree* FindUp(Tree* From, TypeLex id);
    Tree* FindUp(TypeLex id);
    Tree* FindUpOneLevel(Tree* From, TypeLex id);
    Tree* FindRightLeft(Tree* From, TypeLex id);
    Tree* FindRightLeft(TypeLex id);

    PrimitiveDataType GetType(int lexType);

    void Print();

    // ������������� ������������
        // ���������� ������� ���� ������
    void SetCur(Tree* a);

    //�������� ��� �������
    TypeObject GetObjType(Tree* Addr);
    //�������� ��� ������
    PrimitiveDataType GetDataType(Tree* Addr);

    // ��������� �������������� � �������
    Tree* SemInclude(TypeLex a, TypeObject ob, PrimitiveDataType t, bool cons);

    // ����� ���������� � ��������
    Tree* SemFindVar(TypeLex a);
    Tree* SemFindClass(TypeLex a);
    Tree* SemFindClassVar(TypeLex a);

    // ��������� ��������
    PrimitiveDataType GetTypeResult(PrimitiveDataType op1, PrimitiveDataType op2, int operation, TypeLex a);

    // �������� �������������� � �� ��������� �������� ������ �����
    int DupControl(Tree* Addr, TypeLex a);
};

/*
#include "defs.h"
#include "Scaner.h"

enum TypeObject {
    ObjEmpty = 0,   // ������ �������
    ObjVar,         // ����������
    ObjClass,      // ������ ���� ������
    ObjTypeClass,  // ���  ������
    ObjMain         // main
};

enum  PrimitiveDataType {
    UndefinedType = 0,   // ��� ������ �������
    IntegerType,
    ShortType,
    LongType,
    FloatType
};
static const char* PrimitiveDataTypeStrings[] = { "undef", "int", "short", "double" };

struct Node {
    TypeLex id;                 // ������������� �������
    TypeObject objType = ObjEmpty;         // ���  �������
    PrimitiveDataType dataType = UndefinedType; // ��� ������
    bool  Const = 0;            // ���������
};

class Tree {
private:
    Node* node; // ������ �������
    Tree* parent, * left, * right; // ��������, ����� � ������ �������
public:
    static Scaner* scan;
    static Tree* Cur; // ������� ������� ������

    Tree(Tree* l, Tree* r, Tree* u, Node* Data);
    Tree(Scaner* scan);

    // ����������� �������  ������ � ��������:
    void SetLeft(Node* Data);
    void SetRight(Node* Data);

    void SetRightT(Tree* node);
    Tree* GetRight();

    Tree* FindRoot();
    Tree* FindUp(Tree* From, TypeLex id);
    Tree* FindUp(TypeLex id);
    Tree* FindUpOneLevel(Tree* From, TypeLex id);
    Tree* FindRightLeft(Tree* From, TypeLex id);
    Tree* FindRightLeft(TypeLex id);

    PrimitiveDataType GetType(int lexType);

    void Print();

    // ������������� ������������
    // ���������� ������� ���� ������
    void SetCur(Tree* a);

    // �������� �������� �������� ���� ������
    Tree* GetCur(void);



    // ��������� �������������� � �������
    Tree* SemInclude(TypeLex a, TypeObject ob, PrimitiveDataType t, bool cons);

    //����� ������� (��� ���������� ���������)
    Tree* SemNewLevel();

    // ���������� ��� t ��� ���������� �� ������ Addr
    void SemSetType(Tree* Addr, PrimitiveDataType t);
    void SemSetObjType(Tree* Addr, TypeObject t);

    // ����� � ������� ���������� � ������ a
    // � ������� ������ �� ��������������� ������� ������
    Tree* SemGetType(TypeLex a);

    // �������� �������������� � �� ��������� �������� ������ �����
    int DupControl(Tree* Addr, TypeLex a);
};
*/