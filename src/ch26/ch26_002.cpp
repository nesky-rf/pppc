#include "../std_lib_facilities.h"
#include <iterator>
#include <fstream>
#include <sstream>

void make_test(ofstream& os, const string& lab, int n, int base, int spread)
    // write a test description with the label lab to cout
    // generate a sequence of n elements starting at base
    // the average distance of elements is spread
{
    vector<int> v;
    int num = base;
    // generate random n sequence numbers
    for(int i=0; i < n; ++i)
    {
        num = base +(rand()%spread);
        v.push_back(num);
    }
    // number to search
    int val = base +(rand()%spread);
    //
    bool b = false;
    for(int i=0; i < n; ++i)
        if (v[i]==val)
            b = true;
    // report
    stringstream ss;
    ss << "{ " << lab << " " << val << " { ";
    sort(v.begin(),v.end());
    copy(v.begin(),v.end(),ostream_iterator<int>(ss," "));
    ss << " } " << b << " } " << endl;
    //
    os << ss.str();
}



int main()
{
    clock_t t1=clock();
    srand(time(NULL));
    string s {"_test_"};
    string fn {"_unit_case_"};  // output filename
    time_t t;
    time(&t);       // get epoch time
    fn += to_string(t) + ".txt"; // add epoch to filename.txt
    int no_tests = 20000;
    // generate tests -> output file
    ofstream ofs;
    ofs.open(fn);
    if(!ofs) cerr << "file not generated" << endl;
    else cout << "generating " << fn << "...";
    //
    for(int i=0; i < no_tests; i++)
        make_test(ofs, s+to_string(i),10,0,50);
    //
    ofs.close();
    cout << "Done" << endl;
    //
    clock_t t2=clock();
    cout << "test generation time: " << double(t2-t1)/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
