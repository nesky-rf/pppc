#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<double>& v)
{
    for(int i=0; i < v.size(); i++)
        cout << "[" << i << "]=" << v[i] << ",";
    cout << endl;
}

int main()
{
    vector<double> d(3);

    cout << &d[0] << ',' << &d[2] << ": elem " << endl;
    print_vector(d);

    d[0]= 3.5;
    print_vector(d);
    d.push_back(4.6);
    print_vector(d);
    d.push_back(4.6);
    print_vector(d);
    return 0;
}