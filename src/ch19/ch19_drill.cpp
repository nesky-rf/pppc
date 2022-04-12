#include <iostream>
#include <vector>

using namespace std;

void test_type();
void test_vector();
void test_operator();
void test_readval();

template<class T>
struct S {
    S() {}
    S(T v)
    : val(v) {}
    T& get();
    void set(T v);
    T& operator[](int);
    const T& operator[](int) const;
    void read_val(T& v);
private:
    T val;
};

template<class T>
T& S<T>::get() {
    return val;
}

template<class T>
void S<T>::set(T v)
{
    val = v;
}

template<class T>
T& S<T>::operator[](int)
{
    return val;
}

template<class T>
const T& S<T>::operator[](int) const
{
    return val;
}

template<class T>
void read_val(T& v)
{
    cin >> v;
}

template<class T>
istream& operator>>(istream& is,S<T>& v)
{
    T t;
    cin >> t;
    if(!is) return is;
    v.set(t);
    return is;
}

template<class T>
istream& operator>>(istream& is, vector<T>& v)
{
    T t;
    char init;
    char sep;
    vector<T> temp;

    cin >> init;
    if(!is) return is;
    if(init != '{') {
        is.clear(ios_base::failbit);
        return is;
    }    
    while(cin>>t>>sep && sep==',') {
        temp.push_back(t);
    }
    if(sep != '}') {
        is.clear(ios_base::failbit);
        return is;
    }
    
    temp.push_back(t);
    v= temp;
    return is;
}

int main()
{
    try
    {
        // test_type();
        // test_vector();
        // test_operator();
        test_readval();
        return 0;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "Unknown error" << '\n';
        return 2;
    }
    
}

void test_type()
{
    S<char> sc('a');
    cout << "&sc= " << &sc << ", val= " << sc.get()  << endl;

    S<int> si(123);
    cout << "&si= " << &si << ", val= " << si.get() << endl;

    S<double> sd(12.3);
    cout << "&sd= " << &sd << ", val= " << sd.get() << endl;

    S<string> ss("S<string> s");
    cout << "&ss= " << &ss << ", val= " << ss.get() << endl;
}

void test_vector()
{
    S<vector<int>> svi({123,456,789});
    cout << "&svi= " << &svi << ", val= ";
    for(int i=0; i< svi.get().size(); i++) cout << "[" << i << "]= " << svi.get().at(i) << ',';
    cout  << endl;

    vector<int>& sri = svi.get();
    cout << "&sri= " << &sri << ", val= ";
    for(int i=0; i< sri.size(); i++) cout << "[" << i << "]= " << sri.at(i) << ',';
    cout  << endl;

    svi.set({123,456});
    cout << "&svi= " << &svi << ", val= ";
    for(int i=0; i< svi.get().size(); i++) cout << "[" << i << "]= " << svi.get().at(i) << ',';
    cout  << endl;
    cout << "&sri= " << &sri << ", val= ";
    for(int i=0; i< sri.size(); i++) cout << "[" << i << "]= " << sri.at(i) << ',';
    cout  << endl;
}

void test_operator()
{
    S<int> si(123);
    cout << "&si= " << &si << ", val= " << si[0] << endl;

    si[0]= 456;
    cout << "&si= " << &si << ", val= " << si[0] << endl;

    const S<vector<int>> svi({123,456,789});
    cout << "&svi= " << &svi << ", val= ";
    for(int i=0; i< svi[0].size(); i++) cout << "[" << i << "]= " << svi[0].at(i) << ',';
    cout  << endl;
}

void test_readval()
{
    S<char> sc;
    cout << "Type char: ";
    read_val(sc);
    cout << "&sc= " << &sc << ", val= " << sc.get() << endl;

    S<int> si;
    cout << "Type integer: ";
    read_val(si);
    cout << "&si= " << &si << ", val= " << si.get() << endl;

    S<double> sd;
    cout << "Type double: ";
    read_val(sd);
    cout << "&sd= " << &sd << ", val= " << sd.get() << endl;

    S<string> ss;
    cout << "Type string: ";
    read_val(ss);
    cout << "&ss= " << &ss << ", val= " << ss.get() << endl;

    S<vector<int>> svi;
    cout << "Type vector<int>: ";
    read_val(svi);
    cout << "&svi= " << &svi << ", val= ";
    for(int i=0; i< svi.get().size(); i++) cout << "[" << i << "]= " << svi.get().at(i) << ',';
    cout  << endl;
}
