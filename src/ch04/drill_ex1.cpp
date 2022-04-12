#include "../std_lib_facilities.h"

int main() {
    int val1, val2;

    cout << "Enter two integer values.\n...\n";
    while(cin >> val1 >> val2)
        cout << "Val1= " << val1 << ", Val2= " << val2 << "\n...\n";

    if( !cin.good())
        cout << "Only integer values are allowed.\n";

    return 0;
}