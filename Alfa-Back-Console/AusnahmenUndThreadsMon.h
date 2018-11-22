#pragma once
class AusnahmenUndThreadsMon
{
	bool AusnahmenMonitorStatus = true;
public:
	bool SetAusnahmenMonitorTrueFalse(bool);
	bool StartAusnahmenMonitor();


	AusnahmenUndThreadsMon();
	~AusnahmenUndThreadsMon();
};

