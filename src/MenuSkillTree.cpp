#include "MenuSkillTree.hpp"

#include "Global.hpp"
#include "SkillTree.hpp"
#include "Game.hpp"
#include "Ui.hpp"

using namespace Ui;

MenuSkillTree::MenuSkillTree(){
    scrollX = 0;
    scrollY = 0;
}

MenuSkillTree::~MenuSkillTree(){

}

void MenuSkillTree::onClose(){

}

void MenuSkillTree::onOpen(){

}

void MenuSkillTree::drawHex(pair<int, int> pos, bool solid, Image icon){
    int x = COLS/2 + scrollX;
    int y = ROWS/2 + scrollY;

    x += pos.first * 7;
    y += pos.second * 4 - (abs(pos.first)%2==1) * 2;

    if(!solid){
        attrset(getColorPair(C_LIGHT_BLACK, C_DARK_BLACK));
    }
    
    safemvaddstr(y-2, x-2, solid?"_____":" _ _ ");
    safemvaddstr(y-1, x-3, "/     \\");
    safemvaddstr(y  , x-4, solid?"/       \\":".       .");
    safemvaddstr(y+1, x-4, solid?"\\       /":"'       '");
    safemvaddstr(y+2, x-3, solid?"\\_____/":"\\ _ _ /");

    icon.draw(x-3, y-1, ALIGN_LEFT | ALIGN_TOP, false);
    //safemvaddstr(y-1, x-3, icon, false);

    if(!solid){
        attrset(getColorPair(C_LIGHT_WHITE, C_DARK_BLACK));
    }
}

void MenuSkillTree::drawHexLine(pair<int, int> pos, bool fs, bool bs, bool v, bool solid){
    int x = COLS/2 + scrollX;
    int y = ROWS/2 + scrollY;

    x += pos.first * 7;
    y += pos.second * 4 - (abs(pos.first)%2==1) * 2;

    if(!solid){
        attrset(getColorPair(C_LIGHT_BLACK, C_DARK_BLACK));
    }
    
    if(fs){
        safemvaddstr(y, x, solid?"_.-'":" . '");
        safemvaddstr(y+1, x-3, solid?".-'":". '");
    }
    if(bs){
        safemvaddstr(y, x-3, solid?"'-._":"' . ");
        safemvaddstr(y+1, x+1, solid?"'-.":"' .");
    }
    if(v){
        safemvaddch(y-1, x, solid?'|':'.');
        safemvaddch(y, x, solid?'|':'.');
        safemvaddch(y+1, x, solid?'|':'.');
        safemvaddch(y+2, x, solid?'|':'.');
    }

    if(!solid){
        attrset(getColorPair(C_LIGHT_WHITE, C_DARK_BLACK));
    }
}

void MenuSkillTree::onUpdate(int input){


    if(input == KEY_ESCAPE){
        closeMenuToParent();
    }else if(input == KEY_LEFT){
        scrollX+=2;
    }else if(input == KEY_RIGHT){
        scrollX-=2;
    }else if(input == KEY_UP){
        scrollY++;
    }else if(input == KEY_DOWN){
        scrollY--;
    }


    erase();

    SkillTree* skillTree = game->skillTree;

    for(map<pair<int, int>, Skill>::iterator iter = skillTree->skills.begin(); iter != skillTree->skills.end(); ++iter){
        pair<int, int> pos = iter->first;
        Skill skill = skillTree->skills[pos];
        
        drawHex(pos, skill.unlocked, skill.icon);

    }

    for(map<pair<int, int>, bool>::iterator iter = skillTree->connections.begin(); iter != skillTree->connections.end(); ++iter){
        pair<int, int> pos = iter->first;
        if(skillTree->connections[pos]){

            int x = pos.first;
            int y = pos.second;
        
            bool fs = false;
            bool bs = false;
            bool v = false;
            bool on = false;
            
            map<pair<int, int>, Skill>::iterator found;

            found = skillTree->skills.find(make_pair(x, y-1));
            if(found != skillTree->skills.end()){
                v = true;
                if(found->second.unlocked) on = true; 
            }

            found = skillTree->skills.find(make_pair(x, y+1));
            if(found != skillTree->skills.end()){
                v = true;
                if(found->second.unlocked) on = true;
            }

            found = skillTree->skills.find(make_pair(x-1, y));
            if(found != skillTree->skills.end()){
                ((x%2==1)?(fs):(bs)) = true;
                if(found->second.unlocked) on = true;
            }

            found = skillTree->skills.find(make_pair(x+1, y));
            if(found != skillTree->skills.end()){
                ((x%2==0)?(fs):(bs)) = true;
                if(found->second.unlocked) on = true;
            }

            found = skillTree->skills.find(make_pair(x-1, x%2==0?(y+1):y));
            if(found != skillTree->skills.end()){
                ((x%2==1)?(fs):(bs)) = true;
                if(found->second.unlocked) on = true;
            }

            found = skillTree->skills.find(make_pair(x+1, x%2==0?(y+1):y));
            if(found != skillTree->skills.end()){
                ((x%2==0)?(fs):(bs)) = true;
                if(found->second.unlocked) on = true;
            }

            drawHexLine(pos, fs, bs, v, on);

        }

    }


    refresh();
}


