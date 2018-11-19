#pragma once
class AutomatSteuerung 
{
public:
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
