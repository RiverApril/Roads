#pragma once

#include "Actionable.hpp"

#include <vector>
using namespace std;

class Actor;
class Inventory;
class ActionSet;

class Team : public Actionable{

    int turn;

public:

    vector<Actor*> actors;

    Inventory* items;


    Team();
    ~Team();

    void addMember(Actor* actor);
    ActionSet* getActions();
    Inventory* getItems();
    void nextTurn();
    int turnsLeft();

};