#include <iostream>

using namespace std;

int ga[10]={1,2,4,8,16,32,64,128,256,512};

void f(int a[], int n)
{
    int la[10];
    for(int i=0;i<10;i++)   // copy values from ga to la
        la[i] = ga[i];
    for(int i=0;i<10;i++)   // print la
        cout << "[" << i << "]=" << la[i] << ", ";
    cout << endl;

    int* pa = new int[n];
    for(int i=0; i<n; i++) // copy argument array to int*
        pa[i] = a[i];
    for(int i=0; i<n; i++) // print int*
        cout << "[" << i << "]=" << pa[i] << ", ";
    cout << endl;
    delete[] pa;
}

int main()
{
    try
    {
        cout << "global: " << endl;
        f(ga,10);
        int aa[10]={1,1,2,6,24,120,720,5400,49600,496000};
        cout << "local: " << endl;
        f(aa,10);
        return 0;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    
}