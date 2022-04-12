#include "Simple_window.h"

using namespace Graph_lib;

struct Clock_window : Simple_window {
    Clock_window(Point xy, int w, int h, const string& title );
    void read_time(void);
private:
    
    Out_box time_box;
    time_t now;
    tm *now_tm;
};