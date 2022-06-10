#include "exp_dyn_static_cast.h"

void FactoryFunc (Factory0 * _f)
{
   _f->F0();
}


void exp_dyn_static_cast ()
{
    Factory2 *factory2 = new Factory2 ();
    //Factory1 *factory = new Factory1 ();
    Factory1 *factory = factory2;
    factory->F1();
    Factory0 *factory0 = factory2;
    factory0->F0();
    cout << "calling FactoryFunc ()" << endl;
    
    //Factory0* factory0_2 = factory2;
    //Factory0* factory0_2 = static_cast<Factory0*>(factory);  
    Factory0* factory0_2 = dynamic_cast<Factory0*>(factory);  
    Factory0* factory0_3 = dynamic_cast<Factory0*>(factory2);  
    cout << factory2<< " " << factory << " "<< factory0<< " " << factory0_2 << " " << factory0_3 << endl;
    
    FactoryFunc (factory0_2);
    FactoryFunc (factory0_3);    
    FactoryFunc(factory2);
    
    Factory2 *f2 = (Factory2 *)factory0_2;
    cout << f2 << " " << endl;
    FactoryFunc (factory0_2);
   /* 
    C* pC = new C;    
    A* pA = pC;
    D* pD = static_cast<D*> (pC); 
    D* pD2 = (D*)pC; 
    cout << pC << " " << pD << " " << pD2 << " " << pA << endl;
    
    A* pA2 =new A ;    
    //B* pB2 = static_cast <B*>(pA2);
    B* pB2 = (B*)pA2;
    pA2 = pB2;
    cout << pA2 << " " << pB2 << " " << pA2 << endl;
    cout << pB2->g << endl;
    */
    cout << "next test" << endl;
    Factory2 *fc2 = new Factory2 ();
    fc2->F0();
    Factory0 *fc0 = static_cast<Factory0 *> (fc2);
    fc0->Factory0::F0();
    C* pC = new C;
    A* pA = static_cast<A*>(pC);
    //A* pA = pC;
    D* pD = static_cast<D*> (pC);
    //D* pD = pC;
    B* pB = static_cast<B*> (pA);
    //B* pB = dynamic_cast <B*>(pA);
    std::cout << &(pB->g) << " " << pD << " " << pA << std::endl;
    pB->g = 100;
    std::cout << pC->a << " " << pC->b << " " << pC->f << std::endl;
    
   
    /* C* pC = new C;
    A* pA = pC;
   
    if(D* pD = dynamic_cast<D*> (pC))
        std::cout << " OK " << std::endl;
    else
        std::cout << " not OK " << std::endl;
       
    if(B* pB = dynamic_cast<B*> (pA))
        std::cout << " OK " << std::endl;
    else
        std::cout << " not OK " << std::endl;
     */ 
}
