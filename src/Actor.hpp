#pragma once

#include "Stat.hpp"
#include "Damage.hpp"
#include "Actionable.hpp"
#include "Image.hpp"

class ActionSet;
struct Action;

class Actor : public Actionable{

    ActionSet* actions;

    strnum name;
    Stat hp;
    Stat ap;
    Image image;

public:

    Actor(strnum name, int maxHp, int maxAp, Image image);
    virtual ~Actor();

    Image getImage();
    string getName();

    void clearActions();
    void addAction(Action action);
    void sortActions();

    int recieveAttack(Damage damage);
    int asIfAttack(Damage damage);

    int recieveHeal(int amount);

    Stat getHp();
    Stat getAp();

    friend class Team;

};