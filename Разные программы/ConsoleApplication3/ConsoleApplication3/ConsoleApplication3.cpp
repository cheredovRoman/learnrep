#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class IMSG {
public:
	virtual  void   msg() = 0; // интерфейс не имеет реализации
};
class ICALL {
public:
	virtual  void   call() = 0; // интерфейс не имеет реализации

};
class  MSGT : public IMSG {
	// класс поведения для устройств, которые умеют писать смс
public:
	void msg() {
		printf("I am message!\n");
	}
};
class  MSGF : public IMSG {
	// класс поведения для устройств, которые не умеют писать смс
public:
	void msg() {
		printf("I am dont message!\n");
	}
};
class  CALLT : public ICALL {
	// класс поведения для устройств, которые HE умеют call
public:
	void call() {
		printf("I can call...\n");
	}
};
class  CALLF : public ICALL {
	// класс поведения для устройств, которые HE умеют call
public:
	void call() {
		printf("I can not call...\n");
	}
};
class Device {        // абстрактный класс устройства
public:
	IMSG* msgaction;
	ICALL* callaction;
	Device() {}
	~Device();
	// делегируем выполнение операции классам поведения :
	void performcall() { callaction->call();}
	void performmsg() { msgaction->msg();}

};
class Phone : public  Device {
public:
	Phone() {
		callaction = new CALLT();
		msgaction = new MSGT();

	}
};
class Pager : public  Device {
public:
	Pager() {
		callaction = new CALLF();
		msgaction = new MSGT();

	}
};
int main() {   // создаем объекты устройств
	printf("  devices\n");
	Phone Phone1;
	Pager Pager2;
	Phone1.performcall();
	Phone1.performmsg();
	Pager2.performcall();
	Pager2.performmsg();
}



