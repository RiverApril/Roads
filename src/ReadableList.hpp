#pragma once

#include <string>
using namespace std;

class ReadableList{

public:
    virtual int getCount();
    virtual string getName(int index);
    virtual string getDetail(int index);
    int getMaxWidth();

};