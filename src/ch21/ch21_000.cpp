#include "../std_lib_facilities.h"
#include <numeric>
#include <array>

struct Record {
    double unit_price;
    int units;
    
};

struct acc_record {
    double operator()(double d, const Record& r) { return d + r.unit_price * r.units;}
};

double price(double d, const Record& r)
{
    return d + r.unit_price * r.units;
}

int main()
{
    vector<Record> vr {{2.6,10},{3.7,5},{7.6,7}};
    cout << "accumulate" << endl;
    // dealing with plain functions
    double funcTotal = accumulate(vr.begin(),vr.end(),0.0,price);
    // using fucntion objects (preferred solution)
    double objTotal = accumulate(vr.begin(),vr.end(),0.0,acc_record());
    cout << "total: " << funcTotal << ',' << objTotal << endl;

    array<double,3> a {2.6,3.7,7.6};
    double arrTotal = accumulate(a.begin(),a.end(),1.0,multiplies<double>());
    cout << "total: " << arrTotal << endl;
    cout << "------------" << endl;

    // calculale the Dow Jones I ndustrial i ndex:
    cout << "inner product" << endl;
    vector<double> dow_price;
    // share price for each company
    dow_price.push_back(81.86);
    dow_price.push_back(34.69);
    dow_price.push_back(54.45);
    // ...
    list<double> dow_weight;
    // weighl in i ndex for each company
    dow_weight.push_back(5.8549);
    dow_weight.push_back(2.4808);
    dow_weight.push_back(3.8940);
    // ... mult iply (weight, value) pairs and add
    double dji_index = inner_product(dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0);
    double dji2_index = inner_product(dow_price.begin(), dow_price.end(), dow_weight.begin(),0.0,plus<double>(),multiplies<double>());
    cout << "DJI value " << dji_index << ',' << dji2_index <<'\n' ;
    return 0;
}