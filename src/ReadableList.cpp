#include "ReadableList.hpp"


int ReadableList::getCount(){return 0;}
string ReadableList::getName(int index){return "";}
string ReadableList::getDetail(int index){return "";}

int ReadableList::getMaxWidth(){
    int high = 0;
    for(int i = 0; i < getCount(); i++){
        int newLen = getName(i).length();
        if(newLen > high){
            high = newLen;
        }
    }
    return high;
}