#include <iostream>

using namespace std;

int main()
{
    try
    {
        int n=0;
        while(true)
        {
            cout << ++n << "MB" << endl;
            double* pd = new double[131072];
        }

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