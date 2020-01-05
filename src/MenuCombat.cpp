#include "MenuCombat.hpp"

#include "Theme.hpp"
#include "Global.hpp"
#include "Game.hpp"
#include "Ui.hpp"
#include "Team.hpp"
#include "ReadableList.hpp"
#include "ActionSet.hpp"
#include "Action.hpp"
#include "Inventory.hpp"
#include "Actor.hpp"
#include "Assets.hpp"


MenuCombat::MenuCombat(Team* playerTeam, Team* enemyTeam, Theme* theme) : Menu(){
    this->playerTeam = playerTeam;
    this->enemyTeam = enemyTeam;
    this->theme = theme;

    selectX = -1;
    for(int i = 0; i < SELECT_X_COUNT; i++){
        selectY[i] = 0;
    }

    actionsUnfurl = 0;
    itemsUnfurl = 0;
    optionsUnfurl = 0;
    
    lastTarget = nullptr;
    targetIndex = 0;
    actionToUse.type = ACTION_NONE;

    optionsList.add("Quit", "Close the game.");
}

MenuCombat::~MenuCombat(){

}

void MenuCombat::onClose(){

}

void MenuCombat::onOpen(){

}

void MenuCombat::onUpdate(int input){
    
    actionsUnfurl += (selectX == 0) ? ((actionsUnfurl == UNFURL_MAX) ? (0) : (1)) : ((actionsUnfurl == 0) ? (0) : (-1));
    itemsUnfurl += (selectX == 1) ? ((itemsUnfurl == UNFURL_MAX) ? (0) : (1)) : ((itemsUnfurl == 0) ? (0) : (-1));
    optionsUnfurl += (selectX == 2) ? ((optionsUnfurl == UNFURL_MAX) ? (0) : (1)) : ((optionsUnfurl == 0) ? (0) : (-1));


    ReadableList* actionList = playerTeam->getActions();
    ReadableList* itemList = playerTeam->getItems();

    ReadableList* currentList;


    if(actionToUse.type == ACTION_NONE){


        if(input == KEY_LEFT){
            selectX--;
            if(selectX < -1){
                selectX = SELECT_X_COUNT-1;
            }
        }else if(input == KEY_RIGHT){
            selectX++;
            if(selectX >= SELECT_X_COUNT){
                selectX = 0;
            }
        }else if(input == KEY_ESCAPE){
            selectX = (selectX == -1) ? (selectX = 2) : (selectX = -1);
        }else if(input == 'a'){
            selectX = (selectX != 0) ? (selectX = 0) : (selectX = -1);
        }else if(input == 'i'){
            selectX = (selectX != 1) ? (selectX = 1) : (selectX = -1);
        }

        switch(selectX){
            case 0: currentList = actionList; break;
            case 1: currentList = itemList; break;
            case 2: currentList = &optionsList; break;
        }

        if(selectX >= 0){
            if(input == KEY_UP){
                selectY[selectX]--;
            }else if(input == KEY_DOWN){
                selectY[selectX]++;
            }
            if(selectY[selectX] < 0){
                selectY[selectX] = currentList->getCount()-1;
            }
            if(selectY[selectX] >= currentList->getCount()){
                selectY[selectX] = 0;
            }
        }

        if(input == '\n'){
            switch(selectX){
                case 0: {
                    actionToUse = playerTeam->getActions()->get(selectY[selectX]);
                    break;
                }
                case 1: {
                    if(selectY[selectX] >= 0 && itemList->getCount() > 0){
                        Item item = playerTeam->getItems()->get(selectY[selectX]).item;
                        actionToUse = Action(ACTION_ITEM, 0, Lang::str(item.getName()), Lang::str(item.getDetail()), item);
                    }
                    break;
                }
                case 2: {
                    switch(selectY[selectX]){
                        case 0:{
                            closeMenuToParent();
                            return;
                            break;
                        };
                    }
                    break;
                }
            }
        }

        setupTargetList();

    }else{

        if(input == KEY_LEFT){
            targetIndex--;
            if(targetIndex < 0){
                targetIndex = targets.size() - 1;
            }
        }else if(input == KEY_RIGHT){
            targetIndex++;
            if(targetIndex >= targets.size()){
                targetIndex = 0;
            }
        }else if(input == '\n'){
            useAction();
        }else if(input == KEY_ESCAPE){
            lastTarget = targets[targetIndex];
            actionToUse.type = ACTION_NONE;
        }
    }


    erase();
    theme->drawBackground();
    
    move(ROWS-4, 0);
    for(int i = 0; i < COLS; i++){
        addch('_');
    }

    drawTeam(playerTeam, false);
    drawTeam(enemyTeam, true);


    int scrollLeft = 1;
    int scrollBottom = ROWS - 2;
    int width;
    
    Ui::drawScroll(scrollLeft, scrollBottom, UNFURL_MAX, selectY[0], actionsUnfurl, actionList, "Actions", &width);
    scrollLeft += 1 + width;
    Ui::drawScroll(scrollLeft, scrollBottom, UNFURL_MAX, selectY[1], itemsUnfurl, itemList, "Items", &width);
    scrollLeft += 1 + width;
    Ui::drawScroll(scrollLeft, scrollBottom, UNFURL_MAX, selectY[2], optionsUnfurl, &optionsList, "Menu", &width);


    refresh();
}

