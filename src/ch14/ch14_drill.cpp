#include "../std_lib_facilities.h"

struct B1
{
public:
    virtual void pvf()=0;
    virtual void vf() { cout << "B1::vf()" << endl; }
    void f() { cout << "B1::f()" << endl; }
};

struct D1 : B1 
{
public:
    void pvf() { cout << "D1::pvf()" << endl; } 
    void vf() { cout << "D1::vf()" << endl; }   // overrides!
    void f() { cout << "D1::f()" << endl; }     // does not override
};

struct D2 : D1
{
    void pvf() { cout << "D2::pvf()" << endl; }
    void vf() { cout << "D2::vf()" << endl; }   // overrides!
    void f() { cout << "D2::f()" << endl; }     // does not override
};

void ex1()
{
    cout << "ex1....\n";
#if 0
    B1 b1;
    b1.vf();
    b1.f();
#endif
    D1 d1;
    d1.vf();
    d1.f();

    B1& d2(d1);
    d2.vf();
    d2.f();
}

void ex2()
{
    cout << "ex2....\n";
    D1 d1;
    d1.pvf();
    d1.vf();
    d1.f();
}

void ex3()
{
    cout << "ex3....\n";
    D2 d2;
    d2.pvf();
    d2.vf();
    d2.f();
}

int main()
{
    ex1();  // defined w/o pure virtual function B1::pvf
    ex2();  // define B1::pvf
    ex3();  // define D2::pvf
    return 0;
}
