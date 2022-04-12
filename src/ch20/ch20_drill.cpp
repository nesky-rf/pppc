#include "../std_lib_facilities.h"
#include <array>



template<class Iter1, class Iter2> 
Iter1 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)         // copies [f1,e1) to [f2, f2+(e1-f1))
{
    if(f1==e1) return f1;
    
    while(f1!=e1) {
        *f2=*f1;
        f1++;
        f2++;
    }
    return f1;
}

int main()
{
    array<int,10> a {0,1,2,3,4,5,6,7,8,9};
    vector<int> v {0,1,2,3,4,5,6,7,8,9};
    list<int> l {0,1,2,3,4,5,6,7,8,9};

    array<int,10> a1 = a;
    vector<int> v1 = v;
    list<int> l1 = l;

    for(array<int,10>::iterator p= a1.begin(); p != a1.end(); ++p) *p += 2;
    for(vector<int>::iterator p= v1.begin(); p != v1.end(); ++p) *p += 3;
    for(list<int>::iterator p= l1.begin(); p != l1.end(); ++p) *p += 5;

    cout << "original results:" << endl;
    cout << "array: "; for(int i=0; i < a1.size(); ++i) cout << a1[i] << ','; cout << endl;
    cout << "vector: "; for(int i=0; i < v1.size(); ++i) cout << v1[i] << ','; cout << endl;
    cout << "list: "; for(list<int>::iterator p= l1.begin(); p != l1.end(); ++p) cout << *p << ','; cout << endl;

    cout << "copy results:" << endl;
    my_copy(a1.begin(),a1.end(),v1.begin());
    my_copy(l1.begin(),l1.end(),a1.begin());
    cout << "array: "; for(int i=0; i < a1.size(); ++i) cout << a1[i] << ','; cout << endl;
    cout << "vector: "; for(int i=0; i < v1.size(); ++i) cout << v1[i] << ','; cout << endl;
    cout << "list: "; for(list<int>::iterator p= l1.begin(); p != l1.end(); ++p) cout << *p << ','; cout << endl;

    cout << "find results:" << endl;
    vector<int>::iterator p=find(v1.begin(),v1.end(),2);
    if(p!=v1.end())
        cout << "match: " << *p << ", at pos: " << p-v1.begin() << endl;
    else
        cout << "match not found" << endl;
    return 0;
}