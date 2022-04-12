#include <iostream>

using namespace std;

class vector {
    int sz;
    double* elem;
    void copy(const vector& v);
public:
    explicit vector(int s)                   // default constructor
    : sz(s), elem(new double[s]) {

    }
    vector(const vector& v)                 // copy constructor
    : sz(v.sz), elem(new double[v.sz]) {
        copy(v);
    }
    vector& operator=(const vector& v);     // copy assignment
    ~vector() {                             // destructor
        delete [] elem; 
    }
    double& operator[](int n) {             // for non-const vectors
        return elem[n];
    }
    double operator[](int n) const {        // for const vectors
        return elem[n];
    }
    void set(int n, double d) {
        elem[n] = d;
    }
    double get(int n) {
        return elem[n];
    }
    friend ostream& operator<<(ostream& os, const vector& v);   // print elem to ostream
    int size() {
        return sz;
    }
};

void vector::copy(const vector& v)
{
    for(int i=0; i<v.sz; i++)
        elem[i] = v.elem[i];
}

ostream& operator<<(ostream& os, const vector& v)
{
    for(int i=0; i<v.sz; i++)
        os << '[' << i << ']' << '=' << v.elem[i] << ',';
    return os;
}

vector& vector::operator=(const vector& v)
{
    if(this == &v) return *this;    // check if same object before delete!
    delete[] elem;
    elem = new double[v.sz];
    copy(v);
    sz = v.sz;
    
    return *this;
}

int main()
{
    vector v1(2);
    v1.set(1,9.4);
    cout << "&v1: " << &v1 << ", sz= " << v1.size() << endl;
    cout << "[0]= " << v1.get(0) << ", [1]= " << v1.get(1) << ", [2]= " << v1.get(2) << endl;

    vector v2=v1;
    v2.set(1,2.4);
    cout << "&v2: " << &v2 << ", sz= " << v2.size() << endl;
    cout << "[0]= " << v2.get(0) << ", [1]= " << v2.get(1) << ", [2]= " << v2.get(2) << endl;

    vector v3(3);
    v3.set(2,2.2);
    cout << "&v3: " << &v3 << ", sz= " << v3.size() << ", elem: ";
    cout << v3 << endl;
    
    vector v4(4);
    v4.set(2,6.8);
    cout << "&v4: " << &v4 << ", sz= " << v4.size() << ", elem: ";
    cout << v4 << endl;
    v4=v3;
    cout << "&v4: " << &v4 << ", sz= " << v4.size() << ", elem: ";
    cout << v4 << endl;

    double x = v4[2];
    cout << "x= " << x << endl;

    v4[2] = 5.3;

    return 0;
}