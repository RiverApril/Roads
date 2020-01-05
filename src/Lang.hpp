#pragma once

#include <vector>
#include <string>
using namespace std;

typedef int strnum;

namespace Lang{

    extern vector<string> reg;

    strnum str(string s);
    string getStr(strnum index);

};