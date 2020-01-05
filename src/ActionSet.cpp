#include "ActionSet.hpp"
#include "Action.hpp"
#include "Lang.hpp"

#include <algorithm>

ActionSet::~ActionSet(){

}


int ActionSet::getCount(){
    return actions.size();
}

string ActionSet::getName(int index){
    return Lang::getStr(actions[index].name);
}

string ActionSet::getDetail(int index){
    return Lang::getStr(actions[index].detail);
}

void ActionSet::clear(){
    actions.clear();
}

void ActionSet::add(Action action){
    actions.push_back(action);
}

Action ActionSet::get(int index){
    return actions[index];
}


void ActionSet::removeAt(int index){
    actions.erase(actions.begin()+index);
}

bool compareActions(Action lhs, Action rhs){
    if(lhs.type == rhs.type){
        switch(lhs.type){
            default:
            case ACTION_NONE:
            case ACTION_ITEM: return Lang::getStr(lhs.name) < Lang::getStr(rhs.name);

            case ACTION_SINGLE_ATTACK:
            case ACTION_AREA_ATTACK: {
                if(lhs.data.damage.type == rhs.data.damage.type){
                    return Lang::getStr(lhs.name) < Lang::getStr(rhs.name);
                }else{
                    return lhs.data.damage.type < rhs.data.damage.type;
                }
            }
        };
    }else{
        return lhs.type < rhs.type;
    }
}

void ActionSet::sort(){

    std::sort(actions.begin(), actions.end(), compareActions);

}