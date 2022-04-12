#include "../include/Simple_window.h"
#include "../include/Graph.h"


int main(int, char**) {
    try
    {
        using namespace Graph_lib;   // our graphics facilities are in Graph_lib

        Point tl(100,100);           // to become top left  corner of window
        Simple_window win(tl,600,400,"chapter14_ex01");    // make a simple window

        cout << "screen size: " << x_max() << "," << y_max() << endl;
        cout << "window size: " << win.x_max() << "," << win.y_max() << endl;

        Octagon oct1(Point(200,200),100);
        win.attach(oct1);
        win.wait_for_button();

        Octagon oct2(Point(200,200),50);
        win.attach(oct2);
        win.wait_for_button();

        // test: set all available properties
        oct2.set_color(Color::blue);
        oct2.set_style(Line_style::dashdot);
        oct2.set_fill_color(Color::dark_blue);
        // test: read available properties
        cout << "Octagon: " << oct2.number_of_points() << ',' << Color::Color_type(oct2.color().as_int()) << ',' 
            << Line_style::Line_style_type(oct2.style().style()) << endl;

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

