#pragma once

#include <map>
using namespace std;

#include "Skill.hpp"

class SkillTree{

    //         ___     ___        //
    //     ___/1-1\___/3-1\___    //
    //    /0-1\___/2-1\___/4-1\   //
    //    \___/1,0\___/3,0\___/   //
    //    /0,0\___/2,0\___/4,0\   //
    //    \___/1,1\___/3,1\___/   //
    //        \___/2,1\___/       //

public:

    map<pair<int, int>, Skill> skills;
    map<pair<int, int>, bool> connections;

    void addSkill(pair<int, int> pos, Skill skill);
    void addConnection(pair<int, int> pos);
    void unlock(pair<int, int> pos);

};