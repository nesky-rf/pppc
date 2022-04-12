#include "../std_lib_facilities.h"
#include <fstream>
#include <locale>

int main()
{
    cout << "Enter filename to read: ";
    string filein;

    cin >> filein;
    ifstream ifs(filein);
    if(!ifs) error("no file: ",filein);

    char ch;

    vector<char> is_space;
    vector<char> is_alpha;
    vector<char> is_digit;
    vector<char> is_xdigit;
    vector<char> is_upper;
    vector<char> is_lower;
    vector<char> is_alnum;
    vector<char> is_cntrl;
    vector<char> is_punct;
    vector<char> is_print;
    vector<char> is_graph;

    while(ifs.get(ch))
    {
        if(isspace(ch)) is_space.push_back(ch);
        if(isalpha(ch)) is_alpha.push_back(ch);
        if(isdigit(ch)) is_digit.push_back(ch);
        if(isxdigit(ch)) is_xdigit.push_back(ch);
        if(isupper(ch)) is_upper.push_back(ch);
        if(islower(ch)) is_lower.push_back(ch);
        if(isalnum(ch)) is_alnum.push_back(ch);
        if(iscntrl(ch)) is_cntrl.push_back(ch);
        if(ispunct(ch)) is_punct.push_back(ch);
        if(isprint(ch)) is_print.push_back(ch);
        if(isgraph(ch)) is_graph.push_back(ch);
    }
    
    cout << "Report:" << endl;
    cout << "-------" << endl;
    cout << "isspace: " << is_space.size() << endl;
    cout << "isalpha: " << is_alpha.size() << endl;
    cout << "isdigit: " << is_digit.size() << endl;
    cout << "isxdigit: " << is_xdigit.size() << endl;
    cout << "isupper: " << is_upper.size() << endl;
    cout << "islower: " << is_lower.size() << endl;
    cout << "isalnum: " << is_alnum.size() << endl;
    cout << "iscntrl: " << is_cntrl.size() << endl;
    cout << "ispunct: " << is_punct.size() << endl;
    cout << "isprint: " << is_print.size() << endl;
    cout << "isgraph: " << is_graph.size() << endl;

    return 0;
}