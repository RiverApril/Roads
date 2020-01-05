#pragma once

#include <string>
#include "Action.hpp"
#include "Image.hpp"

#define SKILL_NONE 0
#define SKILL_ACTION 1
#define SKILL_LABEL 2

struct Skill{
    int type = SKILL_NONE;
    int cost = 0;
    Image icon;

    bool unlocked = false;

    union data{
        Action action;
        pair<strnum, strnum> label;
        data(){};
        ~data(){};
    } data;

    string getName();
    string getDetail();

    Skill();
    Skill(int type, int cost, Image icon, strnum labelName, strnum labelDetail);
    Skill(int type, int cost, Image icon, Action action);

    void copy(const Skill& other);

    Skill(const Skill& other);
    Skill& operator=(const Skill& rhs);


};