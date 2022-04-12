#include "../std_lib_facilities.h"

int convert_string(const string&);

int main () {
    cout << "Please, enter two operands and a operator: (Escape with '|').\n";
    char c;

    while (cin >> c)
    {
        if ( (c >= '0') && (c <= '9') )
        {
            double operand1, operand2, result;
            char operation;
            cin.putback(c);
            cin >> operand1 >> operand2 >> operation;
            
            switch(operation)
            {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: cout << "Operation not permitted\n";
            }
            cout << "Result: " << operand1 << operation << operand2 << " = " << result <<'\n';
        }
        else if (c == '|')
        {
            cout << "Escape character detected.\n";
            break;
        }
        
        else if(c >= 'a' && c <= 'z')
        {
            string str1, str2;
            char operation;
            double operand1, operand2, result;

            cin.putback(c);
            cin >> str1 >> str2 >> operation;
            
            operand1 = convert_string(str1);
            operand2 = convert_string(str2);
            if ( operand1 == -1 || operand2 == -1)
            {
                cout << "Wrong operands.\n"; 
                continue;
            }

            switch(operation)
            {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: cout << "Operation not permitted\n";
            }
            
            cout << "Result: " << operand1 << operation << operand2 << " = " << result <<'\n';
        }
    }
    
    return 0;
}

int convert_string(const string& input)
{
    if(input == "zero") return 0;
    else if(input == "one") return 1;
    else if(input == "two") return 2;
    else if(input == "three") return 3;
    else if(input == "four") return 4;
    else if(input == "five") return 5;
    else if(input == "six") return 6;
    else if(input == "seven") return 7;
    else if(input == "eight") return 8;
    else if(input == "nine") return 9;
    else return -1;

}