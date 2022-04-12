struct X 
{
    void f(int x) {
        struct Y {
            int f() 
            { 
                return 1 ; 
            } 
            int m; 
        };
        int m;
        m=x; 
        Y m2;
        return f(m2.f()); 
    }

    int m; 
    void g(int m) {
        if (m) f(m+2); 
        else g(m+2); 
    }

    X() { } 
    void m3() { }
};
    int main() 
    {
        X a; 
        a.f(2); 
        return 0;
    }

