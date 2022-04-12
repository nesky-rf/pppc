#include "../include/Simple_window.h"
#include "../include/Graph.h"

int main(int, char**) {
    try
    {
        using namespace Graph_lib;   // our graphics facilities are in Graph_lib

        Point tl(100,100);           // to become top left  corner of window
        Simple_window win(tl,600,400,"My window");    // make a simple window


        Polygon p;
        p.add(Point(100,50));
        p.add(Point(200,50));
        p.add(Point(200,100));
        p.add(Point(100,100));
        p.set_color(Color::red);
        win.attach(p);

        Rectangle r1(Point(200,200),100,50);
        r1.set_color(Color::blue);
        win.attach(r1);

        Rectangle r2(Point(50,200),100,30);
        r2.set_color(Color::blue);
        win.attach(r2);

        Text t(Point(60,220),"Howdy!");
        win.attach(t);

         
        Rectangle a(Point(250+25*0,50+25*0),25,25);
        a.set_fill_color(Color::black);
        win.attach(a);
        Rectangle a1(Point(250+25*1,50+25*0),25,25);
        win.attach(a1);
        Rectangle a2(Point(250+25*2,50+25*0),25,25);
        a2.set_fill_color(Color::black);
        win.attach(a2);
        Rectangle b(Point(250+25*1,50+25*1),25,25);
        b.set_fill_color(Color::black);
        win.attach(b);
        Rectangle c(Point(250+25*2,50+25*2),25,25);
        c.set_fill_color(Color::black);
        win.attach(c);
        Rectangle d(Point(250+25*3,50+25*3),25,25);
        d.set_fill_color(Color::black);
        win.attach(d);

        win.wait_for_button();       // give control to the display engine

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
