#include "Skill.hpp"
#include "Lang.hpp"


string Skill::getName(){
    switch(type){
        case SKILL_ACTION: return Lang::getStr(data.action.name);
        case SKILL_LABEL: return Lang::getStr(data.label.first);
    }
    return "Error";
}

string Skill::getDetail(){
    switch(type){
        case SKILL_ACTION: return Lang::getStr(data.action.detail);
        case SKILL_LABEL: return Lang::getStr(data.label.second);
    }
    return "Error";
}

Skill::Skill(){}

Skill::Skill(int type, int cost, Image icon, strnum labelName, strnum labelDetail)
: type(type), cost(cost), icon(icon) {
    data.label.first = labelName;
    data.label.second = labelDetail;
}

Skill::Skill(int type, int cost, Image icon, Action action)
: type(type), cost(cost), icon(icon) {
    data.action = action;
}

void Skill::copy(const Skill& other){
    if(this != &other){
        type = other.type;
        cost = other.cost;
        icon = other.icon;
        unlocked = other.unlocked;

        switch(type){
            case SKILL_ACTION: data.action = other.data.action; break;
            case SKILL_LABEL: data.label = other.data.label; break;
        }
    }
}

Skill::Skill(const Skill& other){
    copy(other);
}

Skill& Skill::operator=(const Skill& rhs){
    copy(rhs);
    return *this;
}
