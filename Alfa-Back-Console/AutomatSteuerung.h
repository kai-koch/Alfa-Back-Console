#pragma once

class AutomatSteuerung
{
	bool BackProzessTimerStatus = false; // 1 Prozess Lock
public:
	int JobQueueStatus;
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

