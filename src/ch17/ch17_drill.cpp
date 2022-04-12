#include <iostream>
#include <vector>

using namespace std;

void print_array(ostream& os, int* a, int n=10)
{
    for (int i = 0; i < n; i++)
        os << a[i] << ',';
    os << '\n';
}

void print_vector(ostream& os, vector<int> v)
{
    for(int i=0; i< v.size(); i++)
        os << v[i] << ',';
    os << '\n';
}

int main()
{
    {
        cout << "int*[]= ";
        int pi_size= 10;
        int* pi = new int[pi_size];         // array 10 ints in the free store
        for (int i = 0; i < pi_size; i++)   // print array
            cout << pi[i] << ',';
        cout << '\n';
        delete[] pi;                        // deallocate array
    }
    {
        cout << "int*[]= ";
        int pi_size= 11;
        int* pi = new int[pi_size];        // array 10 ints in free store
        for(int i=0; i< pi_size; i++)       // store data
            pi[i] = 100 + i;
        print_array(cout,pi);            // print array to cout
        delete[] pi;
    }
    {
        cout << "int*[]= ";
        int pi_size= 11;
        int* pi = new int[pi_size];        // array 10 ints in free store
        for(int i=0; i< pi_size; i++)       // store data
            pi[i] = 100 + i;
        print_array(cout,pi,pi_size);    // print array to cout
        delete[] pi;
    }
    {
        cout << "int*[]= ";
        int pi_size= 20;
        int* pi = new int[pi_size];        // array 10 ints in free store
        for(int i=0; i< pi_size; i++)       // store data
            pi[i] = 100 + i;
        print_array(cout,pi,pi_size);    // print array to cout
        delete[] pi;
    }
    {
        cout << "vector= ";
        int vec_size= 20;
        vector<int> vec(vec_size);           // vector 20 ints
        for(int i=0; i< vec.size(); i++)     // store data
            vec[i] = 100 + i;
        print_vector(cout,vec);              // print array to cout
    }    
    {
        int* p1=new int(7);
        cout << "&p1= " << p1 << ", p1= " << *p1 << endl;

        cout << "ptr= ";
        int p2_size= 7;
        int* p2=new int[p2_size];
        for(int i=0;i<p2_size;i++)
            p2[i] = (i==0) ? 1 : 2*p2[i-1]; 
        print_array(cout,p2,p2_size);

        int* p3= p2;
        p1= p2;
        cout << "p1= " << p1 << ", *p1= ";
        print_array(cout,p1,p2_size);
        cout << "p2= " << p2 << ", *p2= ";
        print_array(cout,p2,p2_size);
        delete[] p1;
    }
    {
        int p1_size= 10;
        int* p1=new int[p1_size];
        for(int i=0;i<p1_size;i++)
            p1[i] = (i>0) ? 2*p1[i-1] : 1;
        cout << "p1= " << p1 << ", *p1= "; 
        print_array(cout,p1,p1_size);

        int p2_size= 10;
        int* p2=new int[p2_size];
        p2 = p1;
        cout << "p2= " << p2 << ", *p2= ";
        print_array(cout,p2,p2_size);
        delete[] p1;
    }
    {
        
    }
    return 0;
}