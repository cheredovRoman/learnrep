#include "Scaner.h"
#include "Diagram.h"

int main() {
	setlocale(LC_ALL, "ru");
	Scaner* sc;
	Diagram* dg;

	FILE* in = fopen("input.txt", "r");

	sc = new Scaner(in);
	dg = new Diagram(sc);
	dg->Programm();

	int type;
	TypeLex l;

	type = sc->Scan(l);

	if (type == TEnd) printf("Синтаксических ошибок не обнаружено. \n");
	else sc->PrintError("Лишний текст в конце программы.", "");

	printf("\n\nСЕМАНТИЧЕСКОЕ ДЕРЕВО\n\n");
	printf("Вершина с данными		  данные\n\n");
	dg->Print();

	return 0;
}


/*int main() {
	setlocale(LC_ALL, "ru");
	Scaner* sc;
	Diagram* dg;

	FILE* in = fopen("input.txt", "r");

	sc = new Scaner(in);
	dg = new Diagram(sc);
	dg->Programm();

	int type;
	TypeLex l;

	type = sc->Scan(l);
	if (type == TEnd) printf("Синтаксических ошибок не обнаружено. \n");
	else sc->PrintError("Лишний текст в конце программы.", "");
	return 0;
}
*/