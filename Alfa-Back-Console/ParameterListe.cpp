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

bool ParameterListe::ConfifPruefen()
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
	vector<bool> VectroBool(9, true);
	vector<bool>::iterator ITERator;
	size_t Hashret = 0;

	Param sParam1;
	Param *Param_1;
	ParamA sParam2;
	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam1.ZutatenBool;

		if (i == false)
		{
			VectroBool.at(0).flip();
			throw 2;
		}
		else if (i == true)
		{
			std::cout << "ZutatenBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception ZutatenBool Nr. " << e << '\n';
	}
	//####################################################################################

	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam1.VerzierungBool;

		if (i == false)
		{
			VectroBool.at(1).flip();
			throw 2;
		}
		else if (i == true)
		{
			std::cout << "VerzierungBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception VerzierungBool Nr. " << e << '\n';
	}
	//####################################################################################

	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam1.TeigBool;

		if (i == false)
		{
			VectroBool.at(2).flip();
			throw 2;
		}
		else if (i == true)
		{
			std::cout << "TeigBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception TeigBool Nr. " << e << '\n';
	}
	//####################################################################################

	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam1.FormBool;

		if (i == false)
		{
			VectroBool.at(3).flip();
			throw 2;
		}
		else if (i == true)
		{
			std::cout << "FormBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception FormBool Nr. " << e << '\n';
	}
	//####################################################################################

	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam1.TeigGroesseBool;

		if (i == false)
		{
			VectroBool.at(4).flip();
			throw 2;
		}
		else if (i == true)
		{
			std::cout << "TeigGroesseBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception TeigGroesseBool Nr. " << e << '\n';
	}
	//####################################################################################
	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam1.TeigSorteBool;

		if (i == false)
		{
			VectroBool.at(5).flip();
			throw 2;
		}
		else if (i == true)
		{
			std::cout << "ZutatenBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception TeigSorteBool Nr. " << e << '\n';
	}
	//####################################################################################
	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam1.ConfigFileBool;

		if (i == false)
		{
			VectroBool.at(6).flip();
			throw 2;
		}
		else if (i == true)
		{
			std::cout << "ConfigFileBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception ConfigFileBool Nr. " << e << '\n';
	}
	//####################################################################################

	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam1.BlechAusFuellungBool;

		if (i == false)
		{
			VectroBool.at(7).flip();
			throw 2;
		}
		else if (i == true)
		{
			std::cout << "BlechAusFuellungBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception BlechAusFuellungBool Nr. " << e << '\n';
	}
	//####################################################################################

	//Pruefe BOOL Vector für ZusammenfassungBool

	Hashret = std::hash<std::vector<bool>>()(VectroBool);

	std::cout << endl << "Hash is : " << Hashret << endl;
	string HashGruen = { "8217542530325308709" };
	string Hash_str = std::to_string(Hashret);
	cout << "Hash_str -  " << Hash_str << '\n';

	if (HashGruen.compare(Hash_str) != 0)
	{
		std::cout << HashGruen << " is not " << Hash_str << '\n';
		sParam2.ZusammenfassungBool = false;
	}

	// exceptions
	//####################################################################################
	try
	{
		bool i = true;
		int n = 0;
		i = sParam2.ZusammenfassungBool;

		if (i == false)
		{
			throw (-1);
		}
		else if (i == true)
		{
			std::cout << endl << "ZusammenfassungBool" << " is 1\n";
		}

	}
	catch (int e)
	{
		cout << "Exception Matrix erstellt - mehrere Ausnahmen sind aufgetreten - " << e << '\n';
		for (ITERator = VectroBool.begin(); ITERator != VectroBool.end(); ITERator++)
		{
			cout << *ITERator;
		}
		cout << endl;
		return false;
	}
	//####################################################################################


	return true;
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

int ParameterListe::SetConfifTrueFalse(bool TrueFalse)
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
