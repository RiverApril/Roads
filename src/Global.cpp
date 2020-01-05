#include "Global.hpp"

int ROWS;
int COLS;

std::string debugStr;

int getchSafe(){
    int g = getch();
    if(g == 27){
        timeout(0);
        int gg = getch();
        int ic = 1;
        while(gg != -1){
            g |= gg << 8*ic;
            gg = getch();
            ic++;
        }
        timeout(GAME_TIMEOUT);
    }
    return g;
}

int getColorPair(unsigned char fg, unsigned char bg){
    return COLOR_PAIR(fg + (bg * 0x10));
}

// https://stackoverflow.com/questions/69738/c-how-to-get-fprintf-results-as-a-stdstring-w-o-sprintf#69911

std::string format (const char *fmt, ...) {
    va_list ap;
    va_start (ap, fmt);
    std::string buf = vformat (fmt, ap);
    va_end (ap);
    return buf;
}



std::string vformat (const char *fmt, va_list ap) {
    // Allocate a buffer on the stack that's big enough for us almost
    // all the time.
    size_t size = 64;
    char buf[size];

    // Try to vsnprintf into our buffer.
    va_list apcopy;
    va_copy (apcopy, ap);
    int needed = vsnprintf (&buf[0], size, fmt, ap);
    // NB. On Windows, vsnprintf returns -1 if the string didn't fit the
    // buffer.  On Linux & OSX, it returns the length it would have needed.

    if (needed <= size && needed >= 0) {
        // It fit fine the first time, we're done.
        return std::string (&buf[0]);
    } else {
        // vsnprintf reported that it wanted to write more characters
        // than we allotted.  So do a malloc of the right size and try again.
        // This doesn't happen very often if we chose our initial size
        // well.
        std::vector <char> buf;
        size = needed;
        buf.resize (size);
        needed = vsnprintf (&buf[0], size, fmt, apcopy);
        return std::string (&buf[0]);
    }
}

