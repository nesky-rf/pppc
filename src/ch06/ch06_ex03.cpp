#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

const char number = '8';
const char print = '=';
const char quit = 'x';
const string prompt = "> ";
const string result = "Ans: ";

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:
    case quit: 
    case '(': 
    case ')': 
    case '{': 
    case '}':
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '%':
    case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token(number, val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    double d;
    Token t = ts.get();
    switch (t.kind) {
    case '(': case '{':   // handle '(' expression ')'
    {
        d = expression();
        t = ts.get();
        if (t.kind != ')' ) error("')' expected");
        else if (t.kind != '}') error("'}' expected");
        break;
    }
    case '-':
        d = -primary();
        break;
    case '+':
        d = primary();
        break;
    case number:            // we use '8' to represent a number
        d = t.value;  // return the number's value
        break;
    default:
        error("primary expected");
    }

    t = ts.get();
    if(t.kind=='!')
    {
        if(d == 0) d = 1;
            for(int i=d-1;i>0;--i) d *=i;
    }
    else
        ts.putback(t);
    return d;
}

//------------------------------------------------------------------------------

// deal with *, /, and !
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        // case '!':
        //     if(left == 0) left = 1;
        //     for(int i=left-1;i>0;--i) left *=i;
        //     t = ts.get();
        //     break;
        case '%':
            {
                int n = narrow_cast<int>(left);
                int d = narrow_cast<int>(term());
                left = n%d;
                t = ts.get();
            }
            break;
        case '*':
            left *= term();
            t = ts.get();
            break;
        case '/':
            {
                double d = term();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
            }
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

void calculate()
{
    while (cin) {
        cout << prompt ;
        Token t = ts.get();

        if (t.kind == print)
            t = ts.get();
        if (t.kind == quit) 
            return;
        
        ts.putback(t);
        t.value = expression();
        cout << result << t.value << '\n';
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    calculate();
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------