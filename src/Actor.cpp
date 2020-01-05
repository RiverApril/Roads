#include "Actor.hpp"
#include "Action.hpp"
#include "ActionSet.hpp"

Actor::Actor(strnum name, int maxHp, int maxAp, Image image) : name(name), hp(maxHp, maxHp), ap(maxAp, maxAp), image(image){
    actions = new ActionSet();
}
Actor::~Actor(){
    delete actions;
}

Image Actor::getImage(){
    return image;
}

string Actor::getName(){
    return Lang::getStr(name);
}

Stat Actor::getHp(){
    return hp;
}

Stat Actor::getAp(){
    return ap;
}

void Actor::clearActions(){
    actions->clear();
}

void Actor::addAction(Action action){
    actions->add(action);
}

void Actor::sortActions(){
    actions->sort();
}

int Actor::recieveAttack(Damage damage){
    int amount = asIfAttack(damage);
    amount = hp.sub(amount);
    return amount;
}

int Actor::asIfAttack(Damage damage){
    return damage.amount;
}

int Actor::recieveHeal(int amount){
    return hp.add(amount);
}
