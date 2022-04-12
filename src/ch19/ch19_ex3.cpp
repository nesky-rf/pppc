#include "../std_lib_facilities.h"

using namespace std;

template<class T, class U> class Pair {
public:
    Pair() {}
    Pair(T t, U u)
    {
        key.push_back(t);
        value.push_back(u);
    }
    void read_pair(T& k, U& v, int n) {
        k = key.at(n);
        v = value.at(n);
    }
    void push_back(const T& t, const U&u) {
        key.push_back(t);
        value.push_back(u);
    }
    int size() {
        return key.size();
    }

private:
    vector<T> key;
    vector<U> value;
};

template<class T, class U>
ostream& operator<<(ostream& os, Pair<T,U>& p)
{
    T k;
    U v;
    for(int i=0; i< p.size(); i++) {
        p.read_pair(k,v,i);
        os << "\nPair (" << i << ") " << "key: " << k << ", value: " << v;
    }
    return os;
}

int main()
{
    try
    {
        Pair<double,char> p;
        p.push_back(1.4,'r');
        p.push_back(1.8,'w');
        p.push_back(31.2,'\u002B');
        cout << "&p: " << &p << p << endl;

        return 0;
    }
    catch(const std::exception& e)
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