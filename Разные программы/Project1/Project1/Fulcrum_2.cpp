#include <iostream>
#include "Ruler.h"

using namespace std;

int main()
{
    Ruler ruler(2);

    ruler.MakeNewMarks(4);

    ruler.ShowRuler();
}
