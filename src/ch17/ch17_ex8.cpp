#include <iostream>

using namespace std;

int main()
{
    try
    {
        string s1;
        char c;

        while(cin>>c && c!='!')
            s1.push_back(c);

        cout << s1 << endl;
        cout << "addr s1: " << &s1 << endl;

        string s2;
        while(cin>>c && c!='!')
            s2.push_back(c);

        cout << s2 << endl;
        cout << "addr s2: " << &s2 << endl;

        cout << "s1-s2: " << &s2-&s1 << endl;
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