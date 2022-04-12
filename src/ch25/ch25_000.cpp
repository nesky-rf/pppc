#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    // int i=0;

    // while(cin >> i)
    //     cout << dec << i << '\n'
    //      << hex << "0x" << i << '\n'
    //      << bitset<8*sizeof(int)> (i) << '\n';

    enum Printer_flags {
        acknowledge=1 ,
        paper_empty=1<<1,
        busy=1<<2,
        out_of_black=1<<3,
        out_of_color=1<<4,
        // . . .
    }; 
    Printer_flags stat = Printer_flags(acknowledge|out_of_color);
    cout << bitset<2*sizeof(int)> (stat) << ',' << stat << endl;

    struct PPN { // R6000 Physical Page Number
        // Page Frame Number
        unsigned int PFN : 22;
        // u nused
        int : 3;
        unsigned int CCA : 3;
        // Cache Coherency Algorithm
        bool nonreachable : 1;
        bool dirty : 1;
        bool valid : 1;
        bool global : 1;
    };
    PPN pn;
    pn.CCA = 7;
    // unsigned int cca = (pn&0x0070);
    cout << "cca: " << pn.CCA << endl;

    return 0;
}