#include "../include/Simple_window.h"
#include "../include/Graph.h"


int main(int, char**) {
    try
    {
        using namespace Graph_lib;   // our graphics facilities are in Graph_lib

        Point tl(100,100);           // to become top left  corner of window
        Simple_window win(tl,600,400,"chapter14_ex11");    // make a simple window

        cout << "screen size: " << x_max() << "," << y_max() << endl;
        cout << "window size: " << win.x_max() << "," << win.y_max() << endl;

        Binary_tree bt(0);

        win.attach(bt);
        win.wait_for_button();
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

