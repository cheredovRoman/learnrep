
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Ruler
{
	vector<int> marks;
	vector<int>::iterator it;

public:

	Ruler(int how_many_marks);

	void MakeNewMarks(int degree_of_two);

	void ShowRuler();
};
