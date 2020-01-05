#include "Inventory.hpp"


Inventory::~Inventory(){

}

void Inventory::add(ItemStack is){
    for(int i = 0; i < items.size(); i++){
        if(items[i].item.type == is.item.type && items[i].item.meta == is.item.meta){
            items[i].qty += is.qty;
            return;
        }
    }
    items.push_back(is);
}

ItemStack Inventory::remove(ItemStack is){
    for(int i = 0; i < items.size(); i++){
        if(items[i].item.type == is.item.type && items[i].item.meta == is.item.meta){
            if(is.qty < items[i].qty){
                items[i].qty -= is.qty;
                return is;
            }else if(is.qty == items[i].qty){
                items.erase(items.begin()+i);
                return is;
            }else{
                is.qty = items[i].qty;
                items.erase(items.begin()+i);
                return is;
            }
        }
    }
    return {0, {0, 0}};
}

ItemStack Inventory::get(int index){
    return items[index];
}

int Inventory::getCount(){
    return items.size();
}

string Inventory::getName(int index){
    ItemStack is = items[index];
    return is.getName();
}

string Inventory::getDetail(int index){
    ItemStack is = items[index];
    return is.item.getDetail();
}

string ItemStack::getName(){
    return (qty == 1)?item.getName():(to_string(qty)+" "+item.getPluralName());
}

