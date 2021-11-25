#include <iostream>

using namespace std;

class A  {
    public:
    
        int member;
        
        A () {
            cout << "ctor ()" << endl;
            member = 1; 
        }  
        A (int _m) {
            cout << "ctor (int _m)" << endl;
            member = _m; 
        }  
        
        A (const A &) {
            cout << "CTOR COPY!!!" << endl;
            member = 3; 
        } 
        void p () {
            cout << "member: "<< member << endl;
        }
};

void func1 (A _a) 
{ 
    cout << "in func1" << endl;
    _a.p();
}


A func2 (A _a) 
{ 
    cout << "in func2" << endl;
    //A a = _a;
    
    A *a = new A (25);
    a->p();
    
    A b;
    b.p();
    
    //return *a;
    return b;
}

int main()
{
    cout << "a1" << endl;
    A a1;
    a1.p();
    cout << endl;
    
    cout << "a2" << endl;
    A a2 = a1;  
    a2.p();
    cout << endl;
    
    cout << "a2.5" << endl;
    A a25(a1);  
    a25.p();
    cout << endl;
    
    cout << "a3" << endl;
    A a3 = A ();
    a3.p();
    cout << endl;
    
    cout << "a4" << endl;
    A a4(A{});  //!!! ()
    a4.p();
    cout << endl;
    
    cout << "a5" << endl;
    A a5(A(2));
    a5.p();
    cout << endl;
    
    cout << "a6" << endl;
    A a6 = A(2);
    a6.p();
    cout << endl;
    
    cout << "func1" << endl;             
    func1 (a1);
    cout << endl;
    
    cout << "func1.1" << endl;             
    func1 (A());
    cout << endl;
    
    cout << "func2" << endl;             
    
    A f2 = func2 (a1);
    
    f2.p();
    cout << endl;
    
    return 0;
}
