#include "../include/Simple_window.h"
#include "../include/Graph.h"

class Scale {
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int v, int vb, double s)
    : cbase(v), vbase(vb), scale(s) {}
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

double slope(double x) {return x/2; }

int main() {
    try
    {
        const int xmax = 600;    // window size
        const int ymax = 600;

        const int xoffset = 100; // distance from left hand side of window to y axis
        const int yoffset = 100;  // distance from bottom of window to x axis

        const int xspace = 100;   // space beyond axis
        const int yspace = 100; 

        const int xlength = xmax-xoffset-xspace;    // length of axes
        const int ylength = ymax-yoffset-yspace;

        Simple_window win(Point(xoffset,yoffset),xmax,ymax,"Function graphs");

        Axis x(Axis::x,Point(xoffset,ymax/2),xlength,20,"1==20px");
        x.set_color(Color::red);
        Axis y(Axis::y,Point(xmax/2,ymax-yoffset),ylength,20,"1==20px");
        y.set_color(Color::red);

        const int xscale = 20;
        const int yscale = 20;
        const int base_func = -10;
        const int num_points = 400;

        Scale xs(xoffset,base_func,xscale);
        Scale ys(ymax-yoffset,0,-yscale);

        Function    f1(cos,base_func,11,{300,300},num_points,xscale,yscale);
        Function_s  f2(sin,base_func,11,{300,300},num_points,xscale,yscale);

        win.attach(x);
        win.attach(y);
        win.attach(f1);
        win.attach(f2);
        win.wait_for_button();
        f2.set_func(slope);
        win.wait_for_button();
        f2.set_count(5);
        win.wait_for_button();
        f2.set_origin({300,200});
        win.wait_for_button();
        f2.set_scale(10,10);
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

