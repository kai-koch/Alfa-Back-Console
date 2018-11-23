#include "stdafx.h"
#include "lagerVerwaltung.h"
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
void lagerVerwaltung::setEingangwareVerzierungen(zutat eingangswareVerzierungen)
{
	lagerBestandVerzierungen.insert(pair<string, zutat>(eingangswareVerzierungen.getName(), eingangswareVerzierungen));
}

void lagerVerwaltung::setEinganswareZutaten(zutat eingangswareZutaten)
{
	lagerBestandZutaten.insert(pair<string, zutat>(eingangswareZutaten.getName(), eingangswareZutaten));
}

bool lagerVerwaltung::pruefeLageBestand()
{
	// iterator zu durchgehen von Zutatmenge map
	map<string, zutat> ::iterator it_zutatMenge = zutatMenge.begin();
	// iterator zu durchgehen von Verzierungmenge map
	map<string, zutat> ::iterator it_verzierungMenge = verzierungMenge.begin();

	bool lageZustandZutat{ true }, lageZustandVerzierungen{true};
	// Schleife zu ueberpruefen von Verfuegbarkeit des Zutaten Bestandes
	for (map<string, zutat>::iterator it = lagerBestandZutaten.begin(); it != lagerBestandZutaten.end(); it++)
	{
		if ((it->second).getMenge() >= (it_zutatMenge->second).getMenge())
		{
			lagerBestandZutaten[it->first].setMenge( ( ( (it->second).getMenge()) - (it_zutatMenge->second).getMenge() )   );
		}
		else
		{
			lageZustandZutat = false;
		}
	}
	// Schleife zu ueberpruefen von Verfuegbarkeit der Verzierungen Bestandes
	for (map<string, zutat>::iterator it = lagerBestandVerzierungen.begin(); it != lagerBestandVerzierungen.end(); it++)
	{
		if ((it->second).getMenge() >= (it_verzierungMenge->second).getMenge())
		{
			lagerBestandVerzierungen[it->first].setMenge( ((it->second).getMenge()) - ((it_verzierungMenge->second).getMenge()));
		}
		else
		{
			lageZustandVerzierungen = false;
		}
	}

	return (lageZustandZutat&lageZustandVerzierungen);
}
