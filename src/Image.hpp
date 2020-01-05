#pragma once

#include "Lang.hpp"

#define ALIGN_LEFT 0
#define ALIGN_H_CENTER 1
#define ALIGN_RIGHT 2

#define ALIGN_TOP 0
#define ALIGN_V_CENTER 4
#define ALIGN_BOTTOM 8

#define ALIGN_CENTER (ALIGN_H_CENTER | ALIGN_V_CENTER)

class Image{

    int width;
    int height;
    strnum text;

public:

    Image();
    Image(int w, int h, strnum img);
    Image(int w, int h, const char* img);

    int getWidth();
    int getHeight();
    strnum getStrNum();
    void draw(int x, int y, int align = 0, bool drawEdgeSpaces = true);

};