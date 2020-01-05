#pragma once

#include <vector>
using namespace std;

#include "Menu.hpp"
#include "Image.hpp"


class MenuSkillTree : public Menu{

    int scrollX;
    int scrollY;

public:

    MenuSkillTree();
    ~MenuSkillTree();
    
    void onClose() override;
    void onOpen() override;
    void onUpdate(int input) override;

    void drawHex(pair<int, int> pos, bool solid, Image icon);
    void drawHexLine(pair<int, int> pos, bool fs, bool bs, bool v, bool solid);
};