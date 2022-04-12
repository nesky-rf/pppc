#include <iostream>
#include <memory>

using namespace std;

template<class T, class A> struct vector_base {
    A alloc;    // allocator
    T* elem;    // start of allocation
    int sz;     // number of elements
    int space;  // amount of allocated space

    vector_base()
    : sz(0), elem(0), space(0) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    vector_base(const A& a, int n)
    : alloc(a), elem(a.allocate(n)), sz(n), space(n) {}
    ~vector_base() {
        cout << __PRETTY_FUNCTION__ << endl;
        alloc.deallocate(elem,space);
    }
};

// an almost real vector of doubles
template <class T, class A= allocator<T>> class vector
: private vector_base<T, A> {

/*
    innvariant:
        for O<=n<sz elem [n] is element n
        sz<=space;
        if sz<space there is space ior (space-sz ) doubles after elem[sz-1]
*/

public:
    vector()
    : vector_base<T,A>::vector_base() { }
    explicit vector(int s)                   // 1-arg constructor
    : vector_base<T,A>::vector_base(const allocator<A>& ,s)
    {
        // this->sz(s); this->elem(new T[s]); this->space(s);
        // for(int i=0;i<this->sz;i++) this->elem[i]=0;    //      initialize vector values

    }
    vector(const vector& v)                 // copy constructor
    {
        this->sz(v.sz); this->elem(new T[v.sz]); this->space(v.sz);
        for(int i=0; i<v.sz; i++)
            this->elem[i] = v.elem[i];
    }
    T& operator=(const T& v);               // copy assignment
    ~vector() { delete [] this->elem; }           // destructor

    // member functions for accessing elements
    T& at(int n);                           // checked access for non const vector
    const T& at(int n) const;               // chacked access for const vectors
    T& operator[](int n);                   // unchecked access for non-const vectors
    const T& operator[](int n) const;       // unchecked access for const vectors
    // member functions for setters, getters
    void set(int n, T d) { this->elem[n] = d; }
    T get(int n) { return this->elem[n]; }
    int size() { return this->sz; }
    int capacity() { return this->space; }
    // member functions for allocating space
    void resize(int newsize,T d=T());
    void push_back(const T& d);
    void reserve(int newalloc);
};

template<class T, class A> T& vector<T,A>::operator=(const T& v)
{
    if(this == &v) return *this;    // check if same object before delete!

    if(v.sz <= this->space) {
        for(int i=0;i<this->sz;i++) this->elem[i]=v.elem[i];
        this->sz= v.sz;
        return *this;
    }

    T* p = new T[v.sz];
    for(int i=0; i<v.sz; i++)
        p[i] = v.elem[i];
    delete[] this->elem;
    this->elem = p;
    this->sz = this->space = v.sz;
    return *this;
}


template<class T, class A> T& vector<T,A>::at(int n)
{
    if(n<0||n>this->sz) throw out_of_range();
    return(this->elem[n]);
}

template<class T, class A> const T& vector<T,A>::at(int n) const
{
    if(n<0||n>this->sz) throw out_of_range();
    return(this->elem[n]);
}

template<class T, class A> T& vector<T,A>::operator[](int n)
{
    return this->elem[n];
}

template<class T, class A> const T& vector<T,A>::operator[](int n) const
{
    return this->elem[n];
}


template<class T, class A> void vector<T,A>::resize(int newsize, T d)
{
    reserve(newsize);
    for(int i=this->sz;i<newsize;i++) this->alloc.construct(this->elem[i],d);
    for(int i=newsize;i<this->sz;i++) this->alloc.destroy(this->elem[i]);
    this->sz = newsize;
}

template<class T, class A> void vector<T,A>::push_back(const T& d)
{
    if(this->space==0) reserve(8);
    else if(this->sz==this->space) reserve(2*this->space);
    this->alloc.construct(this->elem[this->sz],d);
    ++this->sz;
}

template<class T, class A> void vector<T,A>::reserve(int newalloc)
{
    if(newalloc <= this->space) return;
    vector_base<T,A> p(this->alloc, newalloc);
    for (int i = 0; i < this->sz; i++) this->alloc.construct(&p[i],this->elem[i]);
    for (int i = 0; i < this->sz; i++) this->alloc.destroy(this->elem[i]);
    swap <vector_base<T,A>>(*this,p);
}

template<class T> ostream& operator<<(ostream& os, vector<T>& v)
{
    for(int i=0; i<v.size(); i++)
        os << '[' << i << ']' << '=' << v.get(i) << ',';
    return os;
}

int main()
{
    vector<int> v;
    cout << "&v: " << &v << ", sz= " << v.size() << ", space= " << v.capacity() << endl;

    // vector<double> v1(4);
    // v1.set(2,6.8);
    // cout << "&v1: " << &v1 << ", sz= " << v1.size() << ", space= " << v1.capacity();
    // cout << ", elem: " << v1<< endl;

    // vector<int> v2(3);
    // v2.push_back(1); 
    // cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    // cout << ", elem: " << v2 << endl;
    // v2.push_back(2); v2.push_back(3); v2.push_back(4);
    // cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    // cout << ", elem: " << v2 << endl;
    // v2.push_back(5); v2.push_back(6); v2.push_back(7);
    // cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    // cout << ", elem: " << v2 << endl;

    return 0;
}