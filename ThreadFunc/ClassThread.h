#ifndef CLASSTHREAD_H
#define CLASSTHREAD_H

#include <iostream>

using namespace std;

class A {
    public:
        int a;
        A (int _a){
            cout<<"Ctor A"<<endl;
            a = _a;
        }    
        void func () { cout<<"func () class A, member a is "<< a << endl;}
        ~A () { cout<<"Dtor () class A"<< endl;}        
};

class B : public A {
    public:
        B (int _a):A(_a) {
            cout<<"Ctor B"<<endl;
        }    
        void func () { cout<<"func () class B"<< endl;}
        ~B () { cout<<"Dtor () class B"<< endl;}        
};

#endif // CLASSTHREAD_H

