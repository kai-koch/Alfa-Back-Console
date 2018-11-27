#include "stdafx.h"
#include "lagerVerwaltung.h"
#include <iostream>
using namespace std;
/*
void lagerVerwaltung::setEingangwareVerzierungen(map<string, zutat>::iterator it, double menge)
{
	lagerBestandVerzierungen.insert(map<string,double menge>)
	//it->second.setMenge(menge);
}

void lagerVerwaltung::setEinganswareZutaten(map<string, zutat>::iterator it, double menge)
{
}
*/
lagerVerwaltung::lagerVerwaltung(map<string, zutat> lagerBestandZutaten, map<string, zutat> lagerBestandVerzierungen)
{
	lagerBestandZt=lagerBestandZutaten;
	lagerBestandVezgen=lagerBestandVerzierungen;

}
void lagerVerwaltung::setEingangwareVerzierungen(zutat eingangswareVerzierungen)
{
	lagerBestandVezgen.insert(pair<string, zutat>(eingangswareVerzierungen.getName(), eingangswareVerzierungen));
}

void lagerVerwaltung::setEinganswareZutaten(zutat eingangswareZutaten)
{
	lagerBestandZt.insert(pair<string, zutat>(eingangswareZutaten.getName(), eingangswareZutaten));
}

bool lagerVerwaltung::pruefeLageBestand(map<string,zutat> zutatMenge, map<string, zutat> verzierungMenge)
{
	// iterator zu durchgehen von Zutatmenge map
	map<string, zutat> ::iterator it_zutatMenge = zutatMenge.begin();
	// iterator zu durchgehen von Verzierungmenge map
	map<string, zutat> ::iterator it_verzierungMenge = verzierungMenge.begin();

	bool lageZustandZutat{ true }, lageZustandVerzierungen{true};
	// Schleife zu ueberpruefen von Verfuegbarkeit des Zutaten Bestandes
	for (map<string, zutat>::iterator it = lagerBestandZt.begin(); it != lagerBestandZt.end(); it++)
	{
		if ((it->second).getMenge() >= (it_zutatMenge->second).getMenge())
		{
			lagerBestandZt[it->first].setMenge( ( ( (it->second).getMenge()) - (it_zutatMenge->second).getMenge() )   );
		}
		else
		{
			lageZustandZutat = false;
		}
	}
	// Schleife zu ueberpruefen von Verfuegbarkeit der Verzierungen Bestandes
	for (map<string, zutat>::iterator it = lagerBestandVezgen.begin(); it != lagerBestandVezgen.end(); it++)
	{
		if ((it->second).getMenge() >= (it_verzierungMenge->second).getMenge())
		{
			lagerBestandVezgen[it->first].setMenge( ((it->second).getMenge()) - ((it_verzierungMenge->second).getMenge()));
		}
		else
		{
			lageZustandVerzierungen = false;
		}
	}

	return (lageZustandZutat&lageZustandVerzierungen);
}

void lagerVerwaltung::lagerBestandAnzeigen()
{
	for (map<string, zutat>::iterator it = lagerBestandZt.begin(); it != lagerBestandZt.end(); it++)
	{
		cout << "Menge an Verzierungsorte " << (it->second).getName() << " ist " << (it->second).getMenge() << endl;
	}
	for (map<string, zutat>::iterator it = lagerBestandVezgen.begin(); it != lagerBestandVezgen.end(); it++)
	{
		cout << "Menge an Zutaten Sorte " << (it->second).getName() << " ist " << (it->second).getMenge() << endl;
	}
}


