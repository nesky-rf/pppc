#include "../std_lib_facilities.h"

using namespace std;

class Int {
public:
    Int()
    : val(0) {}
    Int(int i)
    : val(i) {}
    int& operator=(const int& v) {
        val = v;
        return val;
    }
    int read_value() {
        return val;
    }
    void set_value(const int& i) {
        val = i;
    }
private:
    int val;
};

bool operator==(Int& i, const int& j) {
    return (i.read_value() == j)? true: false;
}

bool operator!=(Int& i, const int& j) {
    return (i.read_value() == j)? false: true;
}

ostream& operator<<(ostream& os, Int& i)
{
    return  os << i.read_value();
}

int operator++(Int& i, int) {
    int val = i.read_value();
    i.set_value(val+1);
    return val;
}

int operator++(Int& i) {
    int val = i.read_value();
    val += 1;
    i.set_value(val);
    return val;
}

int operator+=(Int& i, int j) {
    int val = i.read_value();
    val += j;
    i.set_value(val);
    return val;
}

int operator-=(Int& i, int j) {
    int val = i.read_value();
    val -= j;
    i.set_value(val);
    return val;
}

int operator*=(Int& i, int j) {
    int val = i.read_value();
    val *= j;
    i.set_value(val);
    return val;
}

int operator/=(Int& i, int j) {
    int val = i.read_value();
    val /= j;
    i.set_value(val);
    return val;
}

int operator%=(Int& i, int j) {
    int val = i.read_value();
    val %= j;
    i.set_value(val);
    return val;
}

int operator&=(Int& i, int j) {
    int val = i.read_value();
    val &= j;
    i.set_value(val);
    return val;
}

int operator|=(Int& i, int j) {
    int val = i.read_value();
    val |= j;
    i.set_value(val);
    return val;
}

int operator^=(Int& i, int j) {
    int val = i.read_value();
    val ^= j;
    i.set_value(val);
    return val;
}

int operator<<=(Int& i, int j) {
    int val = i.read_value();
    val <<= j;
    i.set_value(val);
    return val;
}

int operator>>=(Int& i, int j) {
    int val = i.read_value();
    val >>= j;
    i.set_value(val);
    return val;
}

int main()
{
    try
    {
        Int e;
        const int ce=8;
        cout << "&e" << &e << ", e= " << e << ", ce= " << ce << endl; 

        e= 7;
        if(e != ce) cout << "operator!= success" << "(" << e << ',' << ce << ")" << endl;
        else cout << "operator!= failed" << "(" << e << ',' << ce << ")" << endl;
        e= 8;
        if(e == ce) cout << "operator== success" << "(" << e << ',' << ce << ")" << endl;
        else cout << "operator== failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce;
        if(e++ == ce) cout << "operator++ success**" << "(" << e << ',' << ce << ")" << endl;
        else cout << "operator++ failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce;
        if(++e == ce+1) cout << "operator++ success" << "(" << e << ',' << (ce+1) << ")" << endl;
        else cout << "operator++ failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e +=3;
        if(e == ce+3) cout << "operator+= success" << "(" << e << ',' << (ce+3) << ")" << endl;
        else cout << "operator+= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e -=3;
        if(e == ce-3) cout << "operator-= success" << "(" << e << ',' << (ce-3) << ")" << endl;
        else cout << "operator-= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e *=3;
        if(e == ce*3) cout << "operator*= success" << "(" << e << ',' << (ce*3) << ")" << endl;
        else cout << "operator*= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e /=3;
        if(e == ce/3) cout << "operator/= success" << "(" << e << ',' << (ce/3) << ")" << endl;
        else cout << "operator/= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e %=3;
        if(e == ce%3) cout << "operator%= success" << "(" << e << ',' << (ce%3) << ")" << endl;
        else cout << "operator%= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e &=3;
        if(e == (ce&3)) cout << "operator&= success" << "(" << e << ',' << (ce&3) << ")" << endl;
        else cout << "operator&= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e |=3;
        if(e == (ce|3)) cout << "operator|= success" << "(" << e << ',' << (ce|3) << ")" << endl;
        else cout << "operator|= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e ^=3;
        if(e == (ce^3)) cout << "operator^= success" << "(" << e << ',' << (ce^3) << ")" << endl;
        else cout << "operator^= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e <<=3;
        if(e == (ce<<3)) cout << "operator<<= success" << "(" << e << ',' << (ce<<3) << ")" << endl;
        else cout << "operator<<= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e >>=3;
        if(e == (ce>>3)) cout << "operator>>= success" << "(" << e << ',' << (ce>>3) << ")" << endl;
        else cout << "operator>>= failed" << "(" << e << ',' << ce << ")" << endl;

        return 0;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "Unknown error" << '\n';
        return 2;
    }
}