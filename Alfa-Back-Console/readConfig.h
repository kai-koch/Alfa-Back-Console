#pragma once
#include "stdafx.h"
#include "zutat.h"
#include "rezept.h"


using namespace std;

class readConfig
{
private:

public:
    readConfig();
    /**
     * 
     */
    static rezept readRezept(string filename);
    ~readConfig();
};
