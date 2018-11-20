#include "stdafx.h"
#include "OfenSteuerung.h"


void OfenSteuerung::OfenAufheizen()
{
}

bool OfenSteuerung::OfenTemperaturStatus()
{
	double Temperat;

	Ofen Ofn;
	Temperat = Ofn.getTemperatur();
	if (Temperat = 0)
	{
		return false;
	}
	return true;
}

OfenSteuerung::OfenSteuerung()
{
}


OfenSteuerung::~OfenSteuerung()
{
}
