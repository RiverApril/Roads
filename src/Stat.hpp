#pragma once

struct Stat{
    int max;
    int now;
    Stat(int max, int now);
    bool isMax();
    bool isZero();
    int add(int amount); // returns amount added
    int sub(int amount); // returns amount removed
    bool set(int amount);
    float getFraction();
};