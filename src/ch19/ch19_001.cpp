#include <iostream>

using namespace std;

// an almost real vector of doubles
class vector {

/*
    innvariant:
        for O<=n<sz elem [n] is element n
        sz<=space;
        if sz<space there is space ior (space-sz ) doubles after elem[sz-1]
*/

    int sz;
    double* elem;
    int space;                              // free slots
    void copy(const vector& v);
public:
    vector()
    : sz(0), elem(0), space(0) {            // default constructor

    }
    explicit vector(int s)                   // 1-arg constructor
    : sz(s), elem(new double[s]), space(s) {
        for(int i=0;i<sz;i++) elem[i]=0;    //      initialize vector values
    }
    vector(const vector& v)                 // copy constructor
    : sz(v.sz), elem(new double[v.sz]), space(v.sz) {
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
    int capacity() {
        return space;
    }
    void resize(int newsize);
    void push_back(const double& d);
    void reserve(int newalloc);
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

    if(v.sz <= space) {
        for(int i=0;i<sz;i++) elem[i]=v.elem[i];
        sz= v.sz;
        return *this;
    }

    double* p = new double[v.sz];
    copy(v);
    delete[] elem;
    elem = p;
    sz = space = v.sz;
    return *this;
}

void vector::resize(int newsize)
{
    reserve(newsize);
    for(int i=sz;i<newsize;i++)
        elem[i] = 0;
    sz = newsize;
}

void vector::push_back(const double& d)
{
    if(space==0) reserve(8);
    else if(sz==space) reserve(2*space);
    elem[sz] = d;
    ++sz;
}

void vector::reserve(int newalloc)
{
    if(newalloc < space) return;
    double* p= new double[newalloc];
    for (int i = 0; i < sz; i++)
        p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

int main()
{
    vector v1(2);
    v1.set(1,9.4);
    cout << "&v1: " << &v1 << ", sz= " << v1.size();
    cout << ", elem: [0]=" << v1.get(0) << ",[1]=" << v1.get(1) << ",[2]=" << v1.get(2) << endl;

    vector v2=v1;
    v2.set(1,2.4);
    cout << "&v2: " << &v2 << ", sz= " << v2.size();
    cout << ", elem: [0]=" << v2.get(0) << ",[1]=" << v2.get(1) << ",[2]=" << v2.get(2) << endl;

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

    vector v5(3);
    v5.push_back(1); 
    cout << "&v5: " << &v5 << ", sz= " << v5.size() << ", capacity= " << v5.capacity();
    cout << ", elem: " << v5 << endl;
    v5.push_back(2); v5.push_back(3); v5.push_back(4);
    cout << "&v5: " << &v5 << ", sz= " << v5.size() << ", capacity= " << v5.capacity();
    cout << ", elem: " << v5 << endl;
    v5.push_back(5); v5.push_back(6); v5.push_back(7);
    cout << "&v5: " << &v5 << ", sz= " << v5.size() << ", capacity= " << v5.capacity();
    cout << ", elem: " << v5 << endl;

    return 0;
}