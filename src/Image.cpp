#include "Image.hpp"

#include "Ui.hpp"
#include "Lang.hpp"


Image::Image(int w, int h, strnum img) : width(w), height(h), text(img){
    
}

Image::Image(int w, int h, const char* img) : Image(w, h, 0){
    text = Lang::str(img);
}

Image::Image() : Image(0, 0, 0){}

int Image::getWidth(){
    return width;
}

int Image::getHeight(){
    return height;
}
strnum Image::getStrNum(){
    return text;
}

void Image::draw(int x, int y, int align, bool drawEdgeSpaces){
    if(align & ALIGN_RIGHT){
        x -= width;
    }
    if(align & ALIGN_H_CENTER){
        x -= width/2;
    }

    if(align & ALIGN_BOTTOM){
        y -= height;
    }
    if(align & ALIGN_V_CENTER){
        y -= height/2;
    }

    string s = Lang::getStr(text);

    for(int yy = 0; yy < height; yy++){
        int begin = 0;
        int end = width-1;
        if(!drawEdgeSpaces){
            bool foundStart = false;
            for(int xx = 0; xx < width; xx++){
                if(s[yy*width+xx] != ' '){
                    end = xx;
                    if(!foundStart){
                        begin = xx;
                        foundStart = true;
                    }
                }
            }
            if(!foundStart){
                continue;
            }
        }
        for(int xx = begin; xx <= end; xx++){
            Ui::safemvaddch(y+yy, x+xx, s[yy*width+xx]);
        }
    }
}
