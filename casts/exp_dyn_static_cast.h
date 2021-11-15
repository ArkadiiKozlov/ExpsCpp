#ifndef EXP_DYN_STATIC_CAST_H
#define EXP_DYN_STATIC_CAST_H

#include <iostream>
using namespace std;

void exp_dyn_static_cast ();

class Factory0
{
    public:
        int a;
        Factory0() { 
          a = 0;
          cout << "ctor Factory0 " << a << endl; 
          
        };        
        //virtual void F0 () = 0;
        virtual void F0 () { cout << "F0 from Factory0" << endl; };
        virtual void F1 () { cout << "F1 from Factory0" << endl; };
};

void FactoryFunc (Factory0 *);

class Factory1
{
    public:
        Factory1() { cout << "ctor Factory1" << endl; };        
        //virtual void F1 () = 0;
        virtual void F0 () { cout << "F0 from Factory1" << endl; };
        virtual void F1 () { cout << "F1 from Factory1" << endl; };
};

class Factory2 : public Factory0, public Factory1
{
    public:
        int a;
        Factory2() { 
        a = 2;
        cout << "ctor Factory2 " << a << endl;            
        };        
        virtual void F0 () { cout << "F0 from Factory2" << endl;};
        virtual void F1 () { cout << "F1 from Factory2" << endl;};
        
        
};

class Factory3 : public Factory0, public Factory1
{
    public:
        Factory3() { cout << "ctor Factory3" << endl; };          
        virtual void F0 () { cout << "F0 from Factory3" << endl;};      
        virtual void F1 () { cout << "F1 from Factory3" << endl;};
        
};


struct A{
    A():a(0), b(0){}
  int a;
  int b;
};
struct B : A{
    B():g(0){}
    int g;
};
struct D{
    D():f(0){}
    float f;
};
struct C : A, D{
    C():d(0){}
    double d;
};

#endif // EXP_DYN_STATIC_CAST_H
