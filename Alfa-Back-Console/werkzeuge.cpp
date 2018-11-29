#include "stdafx.h"
#include "werkzeuge.h"


werkzeuge::werkzeuge()
{
}

const vector<string> werkzeuge::split(const string & s, const char & c)
{
    string buff{ "" };
    vector<string> v;
    for (auto n : s)
    {
        if (n != c)
        {
            buff += n;
        }
        else
        {
            if (n == c && buff != "")
            {
                v.push_back(buff);
                buff = "";
            }
        }
    }
    if (buff != "")
    {
        v.push_back(buff);
    }

    return v;
}


string werkzeuge::join(const string & delimiter, const vector<string>& v)
{
    string out;
    auto i = v.begin(), e = v.end();
    if (i != e)
    {
        out += *i++;
        for (; i != e; ++i) out.append(delimiter).append(*i);
    }
    return out;
}

werkzeuge::~werkzeuge()
{
}
