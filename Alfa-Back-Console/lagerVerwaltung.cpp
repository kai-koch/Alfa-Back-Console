#include "stdafx.h"
#include "lagerVerwaltung.h"
#include <iostream>

using namespace std;

void lagerVerwaltung::setEingangwareVerzierungen(zutat* eingangswareVerzierungen)
{
	lagerBestandVezgen.insert(pair<string, zutat*>(eingangswareVerzierungen->getName(), eingangswareVerzierungen));
}

void lagerVerwaltung::setEinganswareZutaten(zutat* eingangswareZutaten)
{
	lagerBestandZt.insert(pair<string, zutat*>(eingangswareZutaten->getName(), eingangswareZutaten));
}

bool lagerVerwaltung::pruefeLageBestand(map<string,zutat*> zutatMenge, map<string, zutat*> verzierungMenge)
{
	bool lageZustandZutat{ true }, lageZustandVerzierungen{ true };
	// Schleife zu ueberpruefen von Verfuegbarkeit des Zutaten Bestandes
	for (map<string, zutat*>::iterator it = zutatMenge.begin(); it != zutatMenge.end(); it++)
	{
		string name = it->second->getName();
		cout << " name gesucht zutat " << name << endl;
		double  menge = lagerBestandZt.find(name)->second->getMenge();
		cout << " suchende menge " << menge<<endl;
		if (it->second->getMenge()<=menge)
		{
			lageZustandZutat = true;
		}	
		else 
		{
			lageZustandZutat = false;
		}
	}
	cout << "zutat geprueft " << endl<< endl;
	// Schleife zu ueberpruefen von Verfuegbarkeit der Verzierungen Bestandes
	for (map<string, zutat*>::iterator it = verzierungMenge.begin(); it != verzierungMenge.end(); it++)
	{
		string name = it->second->getName();
		cout << " name gesucht zutat " << name << endl;
		double  menge = lagerBestandVezgen.find(name)->second->getMenge();
		if(menge >= (it->second)->getMenge())
		{
			lageZustandVerzierungen = true;
		}
		else
		{
			lageZustandVerzierungen = false;
		}
	}
	cout << " vorhandene bestell menge in der lage " << (lageZustandZutat & lageZustandVerzierungen) << endl << endl;
	return (lageZustandZutat&lageZustandVerzierungen);
}
//Bestellmenge von der Lage abziehen, falls genug ware da ist.
void lagerVerwaltung::bestellMengeAbziehenLage(map<string, zutat*> zutatMenge, map<string, zutat*> verzierungMenge)
{
	bool pruefe = pruefeLageBestand(zutatMenge, verzierungMenge);
	if(pruefe)
	{
	for (map<string, zutat*>::iterator it = zutatMenge.begin(); it != zutatMenge.end(); it++)
	{
		string name = it->second->getName();
		double menge = lagerBestandZt.find(name)->second->getMenge();
		lagerBestandZt[name]->setMenge((menge - (it->second->getMenge())));
	}
	for (map<string, zutat*>::iterator it = verzierungMenge.begin(); it != verzierungMenge.end(); it++)
	{
		string name = it->second->getName();
		double menge = lagerBestandVezgen.find(name)->second->getMenge();
		lagerBestandVezgen[name]->setMenge((menge - (it->second->getMenge())));
	}
	}
	else
	{
		cout<<" nicht genug Ware in der Lage bitte nach bestellen!!"<<endl; 
	}
}

void lagerVerwaltung::lagerBestandAnzeigen()
{
	for (map<string, zutat*>::iterator it = lagerBestandZt.begin(); it != lagerBestandZt.end(); it++)
	{
		cout << "Menge an Zutaten: " << (it->second)->getName() << " ist " << (it->second)->getMenge() << endl;
	}
	for (map<string, zutat*>::iterator it = lagerBestandVezgen.begin(); it != lagerBestandVezgen.end(); it++)
	{
		cout << "Menge an Verzierungen: " << (it->second)->getName() << " ist " << (it->second)->getMenge() << endl;
	}
}

lagerVerwaltung::lagerVerwaltung(map<string, zutat*> lagerBestandZutaten, map<string, zutat*> lagerBestandVerzierungen)
{
    lagerBestandZt = lagerBestandZutaten;
    lagerBestandVezgen = lagerBestandVerzierungen;
}

lagerVerwaltung::lagerVerwaltung()
{
    fillLager();
}


