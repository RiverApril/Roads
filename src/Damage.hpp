#pragma once

#define DAMAGE_STEEL 0
#define DAMAGE_ICE 1

struct Damage{
    int type;
    int amount;
    Damage(int type, int amount);
};