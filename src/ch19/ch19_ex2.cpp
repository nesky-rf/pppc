#include "../std_lib_facilities.h"

using namespace std;

template<class T, class U> 
vector<T> add_vector(vector<T>& t, vector<U>& u)
{
    vector<T> temp;
    cout << "types: " << "T= " << typeid(T).name() << ", U= " << typeid(U).name() << endl;
    if(!is_same<T,U>::value) {
        cout << __PRETTY_FUNCTION__ << "-> ";
        error("Bad argument types");
    }
    for(int i=0; i< t.size(); i++) {
        if(i == u.size()) break;
        temp.push_back(t[i] + u[i]);
    }
    return temp;
} 

int main()
{
    try
    {
        vector<string> v1({"A","B","C"});
        vector<string> v2({"+0x20= a","+0x20= b","+0x20= c", "+0x20= d"});
        vector<string> v = add_vector(v1,v2);

        cout << "&v: " << &v << ", size: " << v.size() << ", " << "elem: ";
        for(int i=0; i< v.size(); i++) cout << "[" << i << "]= " << v[i] << ", ";
        cout << endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    
}