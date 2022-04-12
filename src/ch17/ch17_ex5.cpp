#include <iostream>

using namespace std;

char* findx(const char* s, const char* x)
{
    int n=0;
    while(s[n]!='\0')
        n++;

    char* pc;
    for(int i=0; i< n+1; i++)
    {
        *pc=s[i];
        if(*pc==*x)
            return pc;
    }
    return pc;
}

int main()
{
    try
    {
        char c[]={"Hello World!"};
        char x='e';

        cout << "i: " << c << endl;
        char* f = findx(c,&x);
        cout << "e: " << (*f?"yes":"no") << endl;

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