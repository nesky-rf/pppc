#include <iostream>

using namespace std;

int main()
{
    try
    {
        int i1=0;
        int i2=0;
        int i3=0;
        cout << "stack: " << &i1 << ',' << &i2 << ',' << &i3 << endl;
        cout << "stack " << ((&i3 > &i1)? "grows up": "grows down") << endl;

        int* pi1 = new int(0);
        int* pi2 = new int(0);
        int* pi3 = new int(0);
        cout << "heap: " << pi1 << ',' << pi2 << ',' << pi3 << endl;
        cout << "heap " << ((pi3 > pi1)? "grows up": "grows down") << endl;
        delete pi1;
        delete pi2;
        delete pi3;

        return 0;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    catch(...)
    {
        cerr << "Unknown exception" << endl;
    }
}