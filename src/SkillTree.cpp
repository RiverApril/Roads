#include "SkillTree.hpp"

void SkillTree::addSkill(pair<int, int> pos, Skill skill){
    skills[pos] = skill;
}

void SkillTree::addConnection(pair<int, int> pos){
    connections[pos] = true;
}

void SkillTree::unlock(pair<int, int> pos){
    if(skills.find(pos) != skills.end()){
        skills[pos].unlocked = true;
    }
}

