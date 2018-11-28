#include "stdafx.h"
#include "readConfig.h"


readConfig::readConfig()
{
}



int readConfig::check_error_bits(ifstream* f) {
    int stop = 0;
    if (f->eof()) {
        perror("stream eofbit. error state");
        // EOF after std::getline() is not the criterion to stop processing
        // data: In case there is data between the last delimiter and EOF,
        // getline() extracts it and sets the eofbit.
        stop = 0;
    }
    if (f->fail()) {
        perror("stream failbit (or badbit). error state");
        stop = 1;
    }
    if (f->bad()) {
        perror("stream badbit. error state");
        stop = 1;
    }
    return stop;
}

rezept readConfig::readRezept(string filename)
{
    ifstream fs;
    fs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fs.open(filename, ios_base::in);

    

    
    
    fs.close();
    return rezept();
}

readConfig::~readConfig()
{
}
