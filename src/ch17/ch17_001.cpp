#include <iostream>

using namespace std;

struct vector {
    int sz;
    double* elem;
public:
    vector(int n): sz(n), elem(new double[n]) {
        cout << __PRETTY_FUNCTION__ << endl;
        for (int i = 0; i < n; i++)
            elem[i]=0.0;
    }
    virtual ~vector() { 
        cout << __PRETTY_FUNCTION__ << endl;
        delete[] elem;
    }
    int size() const { return sz;}
    double& operator[](int e) const;
};

double& vector::operator[](int e) const
{
    if(e > sz) {
        cerr << "Out of bounds" << endl;
        exit(0);    
    }
    return elem[e];
}

ostream& operator<<(ostream& os, const vector& v)
{
    for (int i = 0; i < v.size(); i++)
        os << v[i] << ',';
    return os;   
}


int main()
{
    vector one(5);
    for (int i = 0; i < one.size(); i++)
        one[i] = 1.1*i;
    
    cout << one << endl;

    return 0;
}