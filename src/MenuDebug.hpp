#pragma once

#include "Menu.hpp"
#include "Team.hpp"

class MenuDebug : public Menu{

    Team* enemyTeam;

public:
    MenuDebug();
    ~MenuDebug();

    void onClose() override;
    void onOpen() override;
    void onUpdate(int input) override;

};
