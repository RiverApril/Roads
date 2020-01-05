#include "Menu.hpp"

#include "Game.hpp"

Menu::Menu() : parentMenu(nullptr), childMenu(nullptr){

}

Menu::~Menu(){

}

void Menu::_onClose(){
    onClose();
}

void Menu::_onOpen(){
    onOpen();
}

void Menu::_update(int input){
    if(childMenu){
        childMenu->_update(input);
    }else{
        onUpdate(input);
    }
}

void Menu::onClose(){}
void Menu::onOpen(){}
void Menu::onUpdate(int input){}

void Menu::openMenu(Menu* newMenu, int as){
    newMenu->game = game;

    if(childMenu){
        childMenu->_onClose();
        delete childMenu;
        childMenu = nullptr;
    }

    if(as == AS_ORIGINAL){
        if(parentMenu){
            parentMenu->openMenu(newMenu, AS_ORIGINAL);
        }else{
            game->topMenu = newMenu;
            _onClose();
            delete this;
            return;
        }
    }else if(as == AS_SIBLING){
        if(parentMenu){
            parentMenu->openMenu(newMenu, AS_CHILD);
        }else{
            openMenu(newMenu, AS_ORIGINAL);
        }
    }else if(as == AS_CHILD){
        childMenu = newMenu;
        childMenu->parentMenu = this;
        childMenu->_onOpen();
    }
}

void Menu::closeMenuToParent(){
    if(parentMenu){
        if(childMenu){
            childMenu->closeMenuToParent();
        }
        _onClose();
        parentMenu->childMenu = nullptr;
        delete this;
        return;
    }else{
        game->running = false;
    }
}