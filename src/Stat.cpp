#include "Stat.hpp"


Stat::Stat(int max, int now) : max(max), now(now){

}

int Stat::add(int amount){
    if(amount <= 0){
        return 0;
    }
    if(now + amount <= max){
        now += amount;
        return amount;
    }else{
        amount = max - now;
        now = max;
        return amount;
    }
}

int Stat::sub(int amount){
    if(amount <= 0){
        return 0;
    }
    if(now - amount >= 0){
        now -= amount;
        return amount;
    }else{
        amount = now;
        now = 0;
        return amount;
    }
}

bool Stat::set(int amount){
    if(amount >= 0 && amount <= max){
        now = amount;
        return true;
    }
    return false;
}

float Stat::getFraction(){
    return now*1.0f/max;
}