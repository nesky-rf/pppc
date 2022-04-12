#include "../std_lib_facilities.h"
#include <map>

int main()
{
    map<string,int,greater<string>> words;

    string s;
    while (cin >> s) ++words[s];

    typedef map<string,int>::const_iterator iter;
    for(iter p=words.begin(); p != words.end(); ++p)
        cout << '(' << p->first << ',' << p->second << ')' << endl;

    return 0;
}