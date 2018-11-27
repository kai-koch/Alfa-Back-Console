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
	// eine map zur Lagerhaltung von zutaten mit Initialisierte werte
	map<string, zutat> lagerBestandZt = { {"Backpulver", { "Backpulver", 1000.0, "g" }},
										{"Eier",{ "Eier", 1000, "l" }},
										{ "Mehl",{ "Mehl",50000, "g" } },
										{ "Milch",{ "Milch", 100, "l" } },
										{ "Pflanzenfett",{ "Pflanzenfett", 500, "l" } },
										{ "Zitronenpulver",{ "Zitronenpulver", 10000, "g" } },
										{"Rum",{"Rum", 100, "l" }},
										{"Vanillinzucker",{"Vanillinzucker",10000, "g" }},
										{"Kakao",{ "Kakao", 10000, "g" }}
	};
	// eine map zur Lagerhaltung von Verzierungen mit Initialisierungswerte
	map<string, zutat> lagerBestandVezgen =			{ { "Kakaoguss",{"Kakaoguss", 100, "l" }},
													{ "Schokostreusel",{ "Schokostreusel", 10000, "g" } },
													{ "Zuckerstreusel(bunt)",{ "Zuckerstreusel(bunt)", 10000, "g" } },
													{ "Zitronenguss",{ "Zitronenguss", 100, "l" } },
													{ "Zimt",{ "Zimt", 10000, "g" } },
													{ "Zitronenpulver",{ "Zitronenpulver", 10000, "g" } },
													{ "Kakaoguss",{ "Kakaoguss", 100, "l" } },
													{ "Vanillinzucker",{ "Vanillinzucker",10000, "g" } },
													{ "Mandeln",{"Mandeln", 30000, "g"}},
													{ "Marmelade",{"Marmelade", 10, "l" }},
													{"Walnuesse",{"Walnuesse", 10000, "g" }},
													{ "Haselnuesse",{ "Haselnuesse", 10000, "g" } }
													};

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
	*Bestellmenge an Zutaten und Verzierungen mit Lagerzustand vergleichen
	*@Parameter  map ZutatBestellMenge
	*@Parameter map VerzierungsBestellmenge
	*/
	bool pruefeLageBestand(map<string, zutat> zutatMenge, map<string, zutat> verzierungMenge);
	/**
	* lagerbestand anzeigen lassen
	*/
	void lagerBestandAnzeigen();
	/**
	*Constructor
	*mit zwei maps zur Lagerverawltung lagerBestandZutaten und lagerBestandVerzierungen
	*/
	//lagerVerwaltung(map<string, zutat> lagerBestandZutaten, map<string, zutat> lagerBestandVerzierungen);
	lagerVerwaltung();
};