void MenuCombat::setupTargetList(){
    targets.clear();
    targetIndex = 0;
    if(actionToUse.type != ACTION_NONE){

        if(actionToUse.canTarget(true, false)){
            targets.push_back(playerTeam);
        }

        if(actionToUse.canTarget(false, false)){
            for(int i = 0; i < playerTeam->actors.size(); i++){
                targets.push_back(playerTeam->actors[i]);
            }
        }

        if(actionToUse.canTarget(true, true)){
            targets.push_back(enemyTeam);
        }

        if(actionToUse.canTarget(false, true)){
            for(int i = 0; i < enemyTeam->actors.size(); i++){
                targets.push_back(enemyTeam->actors[i]);
            }
        }
    }
    
    for(int i = 0; i < targets.size(); i++){
        if(targets[i] == lastTarget){
            targetIndex = i;
        }
    }

    if(targets.size() == 0){
        actionToUse.type = ACTION_NONE;
        // failed to find viable target
    }
}

void MenuCombat::useAction(){

    if(targets.size() > 0){
        actionToUse.takeAction(targets[targetIndex]);
        lastTarget = targets[targetIndex];
    }
    
    actionToUse.type = ACTION_NONE;
}


void MenuCombat::drawTeam(Team* team, bool rightSide){

    int teamWidth = 0;
    for(int i = 0; i < team->actors.size(); i++){
        teamWidth += team->actors[i]->getImage().getWidth()+1;
    }

    int y = 3*ROWS/4;
    int x = (rightSide?3:1)*COLS/4 - teamWidth/2;


    for(int i = 0; i < team->actors.size(); i++){
        Image img = team->actors[i]->getImage();
        x += img.getWidth()/2;
        bool selected = (actionToUse.type != ACTION_NONE) && ((static_cast<Actionable*>(team->actors[i]) == targets[targetIndex]) || (static_cast<Actionable*>(team) == targets[targetIndex]));

        img.draw(x, y, ALIGN_H_CENTER | ALIGN_BOTTOM, false);
        if(selected){
            attrset(getColorPair(C_LIGHT_GREEN, C_DARK_BLACK));
            Ui::safemvaddch(y-img.getHeight()-1, x, 'v');
            attrset(getColorPair(C_LIGHT_WHITE, C_DARK_BLACK));
        }
        x += img.getWidth()/2+1;
    }

    x = rightSide?(COLS/2+2):0;
    int w = COLS/2-4;
    y = 0;

    Ui::drawHLine(x, y, w, '-', ".|", "|.");
    for(int i = 0; i < team->actors.size(); i++){
        y++;
        Actor* actor = team->actors[i];
        Ui::drawHLine(x, y, w, ' ', ".|", "|.");

        int ww = 3;
        Ui::safemvaddstr(y, x+ww, actor->getName().c_str());
        ww += actor->getName().size()+1;

        string text = format("%d/%d", actor->getHp().now, actor->getHp().max);
        Ui::safemvaddstr(y, x+ww, text.c_str());
        ww += text.size()+1;

        Ui::drawBar(x+ww, y, w-ww-3, actor->getHp().getFraction(), '=', ' ', "-/", "/-");
    }
    y++;
    Ui::drawHLine(x, y, w, '-', ".|", "|.");


}