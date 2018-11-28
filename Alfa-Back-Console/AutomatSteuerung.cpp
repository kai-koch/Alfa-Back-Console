#include "stdafx.h"
#include "AutomatSteuerung.h"
#include <iostream>
#include <string>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <sstream>
using namespace std;
#include "addons.h"
#include "Band.h"
#include "Ofen.h"
#include "AusnahmenUndThreadsMon.h"
#include "ParameterListe.h"


AutomatSteuerung::AutomatSteuerung()
{

/*
	Ofn = new Ofen();
	Bnd = new Band();
	AM = new AusnahmenUndThreadsMon();
	PL = new ParameterListe();
	OfnSu = new OfenSteuerung();*/

}


AutomatSteuerung::~AutomatSteuerung()
{

}

void AutomatSteuerung::plaetzchenAnzahlErmitteln()
{
}

void AutomatSteuerung::blechAnzahlErmitteln()
{
}

void AutomatSteuerung::blechBelegen()
{
}

void AutomatSteuerung::Backen(int Zeit)
{
	divider();

	if (BackProzessTimerStatus == false)
	{
		BackProzessTimerStatus = true;

	std::queue<int> BackProzessTimerBenachrichtigung;
	std::mutex Backen_mutex;
	std::condition_variable cond_Backen;
	bool gemacht = false;
	bool informiert = false;
	bool ZusammenfassungState = true;
	double progress = 0.0; //float
	int ZeitMapping;
	//double EventStatus1;
	string S;
	int intStern = 0;


	std::thread BackProzessTimer([&]() {
		

		ZeitMapping = (Zeit * 2) + 20;

		cout << "AutomatSteuerung::Backen(int Zeit) - Mixing (Kneten) und Dividing(Portionieren) - " << 20 << endl;

		for (int ia = 0; ia < 20; ++ia)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::unique_lock<std::mutex> lock(Backen_mutex);
			BackProzessTimerBenachrichtigung.push(ia);
			informiert = true;
			cond_Backen.notify_one();
		}


		cout << "AutomatSteuerung::Backen(int Zeit) - Der Kuchen wird gebacken - " << Zeit << endl;
		
		for (int i = 0; i < Zeit; ++i)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::unique_lock<std::mutex> lock(Backen_mutex);
			BackProzessTimerBenachrichtigung.push(i);
			informiert = true;
			cond_Backen.notify_one();
		}

		cout << "AutomatSteuerung::Backen(int Zeit) - Cooling(Kühlen) und Finisching(Bezuckern) - " << (Zeit * 2) << endl << '\n';

		for (int ib = 0; ib < 20; ++ib)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::unique_lock<std::mutex> lock(Backen_mutex);
			BackProzessTimerBenachrichtigung.push(ib);
			informiert = true;
			cond_Backen.notify_one();
		}

		Bnd->setGeschwindigkeit(0);

		cls();

        std::cout << "Event BackZeit " << ZeitMapping << '\n';
		BackProzessTimerBenachrichtigung.push(ZeitMapping);
		gemacht = true;
		informiert = true;
		cond_Backen.notify_one();
	});

	std::thread BackProzessTimerNotifer([&]() {
		std::unique_lock<std::mutex> lock(Backen_mutex);
		while (!gemacht) {
			while (!informiert) {  // Schleife, um störendes Aufwecken zu vermeiden
				cond_Backen.wait(lock);
			}
			while (!BackProzessTimerBenachrichtigung.empty())
			{
				//std::cout << "Backprozess erfolgreich beendet - " << BackProzessTimerBenachrichtigung.front() << " - Minuten" << endl;
				///////////////////////////////////////////////////////////////////////
					S.clear();
					S.append("Backprozess erfolgreich beendet - ");
					S.append(std::to_string(BackProzessTimerBenachrichtigung.front()));
					S.append(" - Minuten  ");
					if (intStern == 0) { intStern = 1; S.append(" / "); }
					else if (intStern == 1){ intStern = 2; S.append(" - "); }
					else if (intStern == 2){ intStern = 3; S.append(" \\ "); }
					else if (intStern == 3){ intStern = 4; S.append(" / "); }
					else if (intStern == 4) { intStern = 5;  S.append(" - "); }
					else if (intStern == 5) { intStern = 0;  S.append(" \\ "); }

					///////////////////////////////////////////////////////////////////////

					wstringstream titleStream;
					titleStream << "Counting to " << S.c_str();
					SetConsoleTitle(titleStream.str().c_str());

					///////////////////////////////////////////////////////////////////////
					if (progress < 1.0)
					{
						int BackProgressGroese = 70;

						std::cout << "[";
						int pos = static_cast<int>(BackProgressGroese * progress); //int 13.15 27 November
						for (int i = 0; i < BackProgressGroese; ++i) {
							if (i < pos) std::cout << "=";
							else if (i == pos) std::cout << "|>";
							else std::cout << " ";
						}
						std::cout << "] " << int(progress * 100.0) << " %\r"; //
						//std::cout.flush();

						progress += static_cast<double>(1) / ZeitMapping;
					}
//					else 

					//std::cout << std::endl;
					//////////////////////////////////////////////////////////////////////////////////

				//std::cout << std::endl;
				//////////////////////////////////////////////////////////////////////////////////

				BackProzessTimerBenachrichtigung.pop();
			}
			informiert = false;
		
		}
	});

	BackProzessTimerStatus = false; // Nur 1 Prozess Lock

	BackProzessTimer.join(); //join();
	BackProzessTimerNotifer.join(); //detach();

	
	/*detach() Trennt den Ausführungs - Thread vom Thread - Objekt wodurch dieser unabhängig 
	fortgeführt werden kann.Alle zugewiesenen Ressourcen werden freigegeben 
	sobald der Thread endet.

		Nach dem Aufruf von detach() gelten folgende Bedingungen :

	*this hält keinen Thread mehr
		joinable() == false
		get_id() == std::thread::id()*/

	} // If 

	divider();

	//return true;
}

