#include "../include/Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h , const string& title)
    : Window(xy,w,h,title),
    next_button(Point(x_max()-150,0), 70, 20, "Next point", cb_next),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
    color_menu(Point(x_max()-70,50),70,20,Menu::vertical,"color"),
    color_button(Point(x_max()-80,30), 80, 20, "color menu", cb_color_menu),
    line_menu(Point(x_max()-140,50),70,20,Menu::vertical,"line"),
    line_button(Point(x_max()-160,30), 80, 20, "line menu", cb_line_menu),
    next_x(Point(x_max()-310,0), 50, 20, "next x: "),
    next_y(Point(x_max()-210,0), 50, 20, "next y: "),
    xy_out(Point(100,0), 100, 20, "current (x,y): ")
{
    attach(next_button);
    attach(quit_button);
    attach(color_button);
    color_menu.attach(new Button(Point(0,0),0,0,"red",cb_red));
    color_menu.attach(new Button(Point(0,0),0,0,"green",cb_green));
    color_menu.attach(new Button(Point(0,0),0,0,"blue",cb_blue));
    color_menu.attach(new Button(Point(0,0),0,0,"black",cb_black));
    attach(color_menu);
    attach(line_button);
    line_menu.attach(new Button(Point(0,0),0,0,"line1",cb_line1));
    line_menu.attach(new Button(Point(0,0),0,0,"line2",cb_line2));
    line_menu.attach(new Button(Point(0,0),0,0,"line3",cb_line3));
    attach(line_menu);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    attach(lines);
    //
    color_menu.hide();
    line_menu.hide();
}

void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}

void Lines_window::quit()
{
    hide();     // curious FLTK idiom for delete window
}

void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point(x,y));      // update current position readout:
    stringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    redraw();
}

void Lines_window::change_color(Color c)
{
    lines.set_color(c);
    redraw();
}

void Lines_window::hide_color_menu()
{
    color_menu.hide();
    color_button.show();
}

void Lines_window::cb_color_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).color_menu_pressed();
}

void Lines_window::color_menu_pressed()
{
    color_button.hide();
    color_menu.show();
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::red_pressed()
{ 
    change_color(Color::red); 
    hide_color_menu();
}

void Lines_window::cb_green(Address, Address pw)
{
    reference_to<Lines_window>(pw).green_pressed();
}

void Lines_window::green_pressed()
{ 
    change_color(Color::green); 
    hide_color_menu();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::blue_pressed()
{ 
    change_color(Color::blue); 
    hide_color_menu();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::black_pressed()
{ 
    change_color(Color::black); 
    hide_color_menu();
}

void Lines_window::change_line(Line_style l)
{
    lines.set_style(l);
    redraw();
}

void Lines_window::hide_line_menu()
{
    line_menu.hide();
    line_button.show();
}

void Lines_window::cb_line_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).line_menu_pressed();
}

void Lines_window::line_menu_pressed()
{
    line_button.hide();
    line_menu.show();
}

void Lines_window::cb_line1(Address, Address pw)
{
    reference_to<Lines_window>(pw).line1_pressed();
}

void Lines_window::line1_pressed()
{ 
    change_line(Line_style::dash); 
    hide_line_menu();
}

void Lines_window::cb_line2(Address, Address pw)
{
    reference_to<Lines_window>(pw).line2_pressed();
}

void Lines_window::line2_pressed()
{ 
    change_line(Line_style::dashdot); 
    hide_line_menu();
}

void Lines_window::cb_line3(Address, Address pw)
{
    reference_to<Lines_window>(pw).line3_pressed();
}

void Lines_window::line3_pressed()
{ 
    change_line(Line_style::solid); 
    hide_line_menu();
}

