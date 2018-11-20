#include "stdafx.h"
#include "AutomatSteuerung.h"
#include <iostream>
#include <string>
using namespace std;
#include "addons.h"

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
	cout << "AutomatSteuerung::Backen(int Zeit) - Der Kuchen wird gebacken - " << Zeit << endl;
	std::this_thread::sleep_for(std::chrono::seconds(Zeit));
	cout << "Zeit abgelaufen" << Zeit << endl;
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
