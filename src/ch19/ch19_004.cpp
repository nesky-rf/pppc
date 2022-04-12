#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

// an almost real vector of doubles
template <class T, class A= allocator<T>> class vector {
    A alloc;
/*
    innvariant:
        for O<=n<sz elem [n] is element n
        sz<=space;
        if sz<space there is space ior (space-sz ) doubles after elem[sz-1]
*/

    int sz;
    T* elem;
    int space;                              // free slots
public:
    vector()
    : sz(0), elem(0), space(0) {            // default constructor

    }
    explicit vector(int s)                   // 1-arg constructor
    : sz(s), elem(new T[s]), space(s) {
        for(int i=0;i<sz;i++) elem[i]=0;    //      initialize vector values
    }
    vector(const vector& v)                 // copy constructor
    : sz(v.sz), elem(new T[v.sz]), space(v.sz) {
        for(int i=0; i<v.sz; i++)
            elem[i] = v.elem[i];
    }
    T& operator=(const T& v);          // copy assignment
    ~vector() {                             // destructor
        delete [] elem; 
    }
    // member functions for accessing elements
    T& at(int n);                           // checked access for non const vector
    const T& at(int n) const;               // chacked access for const vectors
    T& operator[](int n);                   // unchecked access for non-const vectors
    const T& operator[](int n) const;       // unchecked access for const vectors
    //
    void set(int n, T d) {
        elem[n] = d;
    }
    T get(int n) {
        return elem[n];
    }
    int size() {
        return sz;
    }
    int capacity() {
        return space;
    }
    void resize(int newsize,T d=T());
    void push_back(const T& d);
    void reserve(int newalloc);
};

template<class T, class A> T& vector<T,A>::operator=(const T& v)
{
    if(this == &v) return *this;    // check if same object before delete!

    if(v.sz <= space) {
        for(int i=0;i<sz;i++) elem[i]=v.elem[i];
        sz= v.sz;
        return *this;
    }

    T* p = new T[v.sz];
    for(int i=0; i<v.sz; i++)
        p[i] = v.elem[i];
    delete[] elem;
    elem = p;
    sz = space = v.sz;
    return *this;
}

// struct out_of_range {};

template<class T, class A> T& vector<T,A>::at(int n)
{
    if(n<0||n>sz) throw out_of_range();
    return(elem[n]);
}

template<class T, class A> const T& vector<T,A>::at(int n) const
{
    if(n<0||n>sz) throw out_of_range();
    return(elem[n]);
}

template<class T, class A> T& vector<T,A>::operator[](int n)
{
    return elem[n];
}

template<class T, class A> const T& vector<T,A>::operator[](int n) const
{
    return elem[n];
}


template<class T, class A> void vector<T,A>::resize(int newsize, T d)
{
    reserve(newsize);
    for(int i=sz;i<newsize;i++) alloc.construct(&elem[i],d);
    for(int i=newsize;i<sz;i++) alloc.destroy(&elem[i]);
    sz = newsize;
}

template<class T, class A> void vector<T,A>::push_back(const T& d)
{
    if(space==0) reserve(8);
    else if(sz==space) reserve(2*space);
    alloc.construct(&elem[sz],d);
    ++sz;
}

template<class T, class A> void vector<T,A>::reserve(int newalloc)
{
    if(newalloc <= space) return;
    auto_ptr<T> p(alloc.allocate(newalloc));
    for (int i = 0; i < sz; i++) alloc.construct(&p.get()[i],elem[i]);
    for (int i = 0; i < sz; i++) alloc.destroy(&elem[i]);
    alloc.deallocate(elem,space);
    elem = p.release();
    space = newalloc;
}

template<class T> ostream& operator<<(ostream& os, vector<T>& v)
{
    for(int i=0; i<v.size(); i++)
        os << '[' << i << ']' << '=' << v.get(i) << ',';
    return os;
}

int main()
{
    vector<double> v1(4);
    v1.set(2,6.8);
    cout << "&v1: " << &v1 << ", sz= " << v1.size() << ", space= " << v1.capacity();
    cout << ", elem: " << v1<< endl;

    vector<int> v2(3);
    v2.push_back(1); 
    cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    cout << ", elem: " << v2 << endl;
    v2.push_back(2); v2.push_back(3); v2.push_back(4);
    cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    cout << ", elem: " << v2 << endl;
    v2.push_back(5); v2.push_back(6); v2.push_back(7);
    cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    cout << ", elem: " << v2 << endl;

    return 0;
}