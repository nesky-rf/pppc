#include "../std_lib_facilities.h"

double a, b, c;

vector<double> solve_equation(double a, double b, double c)
{
    double term_nonzero = b*b - 4*a*c;
    if(term_nonzero < 0)
        error("Complex solutions not allowed.");
    
    vector<double> sols(2);
    sols[0] = (-b + sqrt(term_nonzero)) / (2*a);
    sols[1] = (-b - sqrt(term_nonzero)) / (2*a);

    return sols;
}

double check_equation(double sol)
{
    return a*sol*sol + b*sol + c;
}


int main ()
{
    try
    {
        cout << "Input terms (a,b,c) of quadratic expression: a\u00B7x\u00B2 + b\u00B7x + c = 0 \n";
        
        cin >> a >> b >> c;
        if(cin.fail())
            error("Wrong typed terms");
        
        vector<double> solution;
        solution= solve_equation(a,b,c);

        cout << "Solving equation: " << "x\u2081= " << solution[0] << ", x\u2082= " << solution[1] << '\n';
        cout << "Testing for x\u2081, \u03B5=" << check_equation(solution[0]) << '\n';
        cout << "Testing for x\u2082, \u03B5=" << check_equation(solution[1]) << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown error" << '\n';
    }
    
}