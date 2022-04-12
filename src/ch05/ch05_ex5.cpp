#include "../std_lib_facilities.h"

double ctok(double c)
// converts Celsius to Kelvin
{
    if(c < -273.15)
        error("Temperature must be above -273.15C.");
    double k = c + 273.15;
    return k;
}

double ktoc(double k)
// converts Celsius to Kelvin
{
    if(k < 0)
        error("Temperature must be above 0K.");
    double c = k - 273.15;
    return c;
}

int main()
{
    try
    {
        cout << "Enter temperature to convert and unit (C/K):\n";
        double temp = 0; // declare input variable
        double tempc = 0;
        char unit=0;

        cin >> temp >> unit; // retrieve temperature to input variable
        if(unit == 'C')
            tempc = ctok(temp); // convert temperature
        else if(unit =='K')
            tempc = ktoc(temp); // convert temperature
        else
            error("Unkown unit.\n");

        cout << "Temperature conversion: " << temp << unit << " ~ " << tempc << ((unit=='C')?'K':'C') << endl ; // print out temperature
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown error.\n";
    }
}