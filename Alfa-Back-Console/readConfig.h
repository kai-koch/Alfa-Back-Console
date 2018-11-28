#pragma once
#include "stdafx.h"
#include "zutat.h"
#include "rezept.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class readConfig
{
private:

public:
    readConfig();
    int check_error_bits(ifstream * f);
    /**
     * Versucht Filename einzulesen
     * @Returns rezept
     * @throws
     */
    static rezept readRezept(string filename);
    ~readConfig();
};
