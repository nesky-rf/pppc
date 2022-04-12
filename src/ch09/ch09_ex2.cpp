#include "../std_lib_facilities.h"

class Name_pairs
{
private:
    vector<string> Name;
    vector<double> Age;
public:
    //
    void read_names();
    void read_ages();
    void print();
};

void Name_pairs::read_names()
{
    cout << "Enter names (type 'q' to end list): ";
    string s;
    cin >> s;
    while(s != "q")
    {
        Name.push_back(s);
        cin >> s;
    }
}

void Name_pairs::read_ages()
{
    for (int i = 0; i < Name.size(); i++)
    {
        cout << "Enter age for " << Name[i] << ": ";
        double n;
        cin >> n;
        Age.push_back(n);
    }
    
}

void Name_pairs::print()
{
    for(int i=0; i < Name.size(); i++)
    {
        cout << '(' << Name[i] << ',' << Age[i] << ')' << '\n' ;
    }
}

int main()
{
    Name_pairs book;

    book.read_names();
    book.read_ages();
    book.print();

    return 0;
}