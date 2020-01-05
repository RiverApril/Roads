#pragma once

#include <ncurses.h>
#include <string>
#include <cstdarg>
#include <vector>

#define GAME_TIMEOUT 20

#define KEY_ESCAPE 27

#define C_DARK_BLACK 0x0 // white when background is black
#define C_DARK_RED 0x1
#define C_DARK_GREEN 0x2
#define C_DARK_YELLOW 0x3
#define C_DARK_BLUE 0x4
#define C_DARK_MAGENTA 0x5
#define C_DARK_CYAN 0x6
#define C_DARK_WHITE 0x7

#define C_LIGHT_BLACK 0x8
#define C_LIGHT_RED 0x9
#define C_LIGHT_GREEN 0xA
#define C_LIGHT_YELLOW 0xB
#define C_LIGHT_BLUE 0xC
#define C_LIGHT_MAGENTA 0xD
#define C_LIGHT_CYAN 0xE
#define C_LIGHT_WHITE 0xF

extern int ROWS;
extern int COLS;

extern std::string debugStr;

int getchSafe();

int getColorPair(unsigned char fg, unsigned char bg);

std::string format (const char *fmt, ...);
std::string vformat (const char *fmt, va_list ap);