#include "Ruler.h"

Ruler::Ruler(int how_many_marks)
{
	for (int i = 0; i < how_many_marks; i++)
		marks.push_back(1);
}

void Ruler::MakeNewMarks(int degree_of_two)
{
	int temp_counter = 1;
	int temp_counter_memory = temp_counter;
	int how_many_times_to_multiplie = degree_of_two;
	static int temp_multiplier = 1;

	if (how_many_times_to_multiplie - 1 != -1)
	{
		temp_multiplier = temp_multiplier * 2;
		how_many_times_to_multiplie--;
	}
	else return;

	for (it = marks.begin(); it != marks.end(); it++)
	{
		if (temp_counter != 0)
		{
			temp_counter--;
			continue;
		}
		else
		{
			marks.insert(it, temp_multiplier);
			temp_counter = temp_counter_memory + 2;
			temp_counter_memory = temp_counter;
			it = marks.begin();
			temp_counter--;
		}
	}

	MakeNewMarks(how_many_times_to_multiplie);
}

void Ruler::ShowRuler()
{
	for (int i = 0; i < marks.size(); i++)
		cout << marks.at(i) << " ";
}
