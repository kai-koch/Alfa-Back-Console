// Alfa-Back-Console.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
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
using namespace std;
#include "AutomatSteuerung.h"
#include "OfenSteuerung.h"
#include "Ofen.h"
#include "Band.h"

int main()
{
	Ofen Ofn;
	Band Bnd;
	AutomatSteuerung As;

	Ofn.setTemperatur(100); 
	Bnd.setGeschwindigkeit(100);
    return 0;
}

