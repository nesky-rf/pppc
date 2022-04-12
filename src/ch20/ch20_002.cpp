#include "../std_lib_facilities.h"

int main()
{
    list<int> mli = {1,2,3,4,5};

    for(list<int>::iterator it=mli.begin(); it!=mli.end(); it++)
        cout << *it << '#';
    cout << endl;
    return 0;
}