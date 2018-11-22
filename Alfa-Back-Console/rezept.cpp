#include "stdafx.h"
#include "rezept.h"

rezept::rezept(string teigName, double plaetzchenAnzahl, string form, double xGroesse, double yGroesse, double backTemperatur, double backZeit)
{
	tgName = teigName;
	basisAnzahlPlaetzchen = plaetzchenAnzahl;
	plaetzchenForm = form;
	xBetrag = xGroesse;
	yBetrag = yGroesse;
	backTemp = backTemperatur;
	backZt = backZeit;
}

void rezept::addZutat(zutat  ingredient)
{

	zutaten->insert(pair<string, zutat>(ingredient.getName(), ingredient));
}

void rezept::addVerzierung(zutat ingredient)
{
	verzierungen->insert(pair<string, zutat>(ingredient.getName(), ingredient));
}

string rezept::getKonfigdatei(int totalAnzahlKekse)
{
	double rezeptfactor = totalAnzahlKekse / basisAnzahlPlaetzchen;
	return "";
}

string rezept::getTeigName()
{
	return tgName;
}

double rezept::getBasisPlaetzchenAnzahl()
{
	return basisAnzahlPlaetzchen;
}

string rezept::getForm()
{
	return plaetzchenForm;
}

double rezept::getXBetrag()
{
	return xBetrag;
}

double rezept::getYBetrag()
{
	return yBetrag;
}

double rezept::getBackTemperatur()
{
	return backTemp;
}

double rezept::getBackZeit()
{
	return backZt;
}
