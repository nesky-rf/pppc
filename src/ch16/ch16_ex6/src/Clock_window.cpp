#include "../include/Clock_window.h"

Clock_window::Clock_window(Point xy, int w, int h, const string& title )
    : Simple_window(xy,w,h,title),
    time_box(Point(x_max()/2-35,y_max()/2),70,30,"")
    {
        attach(time_box);
        // read_time();
    }

void Clock_window::read_time(void)
{
    time_t now= time(0);
    tm *t= localtime(&now); 
    stringstream ss;
    
    ss << setfill('0') \
        << setw(2) << t->tm_hour << ':' \
        << setw(2) << t->tm_min << ':' \
        << setw(2) << t->tm_sec;

    time_box.put(ss.str());
}

