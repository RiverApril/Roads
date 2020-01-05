#include "Team.hpp"
#include "ActionSet.hpp"
#include "Actor.hpp"
#include "Inventory.hpp"

Team::Team(){
    items = new Inventory();
    turn = 0;
}

Team::~Team(){
    delete items;
}

void Team::addMember(Actor* actor){
    actors.push_back(actor);
}

ActionSet* Team::getActions(){
    return actors[turn]->actions;
}

Inventory* Team::getItems(){
    return items;
}

void Team::nextTurn(){
    turn++;
    if(actors.size() >= turn){
        turn = 0;
    }
}

int Team::turnsLeft(){
    return actors.size() - turn;
}