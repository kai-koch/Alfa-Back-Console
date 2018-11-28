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
#include <mutex>
using namespace std;


ParameterListe::ParameterListe()
{
}


ParameterListe::~ParameterListe()
{
}

void ParameterListe::setAutomatSteuerungPointer(AutomatSteuerung * ASPM)
{
	AutomatSteuerungParameterListe = ASPM;
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
	/*
	std::mutex mu;
	mu.lock();*/
	//
	vector<bool> VectroBool(MaxEnumErrorSIZE, true);
	vector<bool>::iterator ITERator;
	size_t Hashret = 0;
	size_t HashGruensize_t;
	string HashGruen;

	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();

/* 
	Param sParam1;
	//Param *Param_1;
	ParamA sParam2;*/

	HashGruensize_t = std::hash<std::vector<bool>>()(VectroBool);
	HashGruen = std::to_string(HashGruensize_t);

	PL1->HashGruenSave = HashGruensize_t;


	// exceptions
	TryCatchLoop("An exception occurred. Exception ZutatenBool - ", "ZutatenBool", Zutaten, PL1->my_Param.ZutatenBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception VerzierungBool - ", "VerzierungBool", Verzierung, PL1->my_Param.VerzierungBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception TeigBool  - ", "TeigBool", Teig, PL1->my_Param.TeigBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception FormBool  - ", "FormBool", Form, PL1->my_Param.FormBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception TeigGroesseBool - ", "TeigGroesseBool", TeigGroesse, PL1->my_Param.TeigGroesseBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception TeigSorteBool - ", "TeigSorteBool", TeigSorte, PL1->my_Param.TeigSorteBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception ConfigFileBool - ", "ConfigFileBool", ConfigFile, PL1->my_Param.ConfigFileBool, VectroBool);
	// exceptions
	TryCatchLoop("An exception occurred. Exception BlechAusFuellungBool - ", "BlechAusFuellungBool", BlechAusFuellung, PL1->my_Param.BlechAusFuellungBool, VectroBool);

	//Pruefe BOOL Vector fuer ZusammenfassungBool

	Hashret = std::hash<std::vector<bool>>()(VectroBool);

	//std::cout << endl << "Exception Matrix Hashret is : " << Hashret << endl;
	//std::cout << "HashGruen is : " << HashGruen << endl;
	string Hash_str = std::to_string(Hashret);

	if ((PL1->HashretSave) != Hashret) // keine Status-Veraenderung 
	{
		cout << "HashretSave -  " << PL1->HashretSave << endl;
		cout << "Hash_str -  " << Hashret << endl;
		PL1->HashretSave = Hashret;
	//cout << "Exception Matrix Hash_str -  " << Hash_str << endl;

	if (HashGruen.compare(Hash_str) != 0)
	{
		std::cout << HashGruen << "- HashGruen is not Exception Matrix Hash : " << Hash_str << endl;
		PL1->my_Param2.ZusammenfassungBool = false;
	}

	// exceptions
	int ITERatorLoopRetStatus = TryCatchLoop("Exception Matrix erstellt - mehrere Ausnahmen sind aufgetreten - ", "ZusammenfassungBool", (-1), PL1->my_Param2.ZusammenfassungBool, VectroBool, ITERator );

	}

	return PL1->my_Param2.ZusammenfassungBool;
	
	//mu.unlock();
}


int ParameterListe::GetErrorListe()
{

	return 0;
}

int ParameterListe::SetSetZutatenTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.ZutatenBool = TrueFalse;
	return 0;
}

int ParameterListe::SetVerzierungTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.VerzierungBool = TrueFalse;
	return 0;
}

int ParameterListe::SetTeigTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.TeigBool = TrueFalse;
	return 0;
}

int ParameterListe::SetFormTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.FormBool = TrueFalse;
	return 0;
}

int ParameterListe::SetConfigTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.ConfigFileBool = TrueFalse;
	return 0;
}

int ParameterListe::SetTeigroesseTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.TeigGroesseBool = TrueFalse;
	return 0;
}

int ParameterListe::SetBlechAusfuelungTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.BlechAusFuellungBool = TrueFalse;
	return 0;
}


int ParameterListe::SetTeigSorteTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param.TeigSorteBool = TrueFalse;
	return 0;
}

int ParameterListe::SetZusammenfassungFuncTrueFalse(bool TrueFalse)
{
	ParameterListe* PL1;
	PL1 = AutomatSteuerungParameterListe->getParameterListe();
	PL1->my_Param2.ZusammenfassungBool = TrueFalse;
	return 0;
}



int ParameterListe::TryCatchLoop(string ExceptMessageS, string CoutMessages, int ErrorNumber, bool FlagTest, vector<bool>& VectorBoolPL)
{
	try
	{
		bool i = true;
		int n = 0;
		i = FlagTest;

		//std::cout << "*FlagTest : " << FlagTest << endl;

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
	catch (int e) //e -ErrorNumber
	{
		//cout << ExceptMessageS << e << endl << endl;
	}

}

int ParameterListe::TryCatchLoop(string ExceptMessageS, string CoutMessages, int ErrorNumber, bool FlagTest, vector<bool>& VectorBoolPL, vector<bool>::iterator ITERator )
{
	try
	{
		bool i = true;
		int n = 0;
		i = FlagTest;

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