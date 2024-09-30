// OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{	//Статическое делегирование
	class Imsg
	{
		public:
			virtual void msg() = 0;//интерфейс не имеет реализации
			
	};
	class Icall
	{
	public:
		virtual void call() = 0;//интерфейс не имеет реализации
	};
	class MSGT:public Imsg
	{
	public:
		void msg()
		{
			cout << "I can't send message\n";
		}
	};
	class MSGF :public Imsg
	{
	public:
		void msg()
		{
			cout << "I can send message\n";
		}
	};
	class CALLT :public Icall
	{
	public:
		void call()
		{
			cout<<"I can call\n";
		}
	};
	class CALLF :public Icall
	{
	public:
		void call()
		{
			cout << "I can't call\n";
		}
	};
	//абстрактный класс устройства
	class Device
	{
	public:
		Icall * getcall;
		Imsg* getmsg;
		Device() {}
		~Device();
		void PerformOfGetmsg() 
		{
			getmsg > msg();
		};
		void PerformOfGetcall()
		{
			getcall > call();
		};
	};
	//устройства
	class Phone :public Device {
	public:
		Phone()
		{
			getmsg = new MSGT;
			getcall = new CALLT;

		};
	};

	class Pager :public Device {
	public:
		Pager()
		{
			getmsg = new MSGT;
			getcall = new CALLF;

		};
	};

	

}
