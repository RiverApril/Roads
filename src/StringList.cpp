#include "StringList.hpp"



int StringList::getCount(){
    return list.size();
}

string StringList::getName(int index){
    return list[index].name;
}

string StringList::getDetail(int index){
    return list[index].detail;
}

void StringList::add(string name, string detail){
    list.push_back({name, detail});
}