#include "../include/Simple_window.h"
#include "../include/Graph.h"

int main(int, char**) {
    try
    {
        using namespace Graph_lib;   // our graphics facilities are in Graph_lib

        Point tl(100,100);           // to become top left  corner of window
        Simple_window win(tl,600,400,"My window");    // make a simple window

        Axis xa(Axis::x,Point(20,300),280,10,"x axis");
        win.attach(xa);

        Axis ya(Axis::y,Point(20,300),280,10,"y axis");
        ya.set_color(Color::cyan);
        ya.label.set_color(Color::dark_red);
        win.attach(ya);

        Function sine(sin,0,100,Point(20,150),1000,50,50);
        sine.set_color(Color::blue);
        win.attach(sine);

        Polygon poly;
        poly.add(Point(300,200));
        poly.add(Point(350,120));
        poly.add(Point(400,200));
        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);
        poly.set_style(Line_style(Line_style::dashdot,4));
        win.attach(poly);

        Rectangle r(Point(200,200),100,50);
        r.set_fill_color(Color::yellow);
        win.attach(r);

        Closed_polyline poly_rect;
        poly_rect.add(Point(100,50));
        poly_rect.add(Point(200,50));
        poly_rect.add(Point(200,100));
        poly_rect.add(Point(100,100));
        poly_rect.add(Point(50,75));
        poly_rect.set_style(Line_style(Line_style::dash,2));
        win.attach(poly_rect);

        Text t(Point(50,50),"Hello, graph world!");
        t.set_font(Graph_lib::Font::times_bold);    // X11 font definition
        t.set_font_size(20);
        win.attach(t);

        Image ii(Point(200,250),"image.jpg");
        // ii.move(100,200);        // segmentation fault!!
        win.attach(ii);

        ostringstream oss;
        oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
        Text sizes(Point(100,20),oss.str());
        win.attach(sizes);


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
