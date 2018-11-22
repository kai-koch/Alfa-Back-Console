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
#include "AusnahmenUndThreadsMon.h"
int Temp;
int ProzessSteuerung(int Zahl1int, int Zahl2int);
void cls();

//###############
int Operator;
bool JaNa{ false };
bool Operator_Bool{ false };

/*
enum Ereignisse
{
	SM_FORMEN,
	SM_OFEN,
	SM_ABKUEHLEN,
	SM_VERZIEHRUNGEN,
	MAX_STATES
};

enum Zustaende
{
	IDLE, // Temp 0 + Geschwindigkeit
	TEMPERATUR, //Temp X + Geschwindigkeit 0
	GESCHWINDIGKEIT,// Temp X + Geschwindigkeit X
	FEHLER, // FEHLER Unbekannt
	AUSGANG
};*/


char OperatorTest['w'];

int Zahl1int;
int Zahl2int;


int main()
{

	do
	{

		cout << "" << endl;
		cout << "Grossbaeckerei Helper: " << endl;
		cout << "" << endl;
		cout << "          (" << endl;
		cout << "           )" << endl;
		cout << "      __..--- ..__" << endl;
		cout << " ,--='  /  |  \\  `=--." << endl;
		cout << ":---..___________..---;" << endl;
		cout << "\\.,. _____________,../" << endl;
		cout << "1.Steuerung (1a - IDLE State, 1b - Backen) " << endl;
		cout << "2.Simulation Test (2a - Aendern Geschwindigkeit 2b - Aendern Temperatur, 2c - Aendern Zeit)  " << endl;
		cout << "3.Simulation Flags Test (3a - Zutaten, 3b - Verzierung, 3c - Teig, 3d - Teigroesse,3e - BlechAusfuelung)  " << endl;
        cout << "4.Simulation Bestand im Lager - Flags Test ()  " << endl;
		cout << "5.Exit (5a Exit)" << endl;
		cout << "Bitte die Nummer eingeben :  " << endl;

		cin.clear();

		cin >> Zahl1int >> OperatorTest;

		cout << Zahl1int << "-" << OperatorTest << endl;


		//AusnahmenUndThreadsMon ATM;
		//ATM.StartAusnahmenMonitor();

		switch (*OperatorTest)
		{
		case 'a': Zahl2int = 1; break;
		case 'b': Zahl2int = 2; break;
		case 'c': Zahl2int = 3; break;
		case 'd': Zahl2int = 4; break;
		case 'e': Zahl2int = 5; break;
		//case 'f':
		default: cout << "Falsche Angaben, bitte versuchen Sie es noch einmal ..." << endl; Operator_Bool = true; break;
		}

		while (Operator_Bool == false)
		{

			switch (Zahl1int)
			{
			case 1: ProzessSteuerung(Zahl1int, (Zahl2int - 1)); Operator_Bool = true; break; // Steuerung (1a - IDLE State, 1b - Backen) " << endl;
			case 2: ProzessSteuerung(Zahl1int, (Zahl2int+1)); Operator_Bool = true; break; //Simulation Test (2a - Aendern Geschwindigkeit 2b - Aendern Temperatur, 2c - Aendern Zeit)  " << endl;
			case 3: // Simulation Flags Test (3a - Zutaten, 3b - Verzierung, 3c - Teig, 3d - Teigroesse,3e - BlechAusfuelung)  " << endl;
			case 4:// Simulation Bestand im Lager - Flags Test ()  " << endl;
			case 5: JaNa = true; Operator_Bool = true; break; // Ausgang
			default: cout << "Falsche Angaben, bitte versuchen Sie es noch einmal ..." << endl; Operator_Bool = true; break;
			}
		}
		Operator_Bool = false;

		////Cleaning
		Zahl1int = 0;
		Zahl2int = 0;
		// clean the screen
		//clear();
	} while (!JaNa);

	return 0;
}

int ProzessSteuerung(int Zahl1int, int Zahl2int)
{
	try
	{

		Ofen Ofn;
		Band Bnd;
		AutomatSteuerung As;
		OfenSteuerung OfnSteu;
		int Z = 0;

		bool ZusammenfassungState;
		bool StatusTemperatur;
		bool StatusSpeed;

		As.JobQueueStatus = Zahl2int;
		ParameterListe PL;
		//ZusammenfassungState = PL.ZusammenfassungFunc();
		StatusTemperatur = OfnSteu.OfenTemperaturStatus();
		StatusSpeed = Bnd.GetGeschwindigkeitStatus();

		//Bnd.getGeschwindigkeit();

		while ((ZusammenfassungState = true) && (StatusTemperatur = true) && (StatusSpeed = true))
		{
			std::cout << "While States (ZusammenfassungState << StatusTemperatur << StatusSpeed) - " << ZusammenfassungState << StatusTemperatur << StatusSpeed << endl;
			//cls();

			ZusammenfassungState = PL.ZusammenfassungFunc();
			StatusTemperatur = OfnSteu.OfenTemperaturStatus();
			StatusSpeed = OfnSteu.OfenTemperaturStatus();

			switch (As.JobQueueStatus)
			{
			case 0: Bnd.setGeschwindigkeit(0); break; // IDLE State
			case 1: As.Backen(20); break; // Backen
			case 2: Bnd.setGeschwindigkeit(100); break; // Geschwindigkeit regeln
			case 3: Ofn.setTemperatur(100); break; // Prozess Start
			//case 4: As.Backen(20)Zeit Aendern; break;
			default:; break;
			}
		}

		return 0;

	}
	catch (int e)
	{
		cout << "Unbekannte Fehler" << e << endl;
	}


}