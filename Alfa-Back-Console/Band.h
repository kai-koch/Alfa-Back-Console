#pragma once
#include "BandSteuerung.h"

class Band : public BandSteuerung
{
	double Geschwindigkeit;
public:
	void getGeschwindigkeit();
	void setGeschwindigkeit(int Geschwind);
	Band();
	~Band();
};

