#pragma once
#include "AutomatSteuerung.h"

class Blech : public AutomatSteuerung
{
	double Groesse;
public:
	void GetGroessse();
	Blech();
	~Blech();
};

