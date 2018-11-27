#pragma once

/*
#include <iostream>
#include "Ofen.h"
#include "ParameterListe.h"
#include "AusnahmenUndThreadsMon.h"
#include "Band.h"
#include "OfenSteuerung.h"
*/




class AutomatSteuerung;
class Ofen;
class Band;
class AusnahmenUndThreadsMon;
class ParameterListe;
class OfenSteuerung;

class AutomatSteuerung
{
	bool BackProzessTimerStatus = false; // 1 Prozess Lock

	Ofen * Ofn;
	Band * Bnd;
	AusnahmenUndThreadsMon * AM;
	ParameterListe * PL;
	OfenSteuerung * OfnSu;

public:
	int JobQueueStatus;
	void plaetzchenAnzahlErmitteln();
	void blechAnzahlErmitteln();
	void blechBelegen();
	void Backen(int);
	void Abkuehlen(int);
	void Verzierungen();
	void VerweilDauerBestimmen();

	void InitClassen(AutomatSteuerung * As);

	Ofen *  getOfen();
	Band * getBand();
	AusnahmenUndThreadsMon * getAusnahmenUndThreadsMon();
	ParameterListe * getParameterListe();
	OfenSteuerung * getOfenSteuerung();

	void setOfen(Ofen * Ofn1);
	void setBand(Band * Bnd1);
	void setAusnahmenUndThreadsMon(AusnahmenUndThreadsMon * ATM1);
	void setParameterListe(ParameterListe * PL1);
	void setOfenSteuerung(OfenSteuerung * setOfSteu1);

	AutomatSteuerung();
	~AutomatSteuerung();
};