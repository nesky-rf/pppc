#include "Simple_window.h"

using namespace Graph_lib;

struct My_window : Simple_window {
    My_window(Point xy, int w, int h, const string& title);
private:
    Button quit_button;
    static void cb_quit(Address, Address);
    void quit_pressed();
};