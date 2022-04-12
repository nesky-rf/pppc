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

        // Circle c(Point(50,50),25);

        // cout << "n: " << c.n() << endl;
        // cout << "s: " << c.s() << endl;
        // cout << "e: " << c.e() << endl;
        // cout << "w: " << c.w() << endl;
        // cout << "c: " << c.center() << endl;
        // cout << "ne: " << c.ne() << endl;
        // cout << "se: " << c.se() << endl;
        // cout << "sw: " << c.sw() << endl;
        // cout << "nw: " << c.nw() << endl;

        // win.attach(c);
        // win.wait_for_button();

        // Ellipse e(Point(100,50),25,50);

        // cout << "n: " << e.n() << endl;
        // cout << "s: " << e.s() << endl;
        // cout << "e: " << e.e() << endl;
        // cout << "w: " << e.west() << endl;
        // cout << "c: " << e.center() << endl;
        // cout << "ne: " << e.ne() << endl;
        // cout << "se: " << e.se() << endl;
        // cout << "sw: " << e.sw() << endl;
        // cout << "nw: " << e.nw() << endl;

        // win.attach(e);
        // win.wait_for_button(); 

        Boxs boxw(Point(200,100),100,50,"hello");
        boxw.set_color(Color::red);

        Boxs boxs(Point(300,200),100,50,"bye");
        boxs.set_color(Color::red);

        Arrow the(Point(250,100),Point(300,200));

        win.attach(the);
        win.attach(boxw);
        win.attach(boxs);
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

