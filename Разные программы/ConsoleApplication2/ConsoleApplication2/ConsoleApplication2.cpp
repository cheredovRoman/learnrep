#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class IService { // интерфейс
public:
	virtual string getDescription() = 0;
	virtual float getCost() = 0;
};
class AdditionalOption : public IService { // декоратор
protected:
	IService* item; // декорируемый объект
public:
	virtual string getDescription() = 0;
	virtual float getCost() = 0;
	AdditionalOption(IService* inItem) { item = inItem; }
	~AdditionalOption() {
		if (item) delete item;
	}
};
class DiagnosticEngine : public IService { // конкретный объект
public:
	virtual string getDescription() {
		return string("Engine diagnostics done"); // название услуги
	}
	virtual float getCost() {
		return 3500; // стоимость
	}
};
class DiagnosticElectrical : public IService { // конкретный объект
public:
	virtual string getDescription() {
		return string("Electrical diagnostics done"); // название услуги
	}
	virtual float getCost() {
		return 1200; // стоимость
	}
};
class Recomendations : public AdditionalOption { // конкретный декоратор
public:
	virtual string getDescription() {
		return string("Recommendations issued + ") + item->getDescription(); // Составная услуга
	}
	virtual float getCost() {
		return (900 + item->getCost()) * 0.9; //Составная цена со скидкой
	}
	Recomendations(IService* inItem) : AdditionalOption(inItem) {}
};
class ClientCard : public AdditionalOption { // конкретный декоратор
public:
	virtual string getDescription() {
		return string("Card issued + ") + item->getDescription();
	}
	virtual float getCost() {
		return (400 + item->getCost()) * 0.95; //Составная цена со скидкой
	}
	ClientCard(IService* inItem) : AdditionalOption(inItem) {}
};
int main() {
	DiagnosticEngine* DiagnosticEng = new DiagnosticEngine();
	cout << DiagnosticEng->getDescription() << ", cost: " << DiagnosticEng->getCost() << endl;
	DiagnosticElectrical* DiagnosticElectr = new DiagnosticElectrical();
	cout << DiagnosticElectr->getDescription() << ", cost: " << DiagnosticElectr->getCost()
		<< endl;
	//Задекорировали объект (добавили выдачу рекомендаций к диагностике электрооборудования
	Recomendations* Recomend = new Recomendations(DiagnosticElectr);
	cout << Recomend->getDescription() << ", cost: " << Recomend->getCost() << endl;
	//Задекорировали объект (добавили выдачу карты клиента к диагностике двигателя
	ClientCard* Card = new ClientCard(DiagnosticEng);
	cout << Card->getDescription() << ", cost: " << Card->getCost() << endl;
	//Задекорировали уже декорированный объект (добавили выдачу рекомендаций к диагностике двигателя с выданной картой)
	Recomendations* CardRecomend = new Recomendations(Card);
	cout << CardRecomend->getDescription() << ", cost: " << CardRecomend->getCost() << endl;
	delete DiagnosticEng, DiagnosticElectr;
	delete Recomend, Card, CardRecomend;
	return 0;
}