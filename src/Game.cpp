#include "Game.hpp"

#include "Global.hpp"
#include "Menu.hpp"
#include "Theme.hpp"
#include "Action.hpp"
#include "Team.hpp"
#include "Actor.hpp"
#include "Skill.hpp"
#include "SkillTree.hpp"
#include "Assets.hpp"


using namespace Lang;
using namespace Assets;


Game::Game() : topMenu(nullptr){
    running = init();

    //         ___     ___        //
    //     ___/1-1\___/3-1\___    //
    //    /0-1\___/2-1\___/4-1\   //
    //    \___/1,0\___/3,0\___/   //
    //    /0,0\___/2,0\___/4,0\   //
    //    \___/1,1\___/3,1\___/   //
    //        \___/2,1\___/       //

    skillTree = new SkillTree();
    skillTree->addSkill({0, 0}, Skill(SKILL_LABEL, 0, skillPerson, str("Exists"), str("This skill you get for just existing!")));
    skillTree->addConnection({1, 0});
    skillTree->addSkill({2, -1}, Skill(SKILL_ACTION, 10, skillSword, Action(ACTION_SINGLE_ATTACK, 2, str("Sword Swing"), str("Swing a steel sword."), Damage(DAMAGE_STEEL, 5))));
    skillTree->addConnection({1, 1});
    skillTree->addSkill({2, 1}, Skill(SKILL_ACTION, 10, skillIce, Action(ACTION_SINGLE_ATTACK, 10, str("Ice Spike"), str("Cast an ice spike."), Damage(DAMAGE_ICE, 20))));
    skillTree->addConnection({0, 1});
    skillTree->addSkill({0, 2}, Skill(SKILL_ACTION, 10, skillIce, Action(ACTION_AREA_ATTACK, 25, str("Ice Storm"), str("Cast a storm of ice."), Damage(DAMAGE_ICE, 50))));
    skillTree->addConnection({0, 1});
    skillTree->addSkill({-2, 1}, Skill(SKILL_ACTION, 20, skillFire, Action(ACTION_AREA_ATTACK, 30, str("Fire Storm"), str("Cast a storm of fire."), Damage(DAMAGE_ICE, 55))));
    skillTree->addConnection({-1, 2});
    skillTree->addSkill({0, -2}, Skill(SKILL_ACTION, 30, skillFire, Action(ACTION_AREA_ATTACK, 42, str("Fire Ball"), str("Cast a fireball, roll 8d6."), Damage(DAMAGE_ICE, 86))));
    skillTree->addConnection({0, -1});

    skillTree->unlock({0, 0});
    skillTree->unlock({2, -1});
    skillTree->unlock({2, 1});

    playerTeam = new Team();
    player = new Actor(str("Player"), 200, 50, Assets::actorPerson);
    playerTeam->addMember(player);

    applyActionsFromTree();
}


void Game::applyActionsFromTree(){

    player->clearActions();

    player->addAction(Action(ACTION_FLEE, 0, str("Flee"), str("Run away from the fight.")));
    for(map<pair<int, int>, Skill>::iterator iter = skillTree->skills.begin(); iter != skillTree->skills.end(); ++iter){
        pair<int, int> pos = iter->first;
        Skill skill = skillTree->skills[pos];
        if(skill.type == SKILL_ACTION && true/*skill.unlocked*/){
           player->addAction(skill.data.action);
        }
    }

    player->sortActions();

}


bool Game::init(){
    
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    curs_set(0);
    timeout(GAME_TIMEOUT);

    start_color();
    use_default_colors();

    short a = 0;
    for (short i = 0; i < 0x10; i++) {
        for (short j = 0; j < 0x10; j++) {
            init_pair(a, j, i);
            a++;
        }
    }

    ESCDELAY = 1;
    
    getmaxyx(stdscr, ROWS, COLS);

    Themes::createThemes();
    return true;
}

void Game::update(){

    int input = getchSafe();
    if(input == KEY_RESIZE){
        getmaxyx(stdscr, ROWS, COLS);
    }
    if(topMenu){
        topMenu->_update(input);
    }

    mvprintw(0, 0, debugStr.c_str());
    refresh();
}

void Game::begin(){
    while(running){
        update();
    }
    endwin();
}

void Game::openMenu(Menu* newMenu, int as){
    if(topMenu){
        topMenu->openMenu(newMenu, as);
    }else if(as == AS_ORIGINAL){
        topMenu = newMenu;
        topMenu->game = this;
        topMenu->_onOpen();
    }
}