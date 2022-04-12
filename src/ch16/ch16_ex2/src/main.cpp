#include "../include/My_window.h"
#include "../include/Graph.h"


int main() {
    try
    {
        My_window win(Point(100,100),600,400,"my_window");
        return gui_main();
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

