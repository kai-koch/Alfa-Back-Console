#include "stdafx.h"
#include "OfenSteuerung.h"
#include <iostream>
#include <string>
using namespace std;


void OfenSteuerung::OfenAufheizen()
{
}

bool OfenSteuerung::OfenTemperaturStatus()
{
	double Temperat;

	Ofen Ofn;
	Temperat = Ofn.getTemperatur();
	cout << "bool OfenSteuerung::OfenTemperaturStatus()" << Temperat << endl;
	if (Temperat == 0)
	{
		return false;
	}
	else 
	{ 
	return true;
	}
}

OfenSteuerung::OfenSteuerung()
{
}


OfenSteuerung::~OfenSteuerung()
{
}
