#include <iostream>
#include <vector>

using namespace std;

struct X {  // simple test class
    int val;

    void out(const string& s)
    { cerr << ':' << this << "->" << s << ": " << val << "\n"; }

    X(){ val=0; out("X()"); }   // default constructor

    X(int v) { val=v; out("X(int)"); }

    X(const X& x){ val=x.val; out("X(X&) "); } // copy constructor

    X& operator=(const X& a) // copy assignment
    { val=a.val; out("X::operator=()"); return *this; }
    
    ~X(){ out("~X()"); } // destructor
};

X glob(2);  // a global variable
X copy(X a) { return a; }
X copy2(X a) { X aa = a; return aa; }
X& ref_to(X& a) { return a; }
X* make(int i) { X a(i); return new X(a); }
struct XX { X a; X b; };

int main()
{
    cout << ">>>> main()" << endl;
    cout << "X loc(4)" << endl;
    X loc(4);
    cout << "X loc2 = loc" << endl;
    X loc2 = loc;
    cout << "loc = X(5)" << endl;
    loc = X(5);
    cout << "loc2 = copy(loc)" << endl;
    loc2 = copy(loc);
    cout << "loc2 = copy2(loc)" << endl;
    loc2 = copy2(loc);
    cout << "X loc3(6)" << endl;
    X loc3(6);
    cout << "X& r = ref_to(loc)" << endl;
    X& r = ref_to(loc);
    cout << "delete make(7)" << endl;
    delete make(7);
    cout << "delete make(8)" << endl;
    delete make(8);
    cout << "vector<X> v(4)" << endl;
    vector<X> v(4);
    cout << "XX loc4" << endl;
    XX loc4;
    cout << "X* p = new X(9)" << endl;
    X* p = new X(9);
    cout << "delete p" << endl;
    delete p;
    cout << "X* pp = new X[5]" << endl;
    X* pp = new X[5];
    cout << "delete[] pp" << endl;
    delete[] pp;
    cout << ">>>> ~main()" << endl;
    return 0;
}