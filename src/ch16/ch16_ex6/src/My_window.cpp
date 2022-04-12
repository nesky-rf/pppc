#include "../include/My_window.h"

My_window::My_window(Point xy, int w, int h, const string& title)
    : Simple_window(xy,w,h,title),
    text(Point(x_max()/2-30,y_max()-80),60,20,""),
    btn11(Point(x_max()/2-50,100),30,30,"11",cb_btn11),
    btn12(Point(x_max()/2-10,100),30,30,"12",cb_btn12),
    btn13(Point(x_max()/2+30,100),30,30,"13",cb_btn13),
    btn21(Point(x_max()/2-50,140),30,30,"21",cb_btn21),
    btn22(Point(x_max()/2-10,140),30,30,"22",cb_btn22),
    btn23(Point(x_max()/2+30,140),30,30,"23",cb_btn23),
    btn31(Point(x_max()/2-50,180),30,30,"31",cb_btn31),
    btn32(Point(x_max()/2-10,180),30,30,"32",cb_btn32),
    btn33(Point(x_max()/2+30,180),30,30,"33",cb_btn33)
{
    attach(text);
    attach(btn11); attach(btn12); attach(btn13);
    attach(btn21); attach(btn22); attach(btn23);
    attach(btn31); attach(btn32); attach(btn33);
}


