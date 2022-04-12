#include "../include/Lines_window.h"
#include "../include/Graph.h"

int main() {
    try
    {
        Lines_window win(Point(100,100),600,400,"lines");
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

