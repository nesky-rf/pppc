#include "../std_lib_facilities.h"
#include <iterator>

// function under test
bool b_search(const vector<int>::iterator iti, const vector<int>::iterator ite , const int& k )
{
    int sz = ite - iti;
    if(sz==0) return false;
    //
    if(k < *iti) return false;
    if(k > *(ite-1)) return false;
    int mid = sz/2;
    //
    if(k==*(iti+mid)) return true;
    else if(k<*(iti+mid)) return b_search(iti,ite-mid,k);
    else if(k>*(iti+mid)) return b_search(iti+mid,ite,k);
    else return false;
    //
}
// end function under test

int main()
{
    vector<int> vi {1,2,3,4,5,7,8,9,10};
    // simple testing
    if(b_search(vi.begin(),vi.end(),1) == false) cout << "1 failed" << endl;
    if(b_search(vi.begin(),vi.end(),3) == false) cout << "2 failed" << endl;
    if(b_search(vi.begin(),vi.end(),7) == false) cout << "3 failed" << endl;
    if(b_search(vi.begin(),vi.end(),9) == false) cout << "4 failed" << endl;
    if(b_search(vi.begin(),vi.end(),10) == false) cout << "5 failed" << endl;
    if(b_search(vi.begin(),vi.end(),6) == true) cout << "6 failed" << endl;
    if(b_search(vi.begin(),vi.end(),-1) == true) cout << "7 failed" << endl;
    if(b_search(vi.begin(),vi.end(),0) == true) cout << "8 failed" << endl;
    
    return 0;
}
