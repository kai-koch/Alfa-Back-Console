#include "stdafx.h"
#include "rezept.h"
using namespace std;

rezept::rezept(string teigName, double plaetzchenAnzahl, string form, string groesse, double backTemperatur, double backZeit)
{
	tgName = teigName;
	basisAnzahlPlaetzchen = plaetzchenAnzahl;
	plaetzchenForm = form;
	plaetzchenGroesse = groesse;
	backTemp = backTemperatur;
	backZt = backZeit;
}

void rezept::addZutat(zutat  ingredient)
{

	zutaten.insert(pair<string, zutat>(ingredient.getName(), ingredient));
}

void rezept::addVerzierung(zutat ingredient)
{
	verzierungen.insert(pair<string, zutat>(ingredient.getName(), ingredient));
}

rezept rezept::getKonfigdatei()
{
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
	return *schokoPlaetzchen;
}

map<string, zutat> rezept::geMaptZutatMenge()
{
	return  zutaten;
}




map<string, zutat> rezept::getVerzierungsMenge()
{
	return verzierungen;
}

string rezept::getTeigName()
{
	return tgName;
}

double rezept::getBasisPlaetzchenAnzahl()
{
	return basisAnzahlPlaetzchen;
}

string rezept::getPlaetzchenGroesse()
{
	return string();
}

string rezept::getForm()
{
	return plaetzchenForm;
}

double rezept::getXBetrag( string groesse)
{
	
	
	if (groesse == "gross")
	{ 
		return 80;
	}
	else if (groesse == "mittel")
	{
		return 40;
	}
	else
	{
		return 20;
	}
	
	
	
}

double rezept::getYBetrag(string groesse)
{
	if (groesse == "gross")
	{
		return 80;
	}
	else if (groesse == "mittel")
	{
		return 40;
	}
	else
	{
		return 20;
	}
}

double rezept::getBackTemperatur()
{
	return backTemp;
}

double rezept::getBackZeit()
{
	return backZt;
}
/*
double rezept::plaetzchenGroesse(string groesse)
{
	return (getYBetrag(groesse)*getXBetrag(groesse));
}
*/

rezept::rezept()
{
}

rezept::~rezept()
{
}
