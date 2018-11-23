#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <shlwapi.h>
#include <algorithm>
#include <thread>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include "AutomatSteuerung.h"
using namespace std;


class ParameterListe : public AutomatSteuerung // Status 3
{
	struct Param
	{
		bool ZutatenBool = false;
		bool VerzierungBool = true;
		bool TeigBool = true;
		bool FormBool = false;
		bool TeigGroesseBool = false;
		bool TeigSorteBool = true;
		bool ConfigFileBool = false;
		bool BlechAusFuellungBool = true;
	};
	Param my_Param;

	enum Errors
	{
		Zutaten,
		Verzierung,
		Teig,
		Form,
		TeigGroesse,
		TeigSorte,
		ConfigFile,
		BlechAusFuellung,
		MaxEnumErrorSIZE
	};

	struct ParamA
	{
		bool ZusammenfassungBool;
	};

	size_t HashretSave;
	size_t HashGruenSave;

public:
	bool ZutatenPruefen();
	bool VerzierungPruefen();
	bool TeigPruefen();
	bool FormPruefen();
	bool ConfigPruefen();
	bool Teigroesse();
	bool BlechAusfuelungPruefen();
	bool TeigSortePruefen();
	bool ZusammenfassungFunc();
	int GetErrorListe();

	int SetSetZutatenTrueFalse(bool);
	int SetVerzierungTrueFalse(bool);
	int SetTeigTrueFalse(bool);
	int SetFormTrueFalse(bool);
	int SetConfigTrueFalse(bool);
	int SetTeigroesseTrueFalse(bool);
	int SetBlechAusfuelungTrueFalse(bool);
	int SetTeigSorteTrueFalse(bool);
	int SetZusammenfassungFuncTrueFalse(bool);

	int TryCatchLoop(string MessageS, string CoutMessages, int ErrorNumber, bool * FlagTest, vector<bool>& VectroBool);
	int TryCatchLoop(string MessageS, string CoutMessages, int ErrorNumber, bool * FlagTest, vector<bool>& VectroBool, vector<bool>::iterator ITERator);

	ParameterListe();
	~ParameterListe();
};

