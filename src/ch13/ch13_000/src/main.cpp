#include "../include/Simple_window.h"
#include "../include/Graph.h"

void Rectangles(Simple_window&);
void Unnamed_objects(Simple_window&);
void Text_object(Simple_window&);
void Mark_poly(Simple_window&);
void Images(Simple_window&);

int main(int, char**) {
    try
    {
        using namespace Graph_lib;   // our graphics facilities are in Graph_lib

        Point tl(100,100);           // to become top left  corner of window
        Simple_window win(tl,600,400,"chapter13_000");    // make a simple window

        cout << "screen size: " << x_max() << "," << y_max() << endl;
        cout << "window size: " << win.x_max() << "," << win.y_max() << endl;

        // Rectangles(win);
        // Unnamed_objects(win);
        // Text_object(win);
        // Mark_poly(win);
        Images(win);

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

void Rectangles(Simple_window& win)
{
    Rectangle rect00(Point(150,100),200,100);
    Rectangle rect01(Point(50,50),Point(250,150));
    Rectangle rect02(Point(50,150),Point(250,250));
    Rectangle rect11(Point(250,50),200,100);
    Rectangle rect12(Point(250,150),200,100);

    rect00.set_fill_color(Color::yellow);
    rect01.set_fill_color(Color::blue);
    rect02.set_fill_color(Color::red);
    rect11.set_fill_color(Color::green);

    // rect01.move(400,0);

    win.attach(rect00);
    win.attach(rect01);
    win.attach(rect02);
    win.attach(rect11);
    win.attach(rect12);

    rect00.set_color(Color::invisible);
    win.put_on_top(rect00);

    win.wait_for_button();
}

void Unnamed_objects(Simple_window& win)
{
    Vector_ref<Rectangle> vr;

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
        {
            vr.push_back(new Rectangle(Point(i*20,j*20),20,20));
            vr[vr.size()-1].set_fill_color(i*16+j);
            win.attach(vr[vr.size()-1]);
        }
    
    win.wait_for_button();
}

void Text_object(Simple_window& win)
{
    Text t(Point(200,200),"Hello graph!");
    t.set_color(Color::blue);
    t.set_font_size(20);
    t.set_font(Graph_lib::Font::times_bold);
    win.attach(t);
    win.wait_for_button();
}

void Mark_poly(Simple_window& win)
{
    Marked_polyline mpl("1234");
    mpl.add(Point(100,100));
    mpl.add(Point(150,200));
    mpl.add(Point(250,250));
    mpl.add(Point(300,200));

    win.attach(mpl);
    win.wait_for_button();
}

void Images(Simple_window& win)
{
    Image rita(Point(0,0),"rita.jpg");
    Image path(Point(0,0),"rita_path.gif");
    path.set_mask(Point(50,260),600,400);

    win.attach(path);
    win.attach(rita);
    win.wait_for_button();
}