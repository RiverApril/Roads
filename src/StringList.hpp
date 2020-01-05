#pragma once

#include <vector>
using namespace std;

#include "ReadableList.hpp"

struct StringListItem{
    string name;
    string detail;
};

class StringList : public ReadableList{

    vector<StringListItem> list;
    
public:
    int getCount() override;
    string getName(int index) override;
    string getDetail(int index) override;

    void add(string name, string detail);

};