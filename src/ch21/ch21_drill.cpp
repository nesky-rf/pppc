#include "../std_lib_facilities.h"
#include <fstream>
#include <iterator>
#include <map>
#include <numeric>

struct Item {
    string name;
    int iid;
    double price;
};

istream& operator>>(istream& is, Item& i)
{
    is >> i.name >> i.iid >> i.price;
    return is;
}

ostream& operator<<(ostream& os, vector<Item>& it)
{
    for(vector<Item>::iterator p=it.begin(); p!= it.end(); ++p)
    {
        os << "name: " << p->name << ", id: " << p->iid << ", price: " << p->price << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, list<Item>& it)
{
    for(list<Item>::iterator p=it.begin(); p!= it.end(); ++p)
    {
        os << "name: " << p->name << ", id: " << p->iid << ", price: " << p->price << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, map<string,int>& it)
{
    for(map<string,int>::iterator p=it.begin(); p!= it.end(); ++p)
    {
        os << "key: " << p->first << ", value: " << p->second << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, map<int,string>& it)
{
    for(map<int,string>::iterator p=it.begin(); p!= it.end(); ++p)
    {
        os << "key: " << p->first << ", value: " << p->second << endl;
    }
    return os;
}

struct item_name {
    bool operator()(const Item& a, const Item& b)
    {
        return a.name < b.name;
    }
};

struct item_iid {
    bool operator()(const Item& a, const Item& b)
    {
        return a.iid < b.iid;
    }
};

struct item_price {
    bool operator()(const Item& a, const Item& b)
    {
        return a.price > b.price;
    }
};

struct pred_name {
    string name;
    pred_name(string s): name(s) {}
    bool operator()(const Item& i) {
        return i.name == name;
    }
};

struct pred_iid {
    int iid;
    pred_iid(int i): iid(i) {}
    bool operator()(const Item& i) {
        return i.iid == iid;
    }
};

int accu_bop(int& a, const pair<string,int>& b)
{
    return a + b.second;
}

map<int,string> swap_contents(const map<string,int>& m)
{
    map<int,string> r;
    for( map<string,int>::const_iterator p=m.begin(); p!= m.end(); ++p)
        r.insert(pair<int,string>(p->second,p->first));
    return r;
}

void vector_drill(ifstream&);
void list_drill(ifstream&);
void map_drill();

int main()
{
    ifstream is("input_drill.txt");
    if(!is) error("file input not found\n");
    // use vectors
    // vector_drill(is);
    // use list
    // list_drill(is);
    // use maps
    map_drill();
    return 0;
}

void vector_drill(ifstream& is)
{
    vector<Item> vi;
    Item item;
    while(is >> item)
        vi.push_back(item);
    // sorting elements
    cout << "unsorted items:\n" << vi << endl;
    sort(vi.begin(),vi.end(),item_name());
    cout << "sorted items (name):\n" << vi << endl;
    sort(vi.begin(),vi.end(),item_iid());
    cout << "sorted items (id):\n" << vi << endl;
    sort(vi.begin(),vi.end(),item_price());
    cout << "sorted items (price):\n" << vi << endl;
    // insert new elements
    vi.insert(vi.end(),{"horse shoe",99,12.34});
    vi.insert(vi.end(),{"Canon S400",9988,499.95});
    cout << "insert items:\n" << vi << endl;
    // erase elements
    vector<Item>::iterator it =  find_if(vi.begin(),vi.end(),pred_name("horse shoe"));
    cout << "items to delete: " << (it!=vi.end()?it->name:"None") << endl;
    vi.erase(it);
    it =  find_if(vi.begin(),vi.end(),pred_iid(456));
    cout << "items to delete: " << (it!=vi.end()?it->name:"None") << endl;
    vi.erase(it);
    cout << "erased items:\n" << vi << endl;
}

void list_drill(ifstream& is)
{
    list<Item> li;
    Item item;
    while(is >> item)
        li.push_back(item);
    // sorting elements
    cout << "original list:\n" << li << endl;
    li.sort(item_name());
    cout << "sorted items (name):\n" << li << endl;
    li.sort(item_iid());
    cout << "sorted items (id):\n" << li << endl;
    li.sort(item_price());
    cout << "sorted items (price):\n" << li << endl;
    // insert new elements
    li.insert(li.end(),{"horse shoe",99,12.34});
    li.insert(li.end(),{"Canon S400",9988,499.95});
    cout << "insert items:\n" << li << endl;
    // erase elements
    list<Item>::iterator it =  find_if(li.begin(),li.end(),pred_name("horse shoe"));
    cout << "items to delete: " << (it!=li.end()?it->name:"None") << endl;
    li.erase(it);
    it =  find_if(li.begin(),li.end(),pred_iid(456));
    cout << "items to delete: " << (it!=li.end()?it->name:"None") << endl;
    li.erase(it);
    cout << "erased items:\n" << li << endl;
}

void map_drill()
{
    map<string,int> msi;
    msi.insert({"string",1});
    msi.insert({"vector",2});
    msi.insert({"list",3});
    msi.insert({"map",4});
    msi.insert({"set",5});
    cout << "map items\n" << msi << endl;
    // erase pairs
    msi.clear();
    cout << "map items\n" << msi << endl;
    string first;
    int second;
    // insert pairs
    while(cin >> first >> second)
        msi[first] =second;
    cout << "map items\n" << msi << endl;
    // accumulate
    int acu = accumulate(msi.begin(),msi.end(),0,accu_bop);
    cout << "acc items: " << acu << endl;
    // copy items
    map<int,string> mis=swap_contents(msi);
    cout << "map items\n" << mis << endl;
}