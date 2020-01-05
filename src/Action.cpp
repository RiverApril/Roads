#include "Action.hpp"
#include "Team.hpp"
#include "Actor.hpp"

Action::Action(){}

Action::Action(int type, int cost, strnum name, strnum detail)
: type(type), cost(cost), name(name), detail(detail){}

Action::Action(int type, int cost, strnum name, strnum detail, int meta)
: type(type), cost(cost), name(name), detail(detail){
    data.meta = meta;
}

Action::Action(int type, int cost, strnum name, strnum detail, Item item)
: type(type), cost(cost), name(name), detail(detail){
    data.item = item;
}

Action::Action(int type, int cost, strnum name, strnum detail, Damage damage)
: type(type), cost(cost), name(name), detail(detail){
    data.damage = damage;
}


bool Action::canTarget(bool multiple, bool hostile){
    switch(type){
        default:
        case ACTION_NONE:{
            return false;
        }
        case ACTION_FLEE:{
            return multiple && !hostile;
        }
        case ACTION_SINGLE_ATTACK:{
            return !multiple && hostile;
        }
        case ACTION_AREA_ATTACK:{
            return multiple && hostile;
        }
        case ACTION_ITEM:{
            return data.item.canTarget(multiple, hostile);
        }
    }
}

bool Action::takeActionOnTeam(Team* target){
    if(canTarget(true, false) || canTarget(true, true)){
        bool any = false;
        for(int i = 0; i < target->actors.size(); i++){
            any |= takeActionOnOneForce(target->actors[i]);
        }
        return any;
    }
    return false;
}

bool Action::takeActionOnOne(Actor* target){
    if(canTarget(false, false) || canTarget(false, true)){
        return takeActionOnOneForce(target);
    }
    return false;
}

bool Action::takeActionOnOneForce(Actor* target){
    switch(type){
        case ACTION_FLEE:{
            break;
        }
        case ACTION_SINGLE_ATTACK:
        case ACTION_AREA_ATTACK:{
            target->recieveAttack(data.damage);
            break;
        }
        case ACTION_ITEM:{
            data.item.takeAction(target);
            break;
        }
    }
    return true;
}

bool Action::takeAction(Actionable* target){
    Team* team = dynamic_cast<Team*>(target);
    Actor* actor = dynamic_cast<Actor*>(target);
    if(team){
        return takeActionOnTeam(team);
    }else if(actor){
        return takeActionOnOne(actor);
    }
    return false;
}

void Action::copy(const Action& other){
    if(this != &other){
        type = other.type;
        cost = other.cost;
        name = other.name;
        detail = other.detail;

        switch(type){
            default:
            case ACTION_NONE: data.meta = other.data.meta; break;

            case ACTION_ITEM: data.item = other.data.item; break;

            case ACTION_SINGLE_ATTACK:
            case ACTION_AREA_ATTACK: data.damage = other.data.damage; break;
        }
    }
}

Action::Action(const Action& other){
    copy(other);
}

Action& Action::operator=(const Action& rhs){
    copy(rhs);
    return *this;
}