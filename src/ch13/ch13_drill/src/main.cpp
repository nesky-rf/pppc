#include "../include/Simple_window.h"
#include "../include/Graph.h"

void Display_grid(Simple_window&);
void Display_diagonal(Simple_window&);
void Display_image(Simple_window&);
void Move_image(Simple_window&);

int main(int, char**) {
    try
    {
        using namespace Graph_lib;   // our graphics facilities are in Graph_lib

        Point tl(100,100);           // to become top left  corner of window
        Simple_window win(tl,800,1000,"chapter13_drill");    // make a simple window

        cout << "screen size: " << x_max() << "," << y_max() << endl;
        cout << "window size: " << win.x_max() << "," << win.y_max() << endl;

        // Display_grid(win);
        // Display_diagonal(win);
        // Display_image(win);
        Move_image(win);
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

void Display_grid(Simple_window& win)
{
    int x_size = 800;
    int y_size = 800;

    int x_grid = 100;
    int y_grid = 100;

    Lines vertical;
    for (int x = x_grid; x < x_size; x+=x_grid)
        vertical.add(Point(x,0),Point(x,y_size));

    Lines horizontal;
    for (int y = y_grid; y < y_size; y+=y_grid)
        horizontal.add(Point(0,y),Point(x_size,y));
    
    win.attach(vertical);
    win.attach(horizontal);
    win.wait_for_button();
}

void Display_diagonal(Simple_window& win)
{
    int x_size=800;
    int x_grid=100;

    Vector_ref<Rectangle> diag;

    for(int i=0; i < x_size; i +=x_grid)
    {
        diag.push_back(new Rectangle(Point(i,i),Point(i+x_grid,i+x_grid)));
        diag[diag.size()-1].set_color(Color::red);
        win.attach(diag[diag.size()-1]);
    }

    win.wait_for_button();
}

void Display_image(Simple_window& win)
{
    srand(time(NULL));
    Vector_ref<Image> pacs;

    for(int i=0; i<3; ++i)
    {
        pacs.push_back(new Image(Point(rand()%600,rand()%600), "pac_man.jpg"));
        win.attach(pacs[pacs.size()-1]);
    }
    
    win.wait_for_button();
}

void Move_image(Simple_window& win)
{
    srand(time(NULL));

    Image img(Point(0,0),"star.jpg");
    win.attach(img);

    int count=0;
    int new_pos=0;

    while(win.wait_for_button()&&count<10)
    {
        new_pos= rand()%64;
        cout << "pos (" << new_pos << "): "<< (new_pos%8)*100 << ',' << (new_pos/8)*100 << endl;
        img.move((new_pos%8)*100-img.point(0).x,(new_pos/8)*100-img.point(0).y);
        
        count++;
    }

}