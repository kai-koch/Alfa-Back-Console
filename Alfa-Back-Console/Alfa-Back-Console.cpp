// Alfa-Back-Console.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <shlwapi.h>
#include <algorithm>
#include <thread>
#include <chrono>
using namespace std;
#include "AutomatSteuerung.h"
#include "OfenSteuerung.h"
#include "Ofen.h"
#include "Band.h"
#include "ParameterListe.h"
int Temp;
void cls();

int main()
{
	Ofen Ofn;
	Band Bnd;
	AutomatSteuerung As;
	OfenSteuerung OfnSteu;
	int Z = 0;

	bool ZusammenfassungState;
	bool StatusTemperatur;
	bool StatusSpeed;

	ParameterListe PL;
	ZusammenfassungState = PL.ZusammenfassungFunc();
	StatusTemperatur = OfnSteu.OfenTemperaturStatus();
	StatusSpeed = Bnd.GetGeschwindigkeitStatus();

	//Bnd.getGeschwindigkeit();

	while ((ZusammenfassungState = true) && (StatusTemperatur = true) && (StatusSpeed = true))
	{
		cls();

		ZusammenfassungState = PL.ZusammenfassungFunc();
		StatusTemperatur = OfnSteu.OfenTemperaturStatus();
		StatusSpeed = OfnSteu.OfenTemperaturStatus();

		switch (As.JobQueueStatus)
		{
		case 0: Bnd.setGeschwindigkeit(0); break; // IDLE State
		case 1: Ofn.setTemperatur(100); break; // Aufheizen
		case 2: Bnd.setGeschwindigkeit(100); break; // Geschwindigkeit regeln
		case 3: Ofn.setTemperatur(100); Bnd.setGeschwindigkeit(100); break; // Prozess Start
		case 4: As.Backen(20); break; // Thread needed ... mit lock
		default:; break;
		}
	}
	return 0;
}

