#include "../include/My_window.h"

My_window::My_window(Point xy, int w, int h, const string& title)
: Simple_window(xy,w,h,title),
quit_button(Point(x_max()-70,20), 70, 20, "Quit", cb_quit)
{
    attach(quit_button);
}

void My_window::cb_quit(Address, Address pw)
{
    reference_to<My_window>(pw).quit_pressed();
}

void My_window::quit_pressed()
{
    hide();
}