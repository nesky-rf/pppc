#include "../std_lib_facilities.h"

int main()
{
    int birth_year=1977;
    int age= 44;

    cout << showbase << "Decimal: \t"<< birth_year << ", Hex: \t"<< hex << birth_year << ", Octal: \t"<< oct << birth_year << endl;
    cout << showbase << "\t \t" << dec << age << "\t \t" << hex << age << "\t \t" << oct << age << endl;

    cout << dec << noshowbase;

    double rep= 1234567.89;

    cout << rep << endl;
    cout << scientific << rep << endl;
    cout << fixed << rep << endl;

    return 0;
}