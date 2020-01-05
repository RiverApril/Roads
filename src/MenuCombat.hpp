#pragma once

#include "Menu.hpp"
#include "StringList.hpp"
#include "Action.hpp"

#define SELECT_X_COUNT 3
#define UNFURL_MAX 6

class Team;
class Theme;

class MenuCombat : public Menu{

    Theme* theme;

    Team* playerTeam;
    Team* enemyTeam;

    StringList optionsList;

    vector<Actionable*> targets;
    int targetIndex;
    Actionable* lastTarget;

    Action actionToUse;


    int selectX;
    int selectY[SELECT_X_COUNT];

    int actionsUnfurl;
    int itemsUnfurl;
    int optionsUnfurl;

public:

    MenuCombat(Team* playerTeam, Team* enemyTeam, Theme* theme);
    ~MenuCombat();
    
    void onClose() override;
    void onOpen() override;
    void onUpdate(int input) override;

    void useAction();

    void setupTargetList();
    void drawTeam(Team* team, bool rightSide);

};