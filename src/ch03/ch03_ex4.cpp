#include "std_lib_facilities.h"

int main() {
    cout << "Enter to values to perform operations:\n";
    int val1, val2;
    cin >> val1 >> val2;
    cout << "Operands: val1=" << val1 << ", val2=" << val2 << ".\n";
    cout << "The smallest value is " << (val1<val2? "val1.\n": "val2.\n");
    cout << "The largest value is " << (val1>val2? "val1.\n": "val2.\n");
    cout << "The sum of val1+val2 is " << val1+val2 << ".\n";
    cout << "The difference of val1-val2 is " << val1-val2 << ".\n";
    cout << "The product of val1*val2 is " << val1*val2 << ".\n";
    cout << "The ratio of val1/val2 is " << val1/val2 << ".\n";

    return 0;
}