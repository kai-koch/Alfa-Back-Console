#pragma once
#include "zutat.h"
#include <map>
using namespace std;

/**
* Klasse Rezept um Teig- und Verzierungszusammensetzung  von der Konfiguration zu speichern
*/
class rezept
{
private:
	/**
	* Key: Zutatenname, Value: Instanz der Klasse Zutat fuer Basisanzahl
	* von Keksen
	*/
	map <string, zutat > * zutaten;

	/**
	* Key: Verzierungszutatenname, Value: Anzahl Einheiten benoetigt fuer
	* Basisanzahl
	* von Keksen
	*/
	map <string, zutat> * verzierungen;
	/** Name fuer Teig */
	string  tgName;
	/** Kantenlaenge x fuer Rechteck in das die Form eingepasst wird */
	double xBetrag;
	/**Anzahl der Plaetzchen*/
	double basisAnzahlPlaetzchen;
	/** form der Plaetzchen*/
	string plaetzchenForm;

	/** Kantenlaenge y fuer Rechteck in das die Form eingepasst wird */
	double yBetrag;
	/** Die Temperatur f�r backen in �C*/
	double backTemp;
	/** Die Backzeit in Minuten*/
	double backZt;
public:
	/**
	* Properties der Klasse setzen
	* @construktor
	* @param teigName Teigname
	* @param pleatzchenAnzahl Anzahl an Keksen die beim Grundrezept gestanzt werden koennen
	* @param form Form des Plaetzchens
	* @param xGroesse Kantenlaenge x
	* @param yGroesse Kantenlaenge Y
	* @param backTemperatur Backtemperatur
	* @param backZeit Backzeit
	*/
	rezept(string teigName, double pleatzchenAnzahl, string form, double xGroesse, double yGroesse, double backTemperatur, double backZeit);
	/**
	* Fuegt eine Zutat mit Mengenangabe zur Zutatenliste hinzu
	* @param name Name der Zutat
	* @param einheiten Anzahl der Einheiten, die fuer Rezept benoetigt werden
	*/
	void addZutat(zutat ingredient);
	/**
	* Fuegt eine Verzierungszutat mit Mengenangabe zur Verzierungszutatenliste
	* hinzu
	* @param name Name der Zutat
	* @param einheiten Anzahl der Einheiten, die fuer Rezept benoetigt werden
	*/
	void addVerzierung(zutat ingredient);
	/**
	* Berechnet die Zutatenmenge fuer die Menge an gewuenschten Keksen
	* und gibt den String fuer die Konfigurationsdatei zurueck
	* @param totalAnzahlKekse Anzahl der Kekse, die gebacken werden sollen
	*/
	string getKonfigdatei(int  totalAnzahlKekse);
	string getTeigName();
	double getBasisPlaetzchenAnzahl();
	string getForm();
	double getXBetrag();
	double getYBetrag();
	double getBackTemperatur();
	double getBackZeit();

};