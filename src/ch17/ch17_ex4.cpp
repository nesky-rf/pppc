#include <iostream>

using namespace std;

char* strdup(const char* c)
{
    int n= 0;
    while(c[n] != '\0')
        n++;
    
    char* pc= new char(n+1);
    for(int i=0; i< n; i++)
        pc[i] = c[i];
    pc[n] = '\0';

    return pc;
}

int main()
{
    char c[]={"Hello World!"};
    cout << "i: " << c << endl;
    //
    {
        int n= 0;
        while(c[n] != '\0')
            n++;
        cout << "li: " << n << endl; 
    }
    //
    char* pc = strdup(c);
    cout << "e: " << pc << endl;
    //
    {
        int n= 0;
        while(pc[n] != '\0')
            n++;
        cout << "le: " << n << endl; 
    }
    //
    delete[] pc;
    
    return 0;
}