#include "std_lib_facilities.h"

int main() {
    cout << "Enter thre values to display orderly:\n";
    int val1, val2, val3;
    int current, previous, preprevious;
    while(cin >> current) {
        if(current<=previous){
            val1=current;
            val2=previous;
            val3=preprevious;
        }
        else{
            if(current < preprevious) {
                val1=previous;
                val2=current;
                val3=preprevious;
            }
        }
        preprevious=previous;
        previous=current;
    }

    cout << "Order: " << val1 << " ," << val2 << " ," << val3 << ".\n";

    return 0;
}