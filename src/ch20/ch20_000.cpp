#include "../std_lib_facilities.h"

template<class Iterator> 
Iterator high (Iterator first, Iterator last)
// return an iterator to the element i n !first:last) that has the h ighest value
{
    Iterator high = first;
    for(Iterator p=first; p!=last; ++p)
        if(*p>*high) high = p;
    return high;
}

int main()
{
    vector<double> d;
    d.push_back(2.5);
    d.push_back(9.5);
    d.push_back(5.2);
    for(int k=0; k< d.size(); ++k ) cout << &d.at(k) << ", " << "["<<k<<"]= " << d.at(k) << endl;
    cout << "high: " << *high<double*>(&d[0],&d[d.size()]) << endl;

    vector<double>* i=&d;
    i->push_back(2);
    i->push_back(9);
    i->push_back(10.5);
    for(int k=0; k< i->size(); ++k ) cout << &i->at(k) << ", " << "["<<k<<"]= " << i->at(k) << endl;
    cout << "high: " << *high<double*>(&i->at(0),&i->at(0)+i->size()) << endl;
    
    return 0;
}