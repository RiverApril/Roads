#pragma once

#include <vector>
#include <string>
using namespace std;

#include "ReadableList.hpp"
#include "Item.hpp"

class Inventory : public ReadableList{

    vector<ItemStack> items;
    
public:

    virtual ~Inventory();

    int getCount() override;
    string getName(int index) override;
    string getDetail(int index) override;

    void add(ItemStack is);
    ItemStack remove(ItemStack is);
    ItemStack get(int index);

};