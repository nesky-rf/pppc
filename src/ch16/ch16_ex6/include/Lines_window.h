#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title );
private:
    Open_polyline lines;
    // buttons
    Button next_button; // add next_button
    Button quit_button; // add quit button
    Button color_button; // add menu top-down
    Menu color_menu;    // add menu color
    Button line_button; // add line button
    Menu line_menu;     // add line menu
    // top in/out boxes
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    // callbacks and action's
    static void cb_next(Address, Address);  // callback for next_button
    void next();
    static void cb_quit(Address, Address);  // call back for quit_button
    void quit();
    // color menu
    static void cb_color_menu(Address, Address);  // call back for menu_button
    void color_menu_pressed();
    // items
    static void cb_red(Address, Address);   // callback for red button
    void red_pressed();
    static void cb_green(Address, Address);   // callback for green button
    void green_pressed();
    static void cb_blue(Address, Address);   // callback for blue button
    void blue_pressed();
    static void cb_black(Address, Address);   // callback for black button
    void black_pressed();
    // line menu
    static void cb_line_menu(Address, Address);
    void line_menu_pressed();
    // items
    static void cb_line1(Address, Address);
    void line1_pressed();
    static void cb_line2(Address, Address);
    void line2_pressed();
    static void cb_line3(Address, Address);
    void line3_pressed();

    // helper's
    void change_color(Color c);
    void change_line(Line_style l);
    void hide_color_menu();
    void hide_line_menu();
};
