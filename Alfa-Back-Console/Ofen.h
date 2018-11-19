#pragma once
#include "OfenSteuerung.h"

class Ofen : public OfenSteuerung
{
private:
	double Temperatur;
public:
	double getTemperatur();
	void setTemperatur(int Temperatur);
	Ofen();
	~Ofen();
};

