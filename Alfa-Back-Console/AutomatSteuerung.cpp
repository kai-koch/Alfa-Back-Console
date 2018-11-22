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
	std::mutex Backen_mutex;
	std::condition_variable cond_Backen;
	bool gemacht = false;
	bool informiert = false;
	bool ZusammenfassungState = true;

	std::thread BackProzessTimer([&]() {
		//BackProzessTimerStatus
		cout << "AutomatSteuerung::Backen(int Zeit) - Der Kuchen wird gebacken - " << Zeit << endl << endl;
		
		for (int i = 0; i < Zeit; ++i)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::unique_lock<std::mutex> lock(Backen_mutex);
			BackProzessTimerBenachrichtigung.push(i);
			informiert = true;
			cond_Backen.notify_one();
		}

		Band Bnd;
		Bnd.setGeschwindigkeit(0);

        std::cout << "Event BackZeit " << Zeit << '\n';
		BackProzessTimerBenachrichtigung.push(Zeit);
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
			while (!BackProzessTimerBenachrichtigung.empty()) {
				std::cout << "Backprozess erfolgreich beendet - " << BackProzessTimerBenachrichtigung.front() << " - Minuten" << endl;
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
