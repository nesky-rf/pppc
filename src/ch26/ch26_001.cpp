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

struct Test{
    string label;
    int val;
    vector<int> seq;
    bool res;
};

istream& operator>>(istream& is, Test& t)
{
    // input ex: { 1.3 1 { 2  3  4  6  7  8 } 1 }
    string sep1,sep2;

    if(is >> sep1 >> t.label >> t.val >> sep2 && (sep1 != "{" || sep2 != "{"))
    {
        cerr << "Input test fail format #1" << endl;
        return is;
    }

    t.seq.clear();

    copy(istream_iterator<int>(is),istream_iterator<int>(),back_inserter(t.seq));

    is.clear();
    string sep3,sep4;
    if(is >> sep3 >> t.res >> sep4 && (sep3 != "}" || sep4 != "}"))
    {
        cerr << "Input test fail format #2" << endl;
        return is;
    }

    return is;
}

ostream& operator<<(ostream& os, const Test& t)
{
    os << "{ " << t.label << ' ' << t.val << " { ";
    copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<int>(os," "));
    return os << "} " << t.res << " }";
}

int test_all()
{
    int error_count = 0;
    Test t;
    while (cin >> t)
    {
        cout << t << endl;
        bool r = b_search(t.seq.begin(),t.seq.end(),t.val);
        if(r != t.res)
        {
            cout << "failure: test " << t.label
            << " binary_search : "
            << t.seq.size() << " elements, val==" << t.val
            << " -> " << t.res << '\n';
            ++error_count;
        }
    }
    return error_count;
}

int main()
{
    // torough test -> input file
    int errors = test_all();
    cout << "number of errors: " << errors << endl;
    
    return 0;
}
