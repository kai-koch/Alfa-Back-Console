#include"stdafx.h"
#include "zutat.h"

zutat::zutat(string zutatName, double zutatMenge, string zutatEinheit)
{
	name = zutatName;
	menge = zutatMenge;
	masseinheit = zutatEinheit;
}

string zutat::getName()
{
	return name;
}

double zutat::getMenge()
{
	return menge;
}

string zutat::getMasseinheit()
{
	return masseinheit;
}

void zutat::setMenge(double ztMenge)
{
	menge = ztMenge;
}

zutat::zutat()
{
}

zutat::~zutat()
{
}
