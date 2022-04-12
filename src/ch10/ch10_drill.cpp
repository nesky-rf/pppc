
#include <iostream>
#include <fstream>
#include <string>
#include "../std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Point
{
    int x;
    int y;

    friend istream& operator>>(istream& ist, Point& p)
    {
        char a,b,c;

        if ((ist >> a >> p.x >> b >> p.y >> c) && !(a == '(' && b == ',' && c == ')'))
            throw runtime_error("Invalid format");

        return ist;
    }

    friend ostream& operator<<(ostream& ost, const Point& p)
    {
        return ost << '(' << p.x << ',' << p.y << ')' << endl;
    }

    friend bool operator==(const Point& a, const Point& b)
    {
        return a.x==b.x&&a.y==b.y;
    }
};

//------------------------------------------------------------------------------

int main()
try
{
    vector<Point> original_points;
    Point p;

    cout << "Please enter 7 pair (x,y) points: " << endl;
    while (cin>>p) original_points.push_back(p);

    for(int i=0;i<original_points.size();i++)
        cout << original_points[i];

    ofstream ofs("mydata.txt");
    if(!ofs) error("can't open mydata.txt");

    for(int i=0;i<original_points.size();i++)
        ofs << original_points[i];
    
    vector<Point> processed_points;

    ifstream ifs("mydata.txt");
    if(!ifs) error("cant open mydata.txt");
    while(ifs >> p)
        processed_points.push_back(p);
    cout << "Comparing streams...\n";
    for (int i = 0; i < original_points.size(); i++)
    {
        if(original_points[i]==processed_points[i])
            cout << "Point match" << i << ":" << original_points[i];
        else
            cout << "****Point mismatch" << i << ":" << original_points[i];
        
    }
    

}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
