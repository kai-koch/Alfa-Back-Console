#include "stdafx.h"
#include "ParameterListe.h"
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
using namespace std;

ParameterListe::ParameterListe()
{
}


ParameterListe::~ParameterListe()
{
}

bool ParameterListe::ZutatenPruefen()
{
	return false;
}

bool ParameterListe::VerzierungPruefen()
{
	return false;
}

bool ParameterListe::TeigPruefen()
{
	return false;
}

bool ParameterListe::FormPruefen()
{
	return false;
}

bool ParameterListe::ConfigPruefen()
{
	return false;
}

bool ParameterListe::Teigroesse()
{
	return false;
}

bool ParameterListe::BlechAusfuelungPruefen()
{
	return false;
}

bool ParameterListe::TeigSortePruefen()
{
	return false;
}

bool ParameterListe::ZusammenfassungFunc()
{
	vector<bool> VectroBool(MaxEnumErrorSIZE, true);
	vector<bool>::iterator ITERator;
	size_t Hashret = 0;
	size_t HashGruensize_t;
	string HashGruen;

	Param sParam1;
	Param *Param_1;
	ParamA sParam2;

	HashGruensize_t = std::hash<std::vector<bool>>()(VectroBool);
	HashGruen = std::to_string(HashGruensize_t);

	HashGruenSave = HashGruensize_t;

	// exceptions
	TryCatchLoop("An exception occurred. Exception ZutatenBool - ", "ZutatenBool", Zutaten, &sParam1.ZutatenBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception VerzierungBool - ", "VerzierungBool", Verzierung, &sParam1.VerzierungBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception TeigBool  - ", "TeigBool", Teig, &sParam1.TeigBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception FormBool  - ", "FormBool", Form, &sParam1.FormBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception TeigGroesseBool - ", "TeigGroesseBool", TeigGroesse, &sParam1.TeigGroesseBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception TeigSorteBool - ", "TeigSorteBool", TeigSorte, &sParam1.TeigSorteBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception ConfigFileBool - ", "ConfigFileBool", ConfigFile, &sParam1.ConfigFileBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception BlechAusFuellungBool - ", "BlechAusFuellungBool", BlechAusFuellung, &sParam1.BlechAusFuellungBool, VectroBool);

	//Pruefe BOOL Vector fuer ZusammenfassungBool

	Hashret = std::hash<std::vector<bool>>()(VectroBool);

	//std::cout << endl << "Exception Matrix Hash is : " << Hashret << endl;
	//std::cout << "HashGruen is : " << HashGruen << endl;
	string Hash_str = std::to_string(Hashret);

	if (HashretSave != Hashret) // keine Status-Veraenderung 
	{
		cout << "HashretSave -  " << HashretSave << endl;
		cout << "Hash_str -  " << Hashret << endl;
		HashretSave = Hashret;
	//cout << "Exception Matrix Hash_str -  " << Hash_str << endl;

	if (HashGruen.compare(Hash_str) != 0)
	{
		std::cout << HashGruen << "- HashGruen is not Exception Matrix Hash : " << Hash_str << endl;
		sParam2.ZusammenfassungBool = false;
	}

	// exceptions
	int ITERatorLoopRetStatus = TryCatchLoop("Exception Matrix erstellt - mehrere Ausnahmen sind aufgetreten - ", "ZusammenfassungBool", (-1), &sParam2.ZusammenfassungBool, VectroBool, ITERator );

	}

	return sParam2.ZusammenfassungBool;
	

}


int ParameterListe::GetErrorListe()
{
	return 0;
}

int ParameterListe::SetSetZutatenTrueFalse(bool TrueFalse)
{
	Param sParam1;
	sParam1.ZutatenBool = TrueFalse;
	return 0;
}

int ParameterListe::SetVerzierungTrueFalse(bool TrueFalse)
{
	Param sParam1;
	sParam1.VerzierungBool = TrueFalse;
	return 0;
}

int ParameterListe::SetTeigTrueFalse(bool TrueFalse)
{
	Param sParam1;
	sParam1.TeigBool = TrueFalse;
	return 0;
}

int ParameterListe::SetFormTrueFalse(bool TrueFalse)
{
	Param sParam1;
	sParam1.FormBool = TrueFalse;
	return 0;
}

int ParameterListe::SetConfigTrueFalse(bool TrueFalse)
{
	Param sParam1;
	sParam1.ConfigFileBool = TrueFalse;
	return 0;
}

int ParameterListe::SetTeigroesseTrueFalse(bool TrueFalse)
{
	Param sParam1;
	sParam1.TeigGroesseBool = TrueFalse;
	return 0;
}

int ParameterListe::SetBlechAusfuelungTrueFalse(bool TrueFalse)
{
	Param sParam1;
	sParam1.BlechAusFuellungBool = TrueFalse;
	return 0;
}


int ParameterListe::SetTeigSorteTrueFalse(bool TrueFalse)
{
	Param sParam1;
	sParam1.TeigSorteBool = TrueFalse;
	return 0;
}

int ParameterListe::SetZusammenfassungFuncTrueFalse(bool TrueFalse)
{
	ParamA sParam2;
	sParam2.ZusammenfassungBool = TrueFalse;
	return 0;
}

int ParameterListe::TryCatchLoop(string ExceptMessageS, string CoutMessages, int ErrorNumber, bool * FlagTest, vector<bool>& VectorBoolPL)
{
	try
	{
		bool i = true;
		int n = 0;
		i = *FlagTest;

		//std::cout << "*FlagTest : " << *FlagTest << endl;

		if (i == false)
		{
			VectorBoolPL.at(ErrorNumber).flip();
			throw ErrorNumber;
		}
		else if (i == true)
		{
			//std::cout << CoutMessages << " is 1" << endl;
		}

	}
	catch (int e)
	{
		//cout << ExceptMessageS << e << endl << endl;
	}

}

int ParameterListe::TryCatchLoop(string ExceptMessageS, string CoutMessages, int ErrorNumber, bool * FlagTest, vector<bool>& VectorBoolPL, vector<bool>::iterator ITERator )
{
	try
	{
		bool i = true;
		int n = 0;
		i = *FlagTest;

		if (i == false)
		{
			throw ErrorNumber;
		}
		else if (i == true)
		{
			std::cout << CoutMessages << " is 1" << endl;
		}

	}
	catch (int e)
	{
		cout << ExceptMessageS << e << endl;
		for (ITERator = VectorBoolPL.begin(); ITERator != VectorBoolPL.end(); ITERator++)
		{
			cout << *ITERator;
		}
		cout << endl << endl;
		return false;
	}


	return true;

}