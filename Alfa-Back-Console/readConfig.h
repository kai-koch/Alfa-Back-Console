#pragma once
#include "stdafx.h"
#include "zutat.h"
#include "rezept.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class readConfig
{
private:
    /**
     * Handles Error-Bits from Filestream
     * Based on https://gehrcke.de/2011/06/reading-files-in-c-using-ifstream-dealing-correctly-with-badbit-failbit-eofbit-and-perror/
     */
    static int check_error_bits(ifstream * f);
public:
    /**
     * @constructor
     */
    readConfig();
    /**
     * Versucht Filename einzulesen
     * @Returns rezept
     * @throws excption
     */
    static rezept* readRezept(string filename);
    /**
     * Erstellt ein Rezept aus einer Zeile text-inputt
     * @param line Zeile mit den serialisierten Rezeptdaten
     * @throws exception
     */
    static rezept* buildRezept(string line);

    /**
     * Zerschneided den String s mit dem Trennzeichen c
     * @param s String der zerschnitten werden soll
     * @param c Trennzeichen
     * @returns Vector mit den Teilstuecken von s
     */
    static const vector<string> split(const string& s, const char& c);

    /**
     * @destructor
     */
    ~readConfig();
};
