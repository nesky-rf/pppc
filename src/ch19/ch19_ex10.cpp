#include <iostream>

using namespace std;

struct object {
    int val;
    object() {}
    object(int n): val(n) {}
    ~object() {}
    int* get() { return &val; }
};

template<class T> struct auto_ptr {
    T* val;
public:
    auto_ptr(T* loc): val(loc) {};
    ~auto_ptr() {delete val;};

    T* operator->() const;
    T operator*() const;
    T* release(); 
    T* get();
};

template<class T> T* auto_ptr<T>::operator->() const {
    return val;
}

template<class T> T auto_ptr<T>::operator*() const {
    return *val;
}

template<class T> T* auto_ptr<T>::release() {
    T* temp = val;
    val = nullptr;
    return temp;
}

template<class T> T* auto_ptr<T>::get() {
    return val;
}

int main()
{
    try
    {
        auto_ptr<int> p(new int(16));
        cout << "&auto_ptr: " << &p << ", &p: " << p.get() << ", val: " << *p << endl;
        p.release();
        cout << "&auto_ptr: " << &p << ", &p: " << p.get() << endl ;

        auto_ptr<object> o(new object(5));
        cout << "&auto_ptr: " << &o << ", &o: " << o.get() << ", val: " << o->val << endl;
        o.release();
        cout << "&auto_ptr: " << &o << ", &o: " << o.get() << endl ;

        return 0;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "Unknown error";
        return 2;
    }
    
}