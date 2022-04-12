#include "../std_lib_facilities.h"
// #include <chrono>

enum Genre {fiction=1,nonfiction,peridical,biography,children};

class Book
{
private:
    string isbn;
    string title;
    string author;
    string date;
    Genre genre;
    bool chk_out;
    string date_chk_out;
public:
    Book(string i, string t, string a, string d, Genre g);
    ~Book();
    //
    string get_isbn() const { return isbn; }
    string get_title() const { return title; }
    string get_author() const { return author; }
    string get_date() const { return date; }
    //
    bool checkin();
    bool checkout(string s);
};

Book::Book(string i, string t, string a, string d, Genre g): 
    isbn(i), title(t), author(a), date(d), genre(Genre(g))
{
    if (isbn.size()!=7 || isbn.at(1)!='-' || isbn.at(3)!='-' || isbn.at(5)!='-')
        error("constructor: wrong isbn");
    else if(title.size()==0)
        error("constructor: wrong title");
    else if(author.size()==0)
        error("constructor: wrong author");
    else if(date.size()==0)
        error("constructor: wrong date");
    else if(genre == 0)
        error("constructor: wrong genre");
    chk_out = false;
    date_chk_out = "";
}

Book::~Book()
{
}

bool Book::checkin()
{
    if(chk_out)
    {
        chk_out = false;
        date_chk_out = "";
        return 1;
    }
    return 0;
}

bool Book::checkout(string s)
{
    if(!chk_out)
    {
        chk_out = true;
        date_chk_out = s;
        return 1;
    }
    return 0;
}

bool operator==(Book& a, Book& b)
{
    return a.get_isbn()==b.get_isbn();
}

bool operator!=(Book& a, Book& b)
{
    return a.get_isbn()!=b.get_isbn();
}

ostream& operator<<(ostream& os, Book& b)
{
    return os << "Author: " << b.get_author() << '\n' << "ISBN: " << b.get_isbn() << '\n';
}

class Patron
{
private:
    string name;
    string card;
    double fee;
public:
    Patron(string n, string c, double f);
    ~Patron();
    //
    string get_name() const { return name; }
    string get_card() const { return card; }
    double get_fee() const { return fee; }
    void set_fee( double d) { fee = d;}
};

Patron::Patron(string n, string c, double f) :
    name(n), card(c), fee(f)
{
    if(name.size()==0)
        error("constructor: wrong name");
    else if(card.size()==0)
        error("constructor: wrong card");
}

Patron::~Patron()
{
}

bool check_fee(Patron& p)
{
    double z=0;

    if(p.get_fee()==z)
        return 0;
    return 1;
}


int main()
{
    Book bk1("1-2-3-H","I","am","2005-6-7",Genre::biography);

    if(bk1.checkin())
        cout << "book in \n";
    else
    {
        bk1.checkout("2005-8-9");
        cout << "book out \n";
    }

    Book bk2("1-2-3-H","You","are","2005-6-7",Genre::fiction);
    
    if(bk1 == bk2)
        cout << "same book \n";
    else if( bk1 != bk2)
        cout << "different book\n";
    else
        cout << "what!\n";
    
    cout << bk1 << '\n';
    cout << bk2;

    Patron nm1("john","VISA",12.3);
    Patron nm2("jimi","MASTERCARD",0);

    if(check_fee(nm1))
        cout << nm1.get_name() << ": owes " << nm1.get_fee() << '\n';
    else
        cout << nm1.get_name() << ": does not owe money\n";
    
    if(check_fee(nm2))
        cout << nm2.get_name() << ": owes " << nm2.get_fee() << '\n';
    else
        cout << nm2.get_name() << ": does not owe money\n";


    return 0;
}