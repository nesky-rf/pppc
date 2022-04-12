#include <iostream>

using namespace std;

// an almost real vector of doubles
template <class T, class A= allocator<T>> class vector {
/*
    innvariant:
        for O<=n<sz elem [n] is element n
        sz<=space;
        if sz<space there is space ior (space-sz ) doubles after elem[sz-1]
*/
    A alloc;                                // 
    int sz;                                 //
    T* elem;                                // 
    int space;                              // free slots
public:
    // explicit constructor, destructor, assignment
    vector(): sz(0), elem(0), space(0) { }  // default constructor          
    explicit vector(int s);                 // 1-arg constructor
    vector(const vector& v);                // copy constructor
    T& operator=(const T& v);               // copy assignment
    ~vector() { delete [] elem; }           // destructor 
    // member functions for accessing elements
    T& at(int n);                           // checked access for non const vector
    const T& at(int n) const;               // checked access for const vectors
    T& operator[](int n);                   // unchecked access for non-const vectors
    const T& operator[](int n) const;       // unchecked access for const vectors
    //
    void set(T d, int n) { elem[n] = d; }   // setter -> superseded by subscript []
    T get(int n) { return elem[n]; }        // getter -> superseded by subscript []
    int size() { return sz; }               // read current size of elements
    int capacity() { return space; }        // read capacity for max allocation
    // memeber functions for memory allocation
    void resize(int newsize,T d=T());       // resize vector with initilized data
    void push_back(const T& d);             // add new element d at the back of vector
    void reserve(int newalloc);             // asign new capacity
    // iterators member functions
    typedef T* iterator;                    // elem* is the simplest iterator
    iterator begin() { return &elem[0]; }   // basic begin iterator
    iterator end() { return &elem[sz]; }    // basic end iterator
    iterator insert(iterator pos, const T& v);  // allows insert elem v at pos
    iterator erase(iterator pos);           // remove elem at pos
};

template<class T, class A> vector<T,A>::vector(int s)
    : sz(s), elem(alloc.allocate(s)), space(s) {
        for(int i=0;i<sz;i++) alloc.construct(&elem[i],T());        // initialize vector values to default
}

template<class T, class A> vector<T,A>::vector(const vector& v)
    : sz(v.sz), elem(alloc.allocate(v.sz)), space(v.sz) {
    for(int i=0; i<v.sz; i++) alloc.construct(&elem[i],v.elem[i]);  // initialize vector values to new vector
}

template<class T, class A> T& vector<T,A>::operator=(const T& v)
{
    if(this == &v) return *this;            // check if same object before delete!

    if(v.sz <= space) {
        for(int i=0; i<sz;i++) alloc.construct(&elem[i],v.elem[i]);
        sz= v.sz;
        return *this;
    }

    T* p = alloc.allocate(v.sz);            // allocate new space for vector
    for(int i=0; i<v.sz; i++) alloc.construct(&p[i],v.elem[i]);
    for(int i=0; i<sz; i++) alloc.destroy(&elem[i]);    // remove old elements
    alloc.deallocate(elem);                 // give old space back to free memory
    elem = p;
    sz = space = v.sz;
    return *this;
}

struct Range_error : out_of_range {	// enhanced vector range error reporting
	int index;
	Range_error(int i)
    : out_of_range("Range error: " + to_string(i)), index(i) { }
};

template<class T, class A> T& vector<T,A>::at(int n)
{
    if(n<0||n>sz) throw Range_error();
    return(elem[n]);
}

template<class T, class A> const T& vector<T,A>::at(int n) const
{
    if(n<0||n>sz) throw Range_error();
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
    T* p= alloc.allocate(newalloc);
    for (int i = 0; i < sz; i++) alloc.construct(&p[i],elem[i]);
    for (int i = 0; i < sz; i++) alloc.destroy(&elem[i]);
    alloc.deallocate(elem,space);
    elem = p;
    space = newalloc;
}

template<class T, class A> 
typename vector<T,A>::iterator vector<T,A>::insert(iterator pos, const T& v)
{
    if(space==0) reserve(8);
    else if(sz==space) reserve(2*space);
    for(iterator p =end(); p!= pos; --p)
        *p = *(p-1);
    alloc.construct(pos,v);
    ++sz;
    return pos;
}

template<class T, class A>
typename vector<T,A>::iterator vector<T,A>::erase(iterator pos)
{
    for(iterator p=pos+1; p != end(); ++p)
        *(p-1) = *p;
    alloc.destroy(&elem[sz]);
    --sz;
    return pos;
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

    cout << "vector::iterator" << endl;
    cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    cout << ", elem: ";
    for(vector<int>::iterator p=v2.begin(); p!=v2.end(); p++)
        cout << *p << ',';
    cout << endl;
    cout << "vector::insert" << endl;
    v2.insert(&v2[0],30);
    cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    cout << ", elem: " << v2 << endl;
    cout << "vector::erase" << endl;
    v2.erase(&v2[1]);
    cout << "&v2: " << &v2 << ", sz= " << v2.size() << ", space= " << v2.capacity();
    cout << ", elem: " << v2 << endl;

    return 0;
}