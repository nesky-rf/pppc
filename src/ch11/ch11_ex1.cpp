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

    while(ifs.get(ch))
        if(!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'))
            cout << char(tolower(ch));

    cout << endl;
    return 0;
}