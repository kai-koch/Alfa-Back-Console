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

void rezept::addZutat(zutat*  ingredient)
{

	zutaten.insert(pair<string, zutat*>(ingredient->getName(), ingredient));
}

void rezept::addVerzierung(zutat* ingredient)
{
	verzierungen.insert(pair<string, zutat*>(ingredient->getName(), ingredient));
}

rezept* rezept::getKonfigdatei()
{
	rezept* schokoPlaetzchen = new rezept("Schokokeks", 100.0, "Kreis", "mittel", 180.0, 40.0);
	schokoPlaetzchen->addZutat(new zutat("Backpulver", 100.0, "g"));
	schokoPlaetzchen->addZutat(new zutat("Eier", 0.9, "l"));
	schokoPlaetzchen->addZutat(new zutat("Kakao", 700.0, "g"));
	schokoPlaetzchen->addZutat(new zutat("Mehl", 900.0, "g"));
	schokoPlaetzchen->addZutat(new zutat("Milch", 4.0, "l"));
	schokoPlaetzchen->addZutat(new zutat("Pflanzenfett", 500.0, "g"));
	schokoPlaetzchen->addZutat(new zutat("Zucker", 1000.0, "g"));
	schokoPlaetzchen->addVerzierung(new zutat("Kakaoguss", 0.3, "l"));
	schokoPlaetzchen->addVerzierung(new zutat("Schokostreusel", 300.0, "g"));
	return schokoPlaetzchen;
}

string rezept::toString()
{

    vector<string> config;
    config[0] = "teigname:" + getTeigName();
    config[1] = "basisAnzahl:" +  to_string(getBasisPlaetzchenAnzahl());
    config[2] = "form:" + getForm();
    config[3] = "groesse:" + getPlaetzchenGroesse();
    config[4] = "backTemperatur:" + to_string(getBackTemperatur());
    config[5] = "backZeit:" + to_string(getBackZeit());
    config[6] = getZutatenWriteStr();
    config[7] = getVerzierungenWriteStr();
    return werkzeuge::join("\t", config);

    return string();
}

void rezept::setTeigname(string tn)
{
    tgName = tn;
}

void rezept::setAnzahl(double anz)
{
    basisAnzahlPlaetzchen = anz;
}

void rezept::setForm(string frm)
{
    plaetzchenForm = frm;
}

void rezept::setGroesse(string gr)
{
    plaetzchenGroesse = gr;
}

void rezept::setBacktemperatur(double temp)
{
    backTemp = temp;
}

void rezept::setBackzeit(double zeit)
{
    backZt = zeit;
}

string rezept::getZutatenWriteStr()
{
    vector<string> zuts;
    int i = 0;
    for (std::map<string, zutat*>::iterator it = zutaten.begin(); it != zutaten.end(); ++it)
    {
        zuts[i] = it->second->toString();
        i += 1;
    }

    return "Zutaten:" + werkzeuge::join("|", zuts);
}

string rezept::getVerzierungenWriteStr()
{
    vector<string> zuts;
    int i = 0;
    for (std::map<string, zutat*>::iterator it = verzierungen.begin(); it != verzierungen.end(); ++it)
    {
        zuts[i] = it->second->toString();
        i += 1;
    }

    return "Verzierungen:" + werkzeuge::join("|", zuts);
}

map<string, zutat*> rezept::getZutatMenge()
{
	return zutaten;
}

map<string, zutat*> rezept::getVerzierungsMenge()
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

rezept::rezept() {}

rezept::~rezept() {}
