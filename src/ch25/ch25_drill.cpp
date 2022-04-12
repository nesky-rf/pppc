#include "../std_lib_facilities.h"
#include <bitset>


int main()
{
    // _drill 1
    int v = 1; 
    for (int i = 0; i<sizeof(v)*8; ++i)
    { 
        cout << v << ' '; 
        v <<=1 ;
    }
    cout << endl;
    // _drill 2
    cout << bitset<8*sizeof(short unsigned int)>(0xffff) << endl;
    cout << bitset<8*sizeof(short unsigned int)>(0x0001) << endl;
    cout << bitset<8*sizeof(short unsigned int)>(0x8000) << endl;
    cout << bitset<8*sizeof(short unsigned int)>(0x00ff) << endl;
    cout << bitset<8*sizeof(short unsigned int)>(0xff00) << endl;
    cout << bitset<8*sizeof(short unsigned int)>(0x5555) << endl;
    cout << bitset<8*sizeof(short unsigned int)>(0xAAAA) << endl;
    return 0;
}