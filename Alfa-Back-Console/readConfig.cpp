#include "stdafx.h"
#include "readConfig.h"


readConfig::readConfig() {}


int readConfig::check_error_bits(ifstream* f)
{
    int stop = false;
    if (f->eof()) {
        // End of file reached
        stop = true;
    }
    if (f->bad()) {
        string msg = "Read/writing error on i/o operation";
        throw new exception(msg.c_str());
    }
    if (f->fail()) {
        string msg = "Logical error on i/o operation";
        throw new exception(msg.c_str());
    }
    return stop;
}

rezept* readConfig::buildRezept(string line)
{
    rezept* daRezept = new rezept("Default", 100.0, "Default", "klein", 180.0, 40.0);
    /*
    teigname:Schokokeks	basisAnzahl:10000	form:Kreis	groesse:mittel	backTemperatur:180	backZeit:40	Zutaten:Backpulver,10000,g|Eier,0,9|Kakao,70000,g|Mehl,90000,g|Milch,400,l|Pflanzenfett,50000,g|Zucker,100000,g	Verzierungen:Kakaoguss,0,3|Schokostreusel,30000,g
    */
    vector<string> columns = split(line, '\t');
    for(int i=0; i < columns.size(); i += 1)
    {


    }

    return daRezept;
}

rezept* readConfig::readRezept(string filename)
{
    rezept* daRezept = nullptr;
    string line;
    ifstream fs(filename);

    if(!fs.is_open())
    {
        string msg = "No such file or directory '" + filename + "'";
        throw new exception(msg.c_str());
    }
    check_error_bits(&fs);
    while (true) 
    {
        getline(fs, line);
        if(check_error_bits(&fs))
        {
            break;
        }
        daRezept = buildRezept(line);
    }
    fs.close();
    return daRezept;
}

const vector<string> readConfig::split(const string & s, const char & c)
{
    string buff{ "" };
    vector<string> v;
    for(auto n : s)
    {
        if(n != c) 
        {
            buff += n;
        }
        else
        {
            if(n == c && buff != "")
            {
                v.push_back(buff);
                buff = ""; 
            }
        }
    }
    if (buff != "")
    {
        v.push_back(buff);}

    return v;
}

readConfig::~readConfig() {}
