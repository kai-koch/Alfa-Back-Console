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
#include <sstream>
#include <iomanip>

//####################### Header Intern ###################
#include "rezept.h"
#include "OfenSteuerung.h"
#include "Ofen.h"
#include "Band.h"
#include "ParameterListe.h"
#include "AusnahmenUndThreadsMon.h"
#include "AutomatSteuerung.h"
#include "lagerVerwaltung.h"
//####################### Proto ###########################
void cls();                                              //
void COUTFuncIntro();                                    //
int ProzessSteuerungMethod(int Zahl1int, int Zahl2int);  //
void divider();                                          //
//#########################################################

using namespace std;

//##################### Variablen #########################
int Operator;                                            //
bool JaNa{ false };                                      //    
bool Operator_Bool{ false };                             //
char OperatorTest['w'];                                  //
int Zahl1int;                                            //
int Zahl2int;                                            //
//#################### Main Class #########################
AutomatSteuerung * As; //AutomatSteuerung As;            //
//#########################################################
/**
*erstelle ein Rezept
*/
rezept* erstelleRezept();

int main()
{
	try
	{
		As = new AutomatSteuerung();
		As->InitClassen(As);

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 11);

		COUTFuncIntro(); //
						 /**
						 *haikels Funcktionstest

						 */
						 /*
						 rezept * schokoPlaetzchen = new rezept("Schokokeks", 100.0, "Kreis", "mittel", 180.0, 40.0);
						 zutat * backpulverZutat = new zutat("Backpulver", 100.0, "g");
						 schokoPlaetzchen->addZutat(*backpulverZutat);
						 zutat * eierZutat = new zutat("Eier", 0.9, "l");
						 schokoPlaetzchen->addZutat(*eierZutat);
						 zutat * kakoZutat = new zutat("Kakao", 700.0, "g");
						 schokoPlaetzchen->addZutat(*kakoZutat);
						 zutat * mehlZutat = new zutat("Mehl", 900.0, "g");
						 schokoPlaetzchen->addZutat(*mehlZutat);
						 zutat * milchZutat = new zutat("Milch", 4.0, "l");
						 schokoPlaetzchen->addZutat(*milchZutat);
						 zutat * pflanzenfettZutat = new zutat("Pflanzenfett", 500.0, "g");
						 schokoPlaetzchen->addZutat(*pflanzenfettZutat);
						 zutat * zuckerZutat = new zutat("Zucker", 1000.0, "g");
						 schokoPlaetzchen->addZutat(*zuckerZutat);
						 zutat * kakaogussVerzierung = new zutat("Kakaoguss", 0.3, "l");
						 schokoPlaetzchen->addVerzierung(*kakaogussVerzierung);
						 zutat * schokostreuselVerzierung = new zutat("Schokostreusel", 300.0, "g");
						 schokoPlaetzchen->addVerzierung(*schokostreuselVerzierung);
						 lagerVerwaltung * lgverwaltung= new lagerVerwaltung()
						 */

		do
		{
			cin >> Zahl1int >> OperatorTest;
			cout << "Eingegeben - " << Zahl1int << "-" << OperatorTest << endl;

			divider();

			switch (*OperatorTest)
			{
			case 'a': Zahl2int = 1; break;
			case 'b': Zahl2int = 2; break;
			case 'c': Zahl2int = 3; break;
			case 'd': Zahl2int = 4; break;
			case 'e': Zahl2int = 5; break;
			default: cout << "Falsche Angaben, bitte versuchen Sie es noch einmal ..." << endl; Operator_Bool = true; break;
			}

			while (Operator_Bool == false)
			{

				switch (Zahl1int)
				{
				case 1:
				{
					thread PSMthread1(ProzessSteuerungMethod, Zahl1int, (Zahl2int - 1));
					PSMthread1.detach();
				}
				Operator_Bool = true; break; // Steuerung (1a - IDLE State, 1b - Backen) " << endl;
				case 2:
				{
					if (Zahl2int == 1)
					{
						Band * Band1;
						Band1 = As->getBand();
						Band1->setGeschwindigkeit(100);

					}
					else if (Zahl2int == 2)
					{
						Ofen * Ofen1;
						Ofen1 = As->getOfen();
						Ofen1->setTemperatur(100);
					}
					else if (Zahl2int == 3)
					{
						Ofen * Ofen1;
						Ofen1 = As->getOfen();
						Ofen1->setTemperatur(100);
					}

					Operator_Bool = true; break; //Simulation Test (2a - Aendern Geschwindigkeit 2b - Aendern Temperatur, 2c - Aendern Zeit)  " << endl;
				}
				case 3:
				{
					// Simulation Flags Test (3a - Zutaten, 3b - Verzierung, 3c - Teig, 3d - Teigroesse,3e - BlechAusfuelung)  " << endl;
					rezept* rezepteinlesen = erstelleRezept();
					lagerVerwaltung * lgVerwaltung = new lagerVerwaltung();
					cout << "Der Aktuelle Lagebestand: " << endl;
					lgVerwaltung->lagerBestandAnzeigen();
					cout << " Wird gepruefe, ob genug Zutaten und Verzierungen gibt. Falls ja, wird die zu produzierenden Menge von der Lager abgezogen kann!" << endl;

					lgVerwaltung->pruefeLageBestand(rezepteinlesen->getZutatMenge(), rezepteinlesen->getVerzierungsMenge());
					lgVerwaltung->bestellMengeAbziehenLage(rezepteinlesen->getZutatMenge(), rezepteinlesen->getVerzierungsMenge());
					cout << "Anzeige der aktuelle lagebestand: " << endl;
					lgVerwaltung->lagerBestandAnzeigen();
					
					divider();
					
					Operator_Bool = true; break;
				}
				case 4:
					// Simulation Bestand im Lager - Flags Test ()  " << endl;
				case 5:
					JaNa = true; Operator_Bool = true; break; // Ausgang
				default:
					cout << "Falsche Angaben, bitte versuchen Sie es noch einmal ..." << endl; Operator_Bool = true; break;
				}
			}
			Operator_Bool = false;
			////Cleaning
			Zahl1int = 0;
			Zahl2int = 0;
			cin.clear();
			// clean the screen
			//clear();
		} while (!JaNa);

		return 0;
	}

	catch (exception& e)
	{
		cout << "Unbekannte Fehler in Main ..." << &e << endl;
		return 0;
	}
}

