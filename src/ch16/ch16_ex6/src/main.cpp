#include "../include/Clock_window.h"
#include "../include/Graph.h"

using namespace Graph_lib;

int main() {
    try
    {
        Clock_window win(Point(100,100),600,400,"my_clock");

        win.read_time();
        win.wait_for_button();
        win.read_time();
        win.wait_for_button();
        return gui_main();
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
    catch(...)
    {
        cerr << "unknown exception" << '\n';
    }
    
}

