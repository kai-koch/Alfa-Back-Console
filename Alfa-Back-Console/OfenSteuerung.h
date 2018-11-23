#pragma once
#include "AutomatSteuerung.h"
#include "Ofen.h"

class OfenSteuerung : public AutomatSteuerung
{
public:
	void OfenAufheizen();
	bool OfenTemperaturStatus();
	OfenSteuerung();
	~OfenSteuerung();
};

