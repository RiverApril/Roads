#pragma once

#include <vector>
using namespace std;

#include "ReadableList.hpp"

struct Action;

class ActionSet : public ReadableList{

    vector<Action> actions;
    
public:

    virtual ~ActionSet();

    int getCount() override;
    string getName(int index) override;
    string getDetail(int index) override;

    void clear();
    void add(Action action);
    Action get(int index);

    void removeAt(int index);

    void sort();

};