int ProzessSteuerungMethod(int Zahl1int, int Zahl2int)
{
	try
	{
		bool ZusammenfassungState;
		bool StatusTemperatur;
		bool StatusSpeed;

		As->JobQueueStatus = Zahl2int;
		ParameterListe * PL1;
		PL1 = As->getParameterListe();


		Band * Band1;
		Band1 = As->getBand();
		Band1->setGeschwindigkeit(100);

		Ofen * Ofen1;
		Ofen1 = As->getOfen();
		Ofen1->setTemperatur(100);

		OfenSteuerung * OfenSteuerung1;
		OfenSteuerung1 = As->getOfenSteuerung();

		//ZusammenfassungState = PL1->ZusammenfassungFunc();
		StatusTemperatur = OfenSteuerung1->OfenTemperaturStatus();
		StatusSpeed = Band1->GetGeschwindigkeitStatus();

		StatusSpeed = true;

		//if ((ZusammenfassungState == true) && (StatusTemperatur == true) && (StatusSpeed == true))
		while ((ZusammenfassungState = true) && (StatusTemperatur = true) && (StatusSpeed = true))
		{
			std::cout << "While States (ZusammenfassungState << StatusTemperatur << StatusSpeed) - " << ZusammenfassungState << StatusTemperatur << StatusSpeed << endl;
			//cls();

			ZusammenfassungState = PL1->ZusammenfassungFunc();
			StatusTemperatur = OfenSteuerung1->OfenTemperaturStatus();
			StatusSpeed = Band1->GetGeschwindigkeitStatus();
			//cout << "As.JobQueueStatus ..." << As.JobQueueStatus << endl;

			switch (As->JobQueueStatus)
			{
			case 0: As->Backen(40); As->JobQueueStatus = 999; Zahl1int = 999; Zahl2int = 999; break; // Backen

			default: break;
			}
		}

		return 0;

	}
	catch (exception& e)
	{
		cout << "Unbekannte Fehler" << &e << endl;
		return 0;
	}
}

void COUTFuncIntro()
{
	string Smain;

	wstringstream titleStream;
	titleStream << "Grossbaeckerei Interactive Session Helper v.0.1a" << Smain.c_str();
	SetConsoleTitle(titleStream.str().c_str());

	divider();

	cout << "Grossbaeckerei Interactive Session Helper: " << endl;
	cout << "" << endl;
	cout << "          (" << endl;
	cout << "           )" << endl;
	cout << "      __..--- ..__" << endl;
	cout << " ,--='  /  |  \\  `=--." << endl;
	cout << ":---..___________..---;" << endl;
	cout << "\\.,. _____________,../" << endl << endl;
	cout << "1.Backen                        : 1a - Backen " << endl;
	cout << "2.Simulation Test               : 2a - Aendern Geschwindigkeit, 2b - Aendern Temperatur, 2c - Aendern Zeit" << endl;
	cout << "3.Simulation Flags Test         : 3a - Zutaten, 3b - Verzierung, 3c - Teig, 3d - Teigroesse,3e - BlechAusfuelung" << endl;
	cout << "4.Simulation Bestand im Lager   : - Flags Test ()  " << endl;
	cout << "5.Exit                          : 5a Exit" << endl;
	cout << "Bitte die Nummer eingeben       :  " << endl;

	divider();
}
rezept* erstelleRezept()
{
	rezept* schokoPlaetzchen = new rezept("Schokokeks", 100.0, "Kreis", "mittel", 180.0, 40.0);
	schokoPlaetzchen->addZutat(new zutat("Backpulver", 100.0, "g"));
	schokoPlaetzchen->addZutat(new zutat("Eier", 0.9, "l"));
	schokoPlaetzchen->addZutat(new zutat("Kakao", 700.0, "g"));
	schokoPlaetzchen->addZutat(new zutat("Mehl", 900.0, "g"));
	schokoPlaetzchen->addZutat(new zutat("Milch", 4.0, "l"));
	schokoPlaetzchen->addZutat(new zutat("Pflanzenfett", 500.0, "g"));
	schokoPlaetzchen->addZutat(new zutat("Zucker", 1000.0, "g"));
	schokoPlaetzchen->addVerzierung(new zutat("Kakaoguss", 0.3, "l"));
	schokoPlaetzchen->addVerzierung(new zutat("Schokostreusel", 300.0, "g"));
	return schokoPlaetzchen;
}