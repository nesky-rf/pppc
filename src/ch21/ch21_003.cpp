#include "../std_lib_facilities.h"
#include <map>
#include <numeric>

double get_weighted(const pair<string,double>& a, const pair<string,double>& b)
{
    return a.second * b.second;
}

int main()
{
    map<string,double> dow_price;
    dow_price["MMM"] = 81.86;
    dow_price["AA"] = 34.69;
    dow_price["MO"] = 54.45;

    map<string,double> dow_weight;
    dow_weight.insert(make_pair("MMM",5.8549));
    dow_weight.insert(make_pair("AA",2.4808));
    dow_weight.insert(make_pair("M0",3.8940));

    map<string,string> dow_name;
    dow_name["MMM"] = "3M Co.";
    dow_name["AA"] = "Alcoa Inc.";
    dow_name["MO"] = "Aitria Group Inc.";

    // find symbols
    if(dow_price.find("INTC") != dow_price.end())
        cout << "INTC found" << endl;
    else
        cout << "INTC not found" << endl;
    // print pairs
    typedef map<string,double>::const_iterator iter;
    for(iter p=dow_price.begin(); p != dow_price.end(); ++p)
    {
        const string& symbol = p->first;
        cout << dow_name[symbol] << ':' << '(' << symbol << ',' << p->second << ')' << endl;
    }
    // compute
    double dji_index = inner_product(dow_price.begin(),dow_price.end(),dow_weight.begin(),0.0,plus<double>(),get_weighted);
    cout << "DJI index: " << dji_index << endl;

    return 0;
}