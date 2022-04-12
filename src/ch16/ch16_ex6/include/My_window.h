#include "Simple_window.h"

using namespace Graph_lib;


struct My_window : Simple_window {
    My_window(Point xy, int w, int h, const string& title);
    
private:
    Out_box text;
    //
    Button btn11;
    static void cb_btn11(Address,Address pw) { reference_to<My_window>(pw).btn11_pressed(); }
    void btn11_pressed() { cout << __PRETTY_FUNCTION__ << endl; }
    Button btn12;
    static void cb_btn12(Address,Address pw) { reference_to<My_window>(pw).btn12_pressed(); }
    void btn12_pressed() { cout << __PRETTY_FUNCTION__ << endl; };
    Button btn13;
    static void cb_btn13(Address,Address pw) { reference_to<My_window>(pw).btn13_pressed(); }
    void btn13_pressed() { cout << __PRETTY_FUNCTION__ << endl; };
    //
    Button btn21;
    static void cb_btn21(Address,Address pw) { reference_to<My_window>(pw).btn21_pressed(); }
    void btn21_pressed() { cout << __PRETTY_FUNCTION__ << endl; };
    Button btn22;
    static void cb_btn22(Address,Address pw) { reference_to<My_window>(pw).btn22_pressed(); }
    void btn22_pressed() { cout << __PRETTY_FUNCTION__ << endl; };
    Button btn23;
    static void cb_btn23(Address,Address pw) { reference_to<My_window>(pw).btn23_pressed(); }
    void btn23_pressed() { cout << __PRETTY_FUNCTION__ << endl; };
    //
    Button btn31;
    static void cb_btn31(Address,Address pw) { reference_to<My_window>(pw).btn31_pressed(); }
    void btn31_pressed() { cout << __PRETTY_FUNCTION__ << endl; };
    Button btn32;
    static void cb_btn32(Address,Address pw) { reference_to<My_window>(pw).btn32_pressed(); }
    void btn32_pressed() { cout << __PRETTY_FUNCTION__ << endl; };
    Button btn33;
    static void cb_btn33(Address,Address pw) { reference_to<My_window>(pw).btn33_pressed(); }
    void btn33_pressed() { cout << __PRETTY_FUNCTION__ << endl; };
    
};