void AutomatSteuerung::Abkuehlen(int)
{

// Rechnen fürs das Abkuehlen

}

void AutomatSteuerung::Verzierungen()
{

// Rechnen fürs das Verzierung

}

void AutomatSteuerung::VerweilDauerBestimmen()
{



}


void AutomatSteuerung::InitClassen(AutomatSteuerung * As)
{

	Ofen * OfenInit = new Ofen();
	As->setOfen(OfenInit);

	Band * BandInit = new Band();
	As->setBand(BandInit);

	AusnahmenUndThreadsMon * AusnahmenUndThreadsMonInit = new AusnahmenUndThreadsMon();
	As->setAusnahmenUndThreadsMon(AusnahmenUndThreadsMonInit);

	ParameterListe * ParameterListeInit = new ParameterListe();
	As->setParameterListe(ParameterListeInit);

	OfenSteuerung * OfenSteuerungInit = new OfenSteuerung();
	As->setOfenSteuerung(OfenSteuerungInit);

	AusnahmenUndThreadsMon * ATM;
	ATM = As->getAusnahmenUndThreadsMon();
	ATM->setAutomatSteuerungPointer(As);

	OfenSteuerung * OfenSteuerung2;
	OfenSteuerung2 = As->getOfenSteuerung();
	OfenSteuerung2->setAutomatSteuerungPointer(As);

	ParameterListe * PL2;
	PL2 = As->getParameterListe();
	PL2->setAutomatSteuerungPointer(As);

	std::thread tw1 = ATM->StartThreadAusnahmeMonitor();
	tw1.detach();
	//thread PSMthread2(&AusnahmenUndThreadsMon::StartAusnahmenMonitor(), AusnahmenUndThreadsMon());
	//PSMthread2.detach(); //AusnahmenUndThreadsMon ATM; // Thread Lock Erstellen oder aus DO verschieben

}

void AutomatSteuerung::InitDelete(AutomatSteuerung * As)
{

	delete Ofn;
	delete Bnd;
	delete AM;
	delete PL;
	delete OfnSu;

}

Ofen * AutomatSteuerung::getOfen()
{
	return Ofn;
}

Band * AutomatSteuerung::getBand()
{
	return Bnd;
}

AusnahmenUndThreadsMon * AutomatSteuerung::getAusnahmenUndThreadsMon()
{
	return AM;
}

ParameterListe * AutomatSteuerung::getParameterListe()
{
	return PL;
}

OfenSteuerung * AutomatSteuerung::getOfenSteuerung()
{
	return OfnSu;
}

void AutomatSteuerung::setOfen(Ofen * Ofn1)
{
	Ofn = Ofn1;
}

void AutomatSteuerung::setBand(Band * Bnd1)
{
	Bnd = Bnd1;
}

void AutomatSteuerung::setAusnahmenUndThreadsMon(AusnahmenUndThreadsMon * ATM1)
{
	AM = ATM1;
}

void AutomatSteuerung::setParameterListe(ParameterListe * PL1)
{
	PL = PL1;
}

void AutomatSteuerung::setOfenSteuerung(OfenSteuerung * setOfSteu1)
{
	OfnSu = setOfSteu1;
}
