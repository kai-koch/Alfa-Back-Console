#pragma once
#include "AutomatSteuerung.h"

class OfenSteuerung : public AutomatSteuerung
{
public:
	void OfenAufheizen();
	OfenSteuerung();
	~OfenSteuerung();
};

