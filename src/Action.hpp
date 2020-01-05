#pragma once

#include <string>
using namespace std;

#include "Item.hpp"
#include "Damage.hpp"
#include "Lang.hpp"
#include "Actionable.hpp"

#define ACTION_NONE 0
#define ACTION_FLEE 1
#define ACTION_SINGLE_ATTACK 2
#define ACTION_AREA_ATTACK 3
#define ACTION_ITEM 4

class Team;
class Actor;

struct Action{
    int type = ACTION_NONE;
    int cost = 0;
    strnum name = 0;
    strnum detail = 0;

    union data{
        int meta = 0;
        Item item;
        Damage damage;
        data(){};
    } data;


    Action();
    Action(int type, int cost, strnum name, strnum detail);
    Action(int type, int cost, strnum name, strnum detail, int meta);
    Action(int type, int cost, strnum name, strnum detail, Item item);
    Action(int type, int cost, strnum name, strnum detail, Damage damage);

    bool canTarget(bool multiple, bool hostile);

    bool takeAction(Actionable* target);
    
    bool takeActionOnTeam(Team* target);
    bool takeActionOnOne(Actor* target);
    bool takeActionOnOneForce(Actor* target);

    void copy(const Action& other);

    Action(const Action& other);
    Action& operator=(const Action& rhs);
};