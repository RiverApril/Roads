#include "MenuDebug.hpp"

#include "Global.hpp"
#include "Team.hpp"
#include "Theme.hpp"
#include "Actor.hpp"
#include "Action.hpp"
#include "MenuCombat.hpp"
#include "MenuSkillTree.hpp"
#include "Game.hpp"
#include "Assets.hpp"

MenuDebug::MenuDebug() : Menu(){
    enemyTeam = new Team();
    Actor* testEnemy1 = new Actor(Lang::str("Bandit"), 20, 10, Assets::actorPerson);
    Actor* testEnemy2 = new Actor(Lang::str("Dragon"), 500, 100, Assets::actorDragon);
    Actor* testEnemy3 = new Actor(Lang::str("Dog"), 10, 10, Assets::actorDog);
    enemyTeam->addMember(testEnemy1);
    enemyTeam->addMember(testEnemy2);
    enemyTeam->addMember(testEnemy3);
}

MenuDebug::~MenuDebug(){

}

void MenuDebug::onClose(){

}

void MenuDebug::onOpen(){

}

void MenuDebug::onUpdate(int input){

    erase();

    mvprintw(2, 2, "c: test combat");
    mvprintw(4, 2, "s: skill tree");

    if(input == 'c'){
        openMenu(new MenuCombat(game->playerTeam, enemyTeam, Themes::defaultTheme), AS_CHILD);
    }else if(input == 's'){
        openMenu(new MenuSkillTree(), AS_CHILD);
    }else if(input == KEY_ESCAPE){
        closeMenuToParent();
    }

    refresh();
}