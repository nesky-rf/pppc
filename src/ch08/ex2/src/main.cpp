#include "../include/std_lib_facilities.h"

void print(string, const vector<int>&);
int fibonacci(int, int, vector<int>&, int);
int rand_in_range(int, int);

int main() {
    vector<int> v;

    // ex01
    // print("vector: ",v);
    // cout << '\n';

    // ex02
    int f=50;
    int n = fibonacci(1,2,v,f);
    cout << '(' << n << ')';
    if( f!=n) cout << '*';
    cout << '\n';

    print("fibonacci: ",v);
    cout << '\n';

    srand(time(NULL));
    int m = rand_in_range(0,10);
    cout << "random: " << m;
    cout << '\n';

    return 0;
}

void print(string label, const vector<int>& v)
{
    cout << label;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << ' ';
    }
    
}

int fibonacci(int x, int y, vector<int>& v, int n)
{
    v.push_back(x);
    v.push_back(y);

    unsigned int j=0;
    unsigned int k=0;
    unsigned long int l=0;

    for(int i=2; i<n; i++)
    {
        j = i-2;
        k = i-1;
        l = v.at(j)+v.at(k);
        if( l > numeric_limits<int>::max())
            break;
        v.push_back(int(l));
    }
    return v.size();
}

int rand_in_range(int a, int b)
{
    if(b < 1)
        error("rand_in_range: delimiters [a,b)");
    return rand()%b+a;
}