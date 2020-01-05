
#include "Game.hpp"
#include "MenuDebug.hpp"
#include "Lang.hpp"
#include "Assets.hpp"
#include "Global.hpp"

void segVHandle(int a){
    printf("SEGV, closing");
    endwin();
    exit(1);
}

int main(){

    signal(SIGSEGV, segVHandle);

    Lang::str("");
    Assets::makeAssets();
    
    Game* game = new Game();

    game->openMenu(new MenuDebug(), AS_ORIGINAL);

    game->begin();

    delete game;
    return 0;
}