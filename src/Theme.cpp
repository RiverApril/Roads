#include "Theme.hpp"
#include "Assets.hpp"

#include "Global.hpp"

Theme::Theme(Image bg) : bg(bg){

}

void Theme::drawBackground(){
    attrset(getColorPair(C_LIGHT_BLACK, C_DARK_BLACK));
    bg.draw(COLS/2, 0, ALIGN_H_CENTER | ALIGN_TOP);
    attrset(getColorPair(C_LIGHT_WHITE, C_DARK_BLACK));
}

namespace Themes{

    Theme* defaultTheme;

    void createThemes(){
        defaultTheme = new Theme(Assets::bgMountains);
    }

};