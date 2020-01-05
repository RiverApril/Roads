#pragma once

#include "Image.hpp"

class Theme{

    Image bg;

public:

    Theme(Image bg);

    void drawBackground();

};

namespace Themes{

    extern Theme* defaultTheme;

    void createThemes();

};