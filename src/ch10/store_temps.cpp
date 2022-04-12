#include "../std_lib_facilities.h"
#include <fstream>

struct Reading {
    int hour;
    double temperature;
    string unit;
    Reading(int h, double t, string u): hour(h), temperature(t), unit(u) {}

    friend ostream& operator<<(ostream& ost, Reading& r) {
        return ost << r.hour << " " << r.temperature << r.unit << endl;
    }
};

enum units {c,f};

string str_units(int u)
{
    if(u == units::c)
        return "c";
    else if(u == units::f)
        return "f";
    else
        return "x";
}

int main()
{
    srand(time(NULL));

    ofstream ofs("raw_temps.txt");
    if(!ofs) error("unable to open file");

    for (int i = 0; i < 50; i++)
    {
        Reading read(rand()%23,rand()%200-100,str_units(rand()%2));
        ofs << read;
    }
    

    return 0;
}