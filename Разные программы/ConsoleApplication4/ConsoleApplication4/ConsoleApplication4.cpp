#include <iostream>
#include <string>
using namespace std;
class farornear
{
public:
	virtual string readinformation() = 0;
};
class BrainStation
{
public:
	void ChekInfo(farornear* rc)
	{
		info = rc;
	}
	string readinformation()
	{
		if (info)
		{
			return info->readinformation();
		}
		return "Не установлен ";
	}
private:
	farornear* info = nullptr;;
};

class Far : public farornear
{
public:
	string readinformation() override
	{
		return "Направление";
	}
};
class Near : public farornear
{
public:
	string readinformation() override
	{
		// create pdf report logic
		return "Gps";
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Far Far;
	Near Near;
	BrainStation BrainStation;
	BrainStation.ChekInfo(&Far);

	cout << BrainStation.readinformation() << endl;


	return 0;
}
