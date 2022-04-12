#include "../std_lib_facilities.h"

int main() {
    double val1, val2;

    cout << "Enter two double values.\n...\n";
    while(cin >> val1 >> val2) {
        if( abs(val1-val2) <= 1.0/10000000) {
            cout << "The numbers are almost equal.\n";
        } else {
            cout << "The smaller value is: " << min(val1,val2) << "\n";
            cout << "The larger value is: " << max(val1,val2) << "\n";
        }
        cout << "...\n";
    }

    if( !cin.good())
        cout << "Only integer values are allowed.\n";

    return 0;
}