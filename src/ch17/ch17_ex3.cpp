#include <iostream>

using namespace std;

void to_lower(char* s)
{
    int i=0;
    while(s[i]!= '\0')
    {
        if(s[i]>0x40 && s[i] < 0x5b)
            s[i] += 0x20;
        i++;
    }
}

int main()
{
    char c[]={"Hello World!"};
    cout << "i: " << c << endl;
    to_lower(&c[0]);
    cout << "e: " << c << endl;

    return 0;
}