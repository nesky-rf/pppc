#include "../std_lib_facilities.h"

int main() {
    double value, min=0, max=0, sum=0;
    string unit;
    vector<double> measures;

    cout << "Enter distance and unit (cm/m/in/ft).\n...\n";
    while(cin >> value >> unit) {
        
        if(unit == "cm") value /= 100.0;
        else if(unit == "m") {}
        else if(unit == "in") value /= 39.37;
        else if(unit == "ft") value /= 3.281;
        else if(unit == "|") break;
        else value = 0; 
        
        if(value >0) {
            cout << "Distance entered in meters [m]: " << value <<  "m.\n";
            sum += value;
            measures.push_back(value);
            if( min == 0 && max == 0) {
                min = value;
                max = value;
            }
            else if(value < min){
                cout << "The smalleest value so far.\n";
                min = value;
            }
            else if( value > max){
                cout << "The largest value so far.\n";
                max = value;
            }
            cout << "...\n";
        } else
            cout << "Wrong unit.\n...\n";
    }

    if( !cin.good())
        cout << "Only double followed by unit value is allowed.\n";
    else {
        sort(measures.begin(),measures.end());
        cout << "Summary (expressed in m)\n";
        cout << "Values entered are: ";
        for (int i=0; i<measures.size();i++) cout << measures[i] << ", ";
        cout << "\nThe smallest value is " << min << "\n";
        cout << "The largest value is " << max << "\n";
        cout << "The aggregated sum is " << sum << "\n";
    }

    return 0;
}