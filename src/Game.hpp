#pragma once

class Menu;
class Team;
class SkillTree;
class Actor;

class Game{

    Menu* topMenu;

    bool init();
    void update();

public:

    Team* playerTeam;
    Actor* player;

    SkillTree* skillTree;

    bool running;

    Game();
    void begin();
    void openMenu(Menu* newMenu, int as);

    void applyActionsFromTree();


    friend class Menu;

};