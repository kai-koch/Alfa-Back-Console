#pragma once
class AutomatSteuerung
{
	bool BackProzessTimerStatus = true;
public:
	int JobQueueStatus = 4;
	void plaetzchenAnzahlErmitteln();
	void blechAnzahlErmitteln();
	void blechBelegen();
	void Backen(int);
	void Abkuehlen(int);
	void Verzierungen();
	void VerweilDauerBestimmen();

	AutomatSteuerung();
	~AutomatSteuerung();
};
