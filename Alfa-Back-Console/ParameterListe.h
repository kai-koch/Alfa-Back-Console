#pragma once
class ParameterListe // Status 3
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
	struct ParamA
	{
		bool ZusammenfassungBool = true;
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
	SIZE
	};


public:
	bool ZutatenPruefen();
	bool VerzierungPruefen();
	bool TeigPruefen();
	bool FormPruefen();
	bool ConfifPruefen();
	bool Teigroesse();
	bool BlechAusfuelungPruefen();
	bool TeigSortePruefen();
	bool ZusammenfassungFunc();
	int GetErrorListe();

	int SetSetZutatenTrueFalse(bool);
	int SetVerzierungTrueFalse(bool);
	int SetTeigTrueFalse(bool);
	int SetFormTrueFalse(bool);
	int SetConfifTrueFalse(bool);
	int SetTeigroesseTrueFalse(bool);
	int SetBlechAusfuelungTrueFalse(bool);
	int SetTeigSorteTrueFalse(bool);
	int SetZusammenfassungFuncTrueFalse(bool);

	ParameterListe();
	~ParameterListe();
};

