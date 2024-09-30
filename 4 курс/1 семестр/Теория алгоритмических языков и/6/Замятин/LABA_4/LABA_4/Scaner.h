#pragma once
#ifndef SCANER_H
#define SCANER_H
#include "Defs.h"

class Scaner
{
public:
	Scaner(const char* fileName);
	int codeScaner(TypeLEX lexic);
	void getData();
	int getUk();
	void setUk(int);
	void PrintError(std::string, std::string);

	~Scaner() {};

private:
	TypeIM im;	// »сходный модуль
	int uk;		// ”казатель позиции в исходном модуле
	int codeSize = 0; //потом удали
};
#endif