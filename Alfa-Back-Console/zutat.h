#pragma once
#include <string>
using namespace std;
class zutat
{
	/* Name der Zutat*/
private:	string name;
			/* Menge der Zutat*/
			double menge;
			/*Masseinheit der zutat g, Kg, l , ml,°C */
			string masseinheit;
public:
	/**
	* @constructor
	* @param zutatName Name der Zutat
	* @param zutatMenge Menge der Zutat
	* @param zutatEinheit Masseinheit der Zutat
	*/
	zutat(string zutatName, double zutatMenge, string zutatEinheit);
	/** Getter Name */
	string getName();
	/** Getter Menge */
	double getMenge();
	/** Getter Masseinheit */
	string getMasseinheit();
	/** Setter Menge */
	void setMenge(double ztMenge);

};
