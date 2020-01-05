#pragma once

#define AS_CHILD 0
#define AS_SIBLING 1
#define AS_ORIGINAL -1

class Game;

class Menu{


    Menu* parentMenu;
    Menu* childMenu;

    void _onClose();
    void _onOpen();
    void _update(int input);

protected:
    Game* game;
    
public:
    Menu();
    virtual ~Menu();

    void openMenu(Menu* newMenu, int as);
    void closeMenuToParent();
    
    virtual void onClose();
    virtual void onOpen();
    virtual void onUpdate(int input);

    friend class Game;
};