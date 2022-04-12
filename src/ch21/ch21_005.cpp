#include "../std_lib_facilities.h"
#include <fstream>
#include <iterator>
#include <string>
#include <set>

int main()
{
    string from, to;

    cin >> from >> to;
    ifstream is(from.c_str());
    ofstream os(to.c_str());

    istream_iterator<string> ii(is);
    istream_iterator<string> eos;
    ostream_iterator<string> oo(os,"\n");
// outputs
    // using vector container
    // vector<string> b(ii,eos);
    // sort(b.begin(),b.end());
    // unique_copy(b.begin(),b.end(),oo);
    //
    // using set container
    set<string> b(ii,eos);
    copy(b.begin(),b.end(),oo);
    return 0;
}