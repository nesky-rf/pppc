#include "../std_lib_facilities.h"

namespace drill941
{
    struct Date{
        int y;
        int m;
        int d;
    };

    void init_day(Date& dd, int y, int m, int d)
    {
        if(y<0 || m<1 || m>12 || d<1 || d>31) error("init_day: invalid date");
        dd.d = d;
        dd.m = m;
        dd.y = y;
    }

    void add_day(Date& dd, int n)
    {
        dd.d += n;
    }
}

namespace drill942
{
    struct Date
    {
        int y;
        int m;
        int d;

        Date();
        Date(int y, int m ,int d);

        void add_day(int n);
    };
    
    Date::Date(){
        y=2001;
        m=1;
        d=1;
    }
    
    Date::Date(int y, int m, int d) :
        y(y), m(m), d(d) {
            if(y<0 || m<1 || m>12 || d<1 || d>31) error("constructor: invalid date");
        }

    ostream& operator<<(ostream& os, Date& dd) {
        return os << '(' << dd.y << ',' << dd.m << ',' << dd.d << ')';
    }

    void init_day(Date& dd, int y, int m, int d) {
        if(y<0 || m<1 || m>12 || d<1 || d>31) error("init_day: invalid date");
        dd.d = d;
        dd.m = m;
        dd.y = y;
    }

    void Date::add_day(int n)
    {
        d += n;
        if( d> 31) error("add_day: invalid day");
    }

}

namespace drill943
{
    class Date {
        int y, m ,d;
    public:
        Date(int y, int m, int d);
        void add_day(int n);
        int month() { return m;}
        int day() { return d; }
        int year() { return y; }
    };

    Date::Date(int y, int m, int d) :
        y(y), m(m), d(d) {
            if(y<0 || m < 1 || m>12 || d < 1 || d>31) error("constructor: invalid date");
        }
}

namespace drill971
{
    class Year {
        static const int min=1800;
        static const int max=2200;
    public:
        class Invalid {};
        Year(int y): y(y) { if(y<min || y>max) throw Invalid(); }
        int year() { return y; }
    private:
        int y;
    };

    class Date {
        Year y;
        int m;
        int d;
    public:
        enum Month{jan=1,feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
        Date(Year y, Month m, int d);
        int year() { return y.year();}
        Month month() { return Month(m); }
        int day() { return d; }
    };

    Date::Date(Year y, Month m, int d) :
        y(Year(y)), m(Month(m)), d(d)
    {
        if(m < 1 || m>12 || d < 1 || d>31) error("constructor: invalid date");
    }

    ostream& operator<<(ostream& os, Date& dd)
    {
        return os << '(' << dd.year() << ',' << dd.month() << ',' << dd.day() << ')';
    }
}

namespace drill973
{
    struct Date
    {
    public:
        enum Month{jan=1,feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
        int year() { return y; }
        Month month() { return Month(m); }
        int day() { return d; }
        Date();
        Date(int y, Month m, int d);
    private:
        int y, d;
        Month m;
    };

    Date& default_date()
    {
        static Date dd(2001,Date::feb,1);
        return dd;
    }

    Date::Date() :
        y(default_date().y), m(default_date().m), d(default_date().d)
    {
        if(m < 1 || m>12 || d < 1 || d>31) error("constructor: invalid date");
    }

    Date::Date(int y, Month m, int d):
        y(y), m(Month(m)), d(d)
    {
        if(m < 1 || m>12 || d < 1 || d>31) error("constructor: invalid date");
    }

    ostream& operator<<(ostream& os, Date& dd)
    {
        return os << '(' << dd.year() << ',' << dd.month() << ',' << dd.day() << ')';
    }
    
}

int main()
{
    {
        using namespace drill941;
        cout << "namespace drill941:\n";
        Date today;
        init_day(today, 2000, 1, 1);
        cout << today.y << ',' << today.m << ',' << today.d << '\n';
        add_day(today, 1);
        cout << today.y << ',' << today.m << ',' << today.d << '\n';
    }

    {
        using namespace drill942;
        cout << "namespace drill942:\n";
        Date today;
        cout << today << '\n';
        init_day(today, 2008,3,30);
        cout << today << '\n';

        Date tomorrow= today;
        today.add_day(1);
        cout << tomorrow << '\n';

    }

    {
        using namespace drill943;
        cout << "namespace drill943:\n";
        Date birthday(2002, 4, 31);
        cout << birthday.month() << '\n';
    }   
    
    {
        using namespace drill971;
        cout << "namespace drill971:\n";
        Date today(Year(2002), Date::apr, 31);
        cout << today << '\n';
    }

    {
        using namespace drill973;
        cout << "namespace drill973:\n";
        Date today(2021, Date::nov, 5);
        cout << today << '\n';
    }

    return 0;
}