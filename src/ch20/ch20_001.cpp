#include "../std_lib_facilities.h"

typedef vector<char> Line;

class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator cn;
public:
    Text_iterator(list<Line>::iterator lni, Line::iterator cni)
    : ln(lni), cn(cni) {}
    // member functions operators
    char& operator*() { return *cn; }
    Text_iterator& operator++();
    Text_iterator& operator--();
    Text_iterator& operator-(int);
    bool operator==(const Text_iterator& a) const {
        return (a.ln==ln && a.cn==cn);
    }
    bool operator!=(const Text_iterator& a) const {
        return (a.ln != ln || a.cn != cn);
    }
};

Text_iterator& Text_iterator::operator++()
{
    if(cn == ln->end())
    {
        ++ln;
        cn = ln->begin();
    }
    else
        ++cn;
    return *this; 
}

Text_iterator& Text_iterator::operator--()
{
    if(cn == ln->begin())
    {
        --ln;
        cn = ln->end();
    }
    else
        --cn;
    return *this; 
}

Text_iterator& Text_iterator::operator-(int n)
{
    for(int i=0; i<n; i++) {
        if(cn == ln->begin())
        {
            --ln;
            cn = ln->end();
        }
        else
            --cn;
    }
    return *this; 
}

struct Document {
    list<Line> line;
    Document() {
        line.push_back(Line());
    }
    // first char of first line
    Text_iterator begin() {
        return Text_iterator(line.begin(),line.begin()->begin());
    }
    // last char of last line
    Text_iterator end() {
        list<Line>::iterator iter=line.end();
        iter--;                 // decrement iterator to a dereferenceable one!
        return Text_iterator(iter,iter->end());
    }
};

istream& operator>>(istream& is, Document& d)
{
    char ch;
    while(cin>>ch) {
        d.line.back().push_back(ch);
        if(cin.peek()=='\n') {
            d.line.push_back(Line());
        }
    }
    return is;
}

void print(Document& d)
{
    for(Text_iterator p=d.begin(); p!= d.end(); ++p)
        cout << *p;
}

void erase_line(Document& d, int n)
{
    if(n==0||n>d.line.size()) return;
    list<Line>::iterator it=d.line.begin();
    advance(it,n);      // unnested due to void function
    d.line.erase(it);
}

Text_iterator find_txt(Text_iterator begin, Text_iterator end, const string& s)
{
    Text_iterator p = begin;

    while(p != end)
    {
        if (*p == s[0])
        {
            int i=1;
            while(*++p==s[i]) i++;
            if(i==s.size()) return p-s.size();
        }
        ++p;
    }
    return end;
}

int main()
{
    Document doc;
    cin >> doc;
    cout << "Input lines: " << doc.line.size() << endl;
    print(doc);
    cout << endl;
    // 
    // erase_line(doc,3);
    // print(doc);
    // cout << endl;
    Text_iterator p = find_txt(doc.begin(),doc.end(),"tothe");
    if(p!=doc.end())
        cout << "match: " << *p << endl;
    else
        cout << "not found" << endl;
    
    return 0;
}