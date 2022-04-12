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

struct Transaction
{
    Book book;
    Patron patron;
    string date;
    Transaction(Book& b, Patron& p, string d);
};

Transaction::Transaction(Book& b, Patron& p, string d):
    book(b), patron(p), date(d)
{
    if(date.size()==0)
        error("transaction: missing date");
}

class Library
{
private:
    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> trans;  
    
public:
    Library(/* args */);
    ~Library();
    //
    void add_book(string i, string t, string a, string d, Genre g);
    void add_book(Book& b);
    void add_patron(string n, string c, double f);
    void add_patron(Patron& p);
    void add_trans(Book& b, Patron& p, string d);
    void proceed_checkout(Book& b, Patron& p, string d);
};

Library::Library(/* args */)
{
}

Library::~Library()
{
}

void Library::add_book(string i, string t, string a, string d, Genre g)
{
    Book bk(i,t,a,d,Genre(g));
    books.push_back(bk);
}

void Library::add_book(Book& b)
{
    books.push_back(b);
}

void Library::add_patron(string n, string c, double f)
{
    Patron p(n,c,f);
    patrons.push_back(p);
}

void Library::add_patron(Patron& p)
{
    patrons.push_back(p);
}

void Library::add_trans(Book& b, Patron& p, string d)
{
    Transaction t(b,p,d);
    trans.push_back(t);
}

void Library::proceed_checkout(Book& b, Patron& p, string d)
{
    int bok=-1;
    for (int i = 0; i < books.size(); i++)
    {
        if(books[i].get_isbn() == b.get_isbn())
            bok=i;
    }
    
    if(bok < 0) error("book not found in library");

    if(books[bok].checkin() == true)
        error("book already checked out");

    int pat=-1;
    for (int i = 0; i < books.size(); i++)
    {
        if(patrons[i].get_name() == p.get_name())
            pat=i;
    }

    if(pat < 0) error("patron not found in library");

    if(patrons[pat].get_fee() != 0)
        error("patron owes money");
    
    add_trans(b,p,d);
}

int main()
{
    Library lib;
    Book txt1("1-2-3-H","Jim","Morrison","2005-6-7",Genre::biography);
    Patron pat1("john","VISA",0);

    lib.add_book(txt1);
    lib.add_book("4-5-6-L","Jimi","Hendrix","2025-6-7",Genre::fiction);
    lib.add_patron(pat1);
    lib.add_patron("jimi","MASTERCARD",0);

    lib.proceed_checkout(txt1,pat1,"2005-9-7");
    cout << "transaction succesful\n";

    return 0;
}