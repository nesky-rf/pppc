#include "../include/Simple_window.h"
#include "../include/Graph.h"


int main(int, char**) {
    try
    {
        using namespace Graph_lib;   // our graphics facilities are in Graph_lib

        Point tl(100,100);           // to become top left  corner of window
        Simple_window win(tl,600,400,"chapter13_ex02");    // make a simple window

        cout << "screen size: " << x_max() << "," << y_max() << endl;
        cout << "window size: " << win.x_max() << "," << win.y_max() << endl;

        Arrow arrow(Point(50,50),Point(100,50));
        arrow.set_color(Color::blue);

        win.attach(arrow);
        
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

