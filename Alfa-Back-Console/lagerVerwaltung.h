#pragma once
#include <vector>
#include <string>
#include <map>
#include "zutat.h"
#include "rezept.h"
using namespace std;
class lagerVerwaltung
{
private: 
		// Objekt der klasse rezept instanziert
		rezept * rezeptObj = new rezept();
		// ablesen und speichern der map zutat
		map<string, zutat> zutatMenge = (rezeptObj->geMaptZutatMenge());
		map<string, zutat> verzierungMenge = (rezeptObj->getVerzierungsMenge());
		// eine map zur Lagerhaltung von zutaten
		 map<string, zutat> lagerBestandZutaten;
		 // eine map zur Lagerhaltung von Verzierungen
		 map<string, zutat> lagerBestandVerzierungen;

public:
	/**
	*Registrierung von Eingang von Zutaten im Lageverwaltung 
	*/
	void setEingangwareVerzierungen(zutat lagerBestandVerzierungen);
	/**
	*Registrierung von Eingang von Zutaten im Lageverwaltung
	*/
	void setEinganswareZutaten(zutat lagerBestandVerzierungen);
	/**
	*Registrierung von Eingang von Zutaten im Lageverwaltung
	*/
	bool pruefeLageBestand();

};