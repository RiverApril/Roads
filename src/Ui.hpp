#pragma once

#include "ReadableList.hpp"

namespace Ui{

    void drawScroll(int left, int bottom, int height, int select, int unfurl, ReadableList* list, string title, int* outWidth);

    void drawHLine(int x, int y, int len, char fill, string begin = "", string end = "");
    void drawBar(int x, int y, int len, float fraction, char fillOn, char fillOff, string begin = "", string end = "");

    void safemvaddstr(int y, int x, const char* s, bool writeSpace = true);
    void safemvaddch(int y, int x, char c);

};