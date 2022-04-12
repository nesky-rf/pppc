#include "../std_lib_facilities.h"


class technique {
public:
    technique(int n, int r, char c): total(n), group(r), type(c) {};
    int factorial(int num);
    int permutation();
    int combination();
    int solve(); 
private:
    int total;
    int group;
    char type;
};

int technique::solve()
{
    if(type == 'C')
        return combination();
    else if(type == 'P')
        return permutation();
    else
        error("Operation not permitted.\n");
}

int technique::factorial(int num)
{
    if(num <= 0) num = 1;

    for(int i= num; i>0; --i)
        num *= i;
    return num;
}

int technique::permutation()
{
    return factorial(total)/factorial(total-group);
}

int technique::combination()
{
    return permutation()/factorial(group);
}

int main() 
{
    try
    {
        int total, selected;
        cout << "\n";
        cout << "Enter total number of objects (n): ";
        cin >> total;
        cout << "Enter number of objects selected (r): ";
        cin >> selected;
        char group;
        cout << "Enter grouping as Permutation (P) or Combination (C): ";
        cin >> group;

        technique T(total,selected, group);

        cout << "Solving for " << group << "(" << total << "," << selected << ") = ";
        cout << T.solve() << '\n';
        return 0;
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
    catch(...)
    {
        cerr << "Unknown error" << '\n';
    }
    
}
