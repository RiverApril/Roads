#include "Item.hpp"
#include "Actor.hpp"

string Item::getName(){
    switch(type){
        case ITEM_NONE: return "None";
        case ITEM_HEALTH_POTION: return "Health Potion";
        default: return "Error";
    };
}

string Item::getPluralName(){
    switch(type){
        case ITEM_NONE: return "None";
        default: return getName()+"s";
    };
}

string Item::getDetail(){
    switch(type){
        case ITEM_NONE: return "No Item, this is an Error.";
        case ITEM_HEALTH_POTION: return "A healing liquid.";
        default: return "Item index out of range.";
    };
}

bool Item::canTarget(bool multiple, bool hostile){
    switch(type){
        default:
        case ITEM_NONE: return false;
        case ITEM_HEALTH_POTION: return !multiple && !hostile;
    };
}

bool Item::takeAction(Actor* target){
    switch(type){
        default:
        case ITEM_NONE: return false;
        case ITEM_HEALTH_POTION:
            target->recieveHeal(meta);
            return true;
    }
}

