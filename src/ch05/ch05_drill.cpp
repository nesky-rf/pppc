# include "../std_lib_facilities.h"

int main()
{
    try
    {
        cout << " Success!\n" ;     //Cout
        cout << " Success !\n" ;    //"
        cout << " Success" << "!\n"; //;, "
        cout << "success" << endl;      // ""
        {int res = 7 ; vector<int> v(10); v[5] = res; cout << " Success!\n ";}   //int, "",int,v[5]
        {vector<int> v(10); v[5] = 7; if (v[5]!=7) cout << " Success!\n" ;} // int,v[5],!=
        {if (true) cout << "Success!\n "; else cout << "Fail!\n" ;}   // true
        {bool c = false; if (c) cout << "Success !\n " ; else cout << "Fail!\n " ;}
        {string s = "ape " ; bool c = "fool"<s; if (c) cout << "Success!\n ";}  //bool
        {string s = "ape "; if (s=="fool") cout << "Success !\n " ;}
        {string s = "ape" ; if (s=="fool") cout << "Success!\n " ;} //<<
        {string s = "ape"; if (s=="fool ") cout << " Success!\n " ;}  //<<,==
        {vector<char> v(5); for (int i=0; i<v.size(); ++i) ; cout << " Success !\n " ;} //5, 0
        {vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << " Success !\n " ;}    //5
        {string s = "Success!\n " ; for (int i=0; i<6 ; ++i) cout << s[i];}   //0
        {if (true) cout << "Success!\n " ; else cout << " Fail!\n " ;}   //then?
        {int x = 2000; int c = x; if (c==2000 ) cout << " Success!\n " ;}   //int
        {string s = "Success !\n "; for (int i=0; i<10; ++i) cout << s[i] ;}  //0
        {vector<string> v(5); for (int i=0; i<v.size(); ++i) ; cout << "Success !\n " ;} //vector<string> v(5)
        {int i =0 ; int j = 9; while (i<10) ++i; if (j<i) cout << "Success !\n";} //i
        {int x = 2; double d = 5/(x-2.0); if (d==2*x+0.5) cout << "Success!\n " ;} // 2.0
        {string s = " Success !\n " ; for (int i=0; i<=10; ++i) cout << s[i];} //string
        {int i=0; while (i<10) ++i; if (i<10) cout << " Success !\n ";}
        {int x = 4; double d = 5/(x-2); if (d=2*x+0.5) cout << " Success!\n " ;}
        cout << "Successssssssss!\n " ;  //cout

        keep_window_open();
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch(...)
    {
        cerr << "Oops: unknown exception !\n " ;
        keep_window_open();
        return 2;
    }
    
}