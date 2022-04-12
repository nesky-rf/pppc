#include "../std_lib_facilities.h"

using namespace std;

template<class T>
class Number {
public:
    Number()
    : val(0) {}
    Number(T i)
    : val(i) {}
    T& operator=(const T& v) {
        val = v;
        return val;
    }
    T read_value() {
        return val;
    }
    void set_value(const T& i) {
        val = i;
    }
private:
    T val;
};

template<class T>
bool operator==(Number<T>& i, const T& j) {
    return (i.read_value() == j)? true: false;
}

template<class T>
bool operator!=(Number<T>& i, const T& j) {
    return (i.read_value() == j)? false: true;
}

template<class T>
ostream& operator<<(ostream& os, Number<T>& i)
{
    return  os << i.read_value();
}

template<class T>
T operator++(Number<T>& i, int) {
    T val = i.read_value();
    i.set_value(val+1);
    return val;
}

template<class T>
T operator++(Number<T>& i) {
    T val = i.read_value();
    val += 1;
    i.set_value(val);
    return val;
}

template<class T>
T operator+=(Number<T>& i, T j) {
    T val = i.read_value();
    val += j;
    i.set_value(val);
    return val;
}

template<class T>
T operator-=(Number<T>& i, T j) {
    T val = i.read_value();
    val -= j;
    i.set_value(val);
    return val;
}

template<class T>
T operator*=(Number<T>& i, T j) {
    T val = i.read_value();
    val *= j;
    i.set_value(val);
    return val;
}

template<class T>
T operator/=(Number<T>& i, T j) {
    T val = i.read_value();
    val /= j;
    i.set_value(val);
    return val;
}

template<class T>
T operator%=(Number<T>& i, T j) {
    if(is_same<T,double>::value) return 0;
    T val = i.read_value();
    val %= j;
    i.set_value(val);
    return val;
}

template<class T>
T operator&=(Number<T>& i, T j) {
    if(is_same<T,double>::value) return 0;
    T val = i.read_value();
    val &= j;
    i.set_value(val);
    return val;
}

template<class T>
T operator|=(Number<T>& i, T j) {
    if(is_same<T,double>::value) return 0;
    T val = i.read_value();
    val |= j;
    i.set_value(val);
    return val;
}

template<class T>
T operator^=(Number<T>& i, T j) {
    if(is_same<T,double>::value) return 0;
    T val = i.read_value();
    val ^= j;
    i.set_value(val);
    return val;
}

template<class T>
T operator<<=(Number<T>& i, T j) {
    if(is_same<T,double>::value) return 0;
    T val = i.read_value();
    val <<= j;
    i.set_value(val);
    return val;
}

template<class T>
T operator>>=(Number<T>& i, T j) {
    if(is_same<T,double>::value) return 0;
    T val = i.read_value();
    val >>= j;
    i.set_value(val);
    return val;
}

int main()
{
    try
    {
        Number<int> e;
        const int ce=8;
        int k=3.0;
        cout << "&e" << &e << ", e= " << e << ", ce= " << ce << endl;
        cout << "type: " << typeid(e).name() << endl;

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
        e = ce; e +=k;
        if(e == ce+k) cout << "operator+= success" << "(" << e << ',' << (ce+k) << ")" << endl;
        else cout << "operator+= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e -=k;
        if(e == ce-k) cout << "operator-= success" << "(" << e << ',' << (ce-k) << ")" << endl;
        else cout << "operator-= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e *=k;
        if(e == ce*k) cout << "operator*= success" << "(" << e << ',' << (ce*k) << ")" << endl;
        else cout << "operator*= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e /=k;
        if(e == ce/k) cout << "operator/= success" << "(" << e << ',' << (ce/k) << ")" << endl;
        else cout << "operator/= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e %=k;
        if(e == ce%k) cout << "operator%= success" << "(" << e << ',' << (ce%k) << ")" << endl;
        else cout << "operator%= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e &=k;
        if(e == (ce&k)) cout << "operator&= success" << "(" << e << ',' << (ce&k) << ")" << endl;
        else cout << "operator&= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e |=k;
        if(e == (ce|k)) cout << "operator|= success" << "(" << e << ',' << (ce|k) << ")" << endl;
        else cout << "operator|= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e ^=k;
        if(e == (ce^k)) cout << "operator^= success" << "(" << e << ',' << (ce^k) << ")" << endl;
        else cout << "operator^= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e <<=k;
        if(e == (ce<<k)) cout << "operator<<= success" << "(" << e << ',' << (ce<<k) << ")" << endl;
        else cout << "operator<<= failed" << "(" << e << ',' << ce << ")" << endl;
        e = ce; e >>=k;
        if(e == (ce>>k)) cout << "operator>>= success" << "(" << e << ',' << (ce>>k) << ")" << endl;
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