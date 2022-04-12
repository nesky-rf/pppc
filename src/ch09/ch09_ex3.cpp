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
    //
    int get_size() { return Name.size(); }
    string get_name(int n) { return Name[n]; }
    double get_age(int n) { return Age[n]; }
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

ostream& operator<<(ostream& os, Name_pairs& n)
{
    for(int i=0; i < n.get_size(); i++)
    {
        os << '(' << n.get_name(i) << ',' << n.get_age(i) << ')' << '\n' ;
    }
    return os;
}

int main()
{
    Name_pairs book;

    book.read_names();
    book.read_ages();
    cout << book << '\n';

    return 0;
}