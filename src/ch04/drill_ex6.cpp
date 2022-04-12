#include "../std_lib_facilities.h"

int main() {
    double current, min=0, max=0;

    cout << "Enter a double.\n...\n";
    while(cin >> current) {
        cout << "Value entered: " << current << ".\n";
        if( min == 0 && max == 0) {
            min = current;
            max = current;
        }
        else if(current < min){
            cout << "The smaller value so far.\n";
            min = current;
        }
        else if( current > max){
            cout << "The largest value so far.\n";
            max = current;
        }
        cout << "...\n";
    }

    if( !cin.good())
        cout << "Only integer values are allowed.\n";

    return 0;
}