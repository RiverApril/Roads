#include "Ui.hpp"

#include <ncurses.h>

#include "Global.hpp"

namespace Ui{

    void drawScroll(int left, int bottom, int height, int select, int unfurl, ReadableList* list, string title, int* outWidth){
        int x = left + unfurl;
        int y = bottom;
        int width = max(list->getMaxWidth(), (int)title.length() + 1) + 4;
        
        *outWidth = width + unfurl;

        if(unfurl > 0){
            move(y, x-1);
            printw("()");
            for(int i = 2; i < width; i++){
                addch('_');
            }
            printw(")");
            move(y-1, x);
            for(int i = 1; i < width-1; i++){
                addch('_');
            }
        }

        int offset = 0;
        if(list->getCount() > 0){
            if(select < height/2){
                offset += height/2-select-1;
            }
            if(select > list->getCount()-height/2){
                offset += list->getCount()-height/2 - select;
            }
        }

        for(int i = 0; i < unfurl; i++){
            x--;
            y--;
            int listIndex = unfurl-i-1 + select - height/2 + offset;
            move(y, x);
            addch('\\');
            
            if(listIndex == select){
                addch('>');
            }else{
                addch((y==bottom-1)?'_':' ');
            }

            for(int j = 3; j < width; j++){
                addch((y==bottom-1)?'_':' ');
            }
            addch('\\');
            if(listIndex >= 0 && listIndex < list->getCount()){
                string s = list->getName(listIndex);
                if(y==bottom-1){
                    for(int j = 0; j < s.length(); j++){
                        if(s[j] == ' ') s[j] = '_';
                    }
                }

                if(listIndex == select){
                    attrset(getColorPair(C_LIGHT_GREEN, C_DARK_BLACK));
                }

                mvprintw(y, x+2, "%s", s.c_str());

                if(listIndex == select){
                    attrset(getColorPair(C_LIGHT_WHITE, C_DARK_BLACK));
                }

            }
        }
    
        move(y, x);
        printw("()");
        for(int i = 2; i < width-1; i++){
            addch('_');
        }
        printw(")");
        move(y-1, x+1);
        for(int i = 1; i < width-1; i++){
            addch('_');
        }
        mvprintw(y, x+3, "%s", title.c_str());

    }

    void drawHLine(int x, int y, int len, char fill, string begin, string end){
        for(int i = 0; i < len; i++){
            safemvaddch(y, x+i, fill);
        }
        safemvaddstr(y, x, begin.c_str(), true);
        safemvaddstr(y, x+len-end.size(), end.c_str(), true);
    }

    void drawBar(int x, int y, int len, float fraction, char fillOn, char fillOff, string begin, string end){
        
        safemvaddstr(y, x, begin.c_str(), true);
        safemvaddstr(y, x+len-end.size(), end.c_str(), true);

        len -= begin.size();
        len -= end.size();
        
        int div = (int)((1.0f-fraction)*len);

        for(int i = 0; i < len; i++){
            safemvaddch(y, x+begin.size()+i, i >= div ? fillOn : fillOff);
        }
    }

    void safemvaddstr(int y, int x, const char* s, bool writeSpace){
        int xStart = x;
        while(s[0] != '\0'){
            if(s[0] == '\n'){
                y++;
                x = xStart;
            }else{
                if(writeSpace || s[0] != ' ') safemvaddch(y, x, s[0]);
                x++;
            }
            s++;
        }
    }

    void safemvaddch(int y, int x, char c){
        if(y >= 0 && x >= 0 && y < ROWS && x < COLS){
            mvaddch(y, x, c);
        }
    }

};