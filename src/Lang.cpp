#include "Lang.hpp"

namespace Lang{
    
    vector<string> reg;

    strnum str(string s){
        for(strnum i = 0; i < reg.size(); i++){
            if(reg[i].compare(s) == 0){
                return i;
            }
        }
        reg.push_back(s);
        return reg.size()-1;
    }

    string getStr(strnum index){
        if(index >= reg.size()){
            return "Error";
        }
        return reg[index];
    }

}