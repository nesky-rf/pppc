#include "../std_lib_facilities.h"
#include <fstream>

double celsius_to_fah(double);

struct Reading {
    int hour;
    double temperature;
    string unit;

    Reading(): hour(0), temperature(0) {}
    Reading(int h, double t, string u): hour(h), temperature(t), unit(u) {}

    friend ostream& operator<<(ostream& ost, Reading& r) {
        return ost << r.hour << " " << r.temperature << r.unit << endl;
    }

    friend istream& operator>>(istream& ist, Reading& r) {
        ist >> r.hour >> r.temperature >> r.unit;
        if( r.unit == "c")
            r.temperature = celsius_to_fah(r.temperature);
        else if(r.unit != "f")
            error("data corrupted");
        return ist;
    }

    bool operator< (const Reading& r) { return temperature < r.temperature; }
};

double celsius_to_fah( double c)
{
    return (c*9/5)+32;
}


int main()
{
    ifstream ifs("raw_temps.txt");
    if(!ifs) error("unable to open file");

    Reading r;
    vector<Reading> readings;
    double sum=0;

    while(ifs>>r) {
        readings.push_back(r);
        sum += r.temperature;
    }

    cout << "Mean: " << sum/readings.size() << endl;
    sort(readings.begin(),readings.end());
    cout << "Median: " << readings[24].temperature << endl;
    

    return 0;
}