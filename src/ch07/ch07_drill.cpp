#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string s)
        :kind(ch), name(s) { }
};

class Variable{
public:
    string name;
    double value;
    Variable(string n, double v): name(n), value(v) {}
};

//------------------------------------------------------------------------------

const char number = '8';
const char print = '=';
const char quit = 'x';
const string prompt = "> ";
const string result = "Ans: ";

const char name= 'a';           // token for variable name
const char lett= 'L';            // token let keyword
const string declkey= "let";

const char sqrtt= 'S';
const string sqrtkey= "sqrt";
const char powt= 'P';
const string powkey= "pow";

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore();
    void ignore(char);
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
    case ',':
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
        if(isalpha(ch))
        {
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+= ch;
            cin.putback(ch);
            if (s == declkey) return Token(lett);
            if (s == sqrtkey) return Token(sqrtt);
            if (s == powkey) return Token(powt);
            return Token(name, s);
        }
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

void Token_stream::ignore()
{
    cin.ignore();
}

void Token_stream::ignore(char ch)
{
    if(full == true)
    {
        buffer = false;
        full = false;
    }
    char c;
    while(cin >> c)
        if (c == ch) return;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()
double get_value(string);

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    double d;
    Token t = ts.get();
    switch (t.kind) {
    case '(':   // handle '(' expression ')'
    {
        d = expression();
        t = ts.get();
        if (t.kind != ')' ) error("')' expected");
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
    case name:
        d = get_value(t.name);
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

vector<Variable> var_table;

double get_value(string s)
{
    for(int i=0;i < var_table.size(); i++)
        if(var_table[i].name == s)
            return var_table[i].value;
    error("get: variable undefined");
}

bool is_declared(string s)
{
    for(int i=0;i < var_table.size(); i++)
        if(var_table[i].name == s)
            return true;
    return false;
}

double define_name(string s, double d)
{
    if(is_declared(s)) error("define: variable already defined");
    var_table.push_back(Variable(s,d));
    return d;
}

double declaration()
{
    Token t=ts.get();
    if(t.kind != name) error("declaration: syntax error");
    string var = t.name;

    Token t2=ts.get();
    if(t2.kind != '=') error("declaration: syntax error");

    double d = expression();
    define_name(var, d);
    return d;
}

double square_root()
{
    double d = expression();
    if(d<0) error("sqrt: negative number");
    return sqrt(d);
}

double pow_n()
{
    Token t=ts.get();
    if(t.kind != '(') error("pow: syntax error");
    double n = expression();
    t=ts.get();
    if(t.kind != ',') error("pow: syntax error");
    double p = expression();
    t=ts.get();
    if(t.kind != ')') error("pow: syntax error");

    return(pow(n,p));
}

double statement()
{
    Token t=ts.get();
    switch(t.kind)
    {
        case lett:
            return declaration();
        case sqrtt:
            return square_root();
        case powt:
            return pow_n();
        default:
            ts.putback(t);
            return expression();
    }
}

//------------------------------------------------------------------------------

void calculate()
{
    while (cin) {
        try
        {
            cout << prompt ;
            Token t = ts.get();

            if (t.kind == print)
                t = ts.get();
            if (t.kind == quit) 
                return;
            
            ts.putback(t);
            cout << result << statement() << '\n';
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
            ts.ignore();
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    define_name("pi",3.1415926535);
    define_name("e",2.7182818284);

    calculate();
    keep_window_open();
    return 0;
}
catch (const exception& e) {
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