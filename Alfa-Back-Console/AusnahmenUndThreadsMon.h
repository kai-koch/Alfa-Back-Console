#pragma once
#include "AutomatSteuerung.h"

class AusnahmenUndThreadsMon  : public AutomatSteuerung
{
	bool AusnahmenMonitorStatus = true;
public:
	bool SetAusnahmenMonitorTrueFalse(bool);
	bool StartAusnahmenMonitor();


	AusnahmenUndThreadsMon();
	~AusnahmenUndThreadsMon();
};