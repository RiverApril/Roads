#pragma once

#include <string>
using namespace std;

#define ITEM_NONE 0
#define ITEM_HEALTH_POTION 1

class Actor;

struct Item{
    int type;
    int meta;
    string getName();
    string getPluralName();
    string getDetail();

    bool canTarget(bool multiple, bool hostile);

    bool takeAction(Actor* target);
};

struct ItemStack{
    int qty;
    Item item;
    string getName();
};