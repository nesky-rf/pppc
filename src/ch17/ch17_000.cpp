#include <iostream>
#include <vector>

using namespace std;

double* calc(int,int);

int main()
{
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof('a') << '\n';
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof(2+2) << '\n';
    int* p = 0;
    cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n' ;
    bool b= true;
    cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n' ;
    bool* pb = 0;
    cout << "the size of bool* is " << sizeof(bool*) << ' ' << sizeof(pb) << '\n' ;
    vector<int> vec(1);
    cout << "the size of vector is " << sizeof(vec) << ' ' << sizeof(vec[0]) << '\n' ;

    double* pd= new double;
    double* qd= new double[1000];

    qd[700] = 7.7;
    qd=pd;
    double a = qd[700];
    cout << "*pd: " << *pd << ',' << "qd[700]: " << qd[700] << ',' << "a: " << a << endl;

    double* r= calc(100,100);
    cout << "r: " << *r << endl;
    delete[] r;

    return 0;
}

double* calc(int res_size, int max)
{
    double* p = new double[max];
    double* res = new double[res_size];
    //
    *res=4.6;
    // use p to calcu late results to be put in res
    delete[] p;
    return res;
}