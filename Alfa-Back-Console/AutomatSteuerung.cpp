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
using namespace std;
#include "addons.h"
#include "Band.h"

AutomatSteuerung::AutomatSteuerung()
{

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
	std::queue<int> BackProzessTimerBenachrichtigung;
	std::mutex Exception_mutex;
	std::condition_variable cond_Backen;
	bool gemacht = false;
	bool informiert = false;
	bool ZusammenfassungState = true;

	std::thread BackProzessTimer([&]() {

		while (BackProzessTimerStatus = true)
		{
			
			cout << "AutomatSteuerung::Backen(int Zeit) - Der Kuchen wird gebacken - " << Zeit << endl << endl;
			std::this_thread::sleep_for(std::chrono::seconds(Zeit));

			BackProzessTimerStatus = false;
			//if Test Condition
			Band Bnd;
			Bnd.setGeschwindigkeit(0);

			if (BackProzessTimerStatus == false)
			{
				std::unique_lock<std::mutex> lock(Exception_mutex);
				std::cout << "Zeit abgelaufen - " << Zeit << " - Minuten" << endl;
				BackProzessTimerBenachrichtigung.push(Zeit);
				informiert = true;
				gemacht = true;
				cond_Backen.notify_one();

			}
			//if Test Matrix Condition
		}

		//gemacht = true;
		informiert = true;
		cond_Backen.notify_one();
	});

	std::thread BackProzessTimerNotifer([&]() {
		std::unique_lock<std::mutex> lock(Exception_mutex);
		while (!gemacht) {
			while (!informiert) {  // Schleife, um störendes Aufwecken zu vermeiden
				cond_Backen.wait(lock);
			}
			while (!BackProzessTimerBenachrichtigung.empty()) {
				std::cout << endl << "Backprozess erfolgreich beendet - " << BackProzessTimerBenachrichtigung.front() << " - Minuten" << endl;
				BackProzessTimerBenachrichtigung.pop();
			}
			informiert = false;
		}
	});

	BackProzessTimer.join();
	BackProzessTimerNotifer.join(); //detach();

	//return true;
}

void AutomatSteuerung::Abkuehlen(int)
{
}

void AutomatSteuerung::Verzierungen()
{
}

void AutomatSteuerung::VerweilDauerBestimmen()
{
}
