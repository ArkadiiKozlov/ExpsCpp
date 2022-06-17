#include <iostream>

extern "C" {
#include <pthread.h>
#include <unistd.h>
}

#include "ClassThread.h"

using namespace std;

void *thread_func_wrapper (void *_in) {
  cout << "in thread" << endl;
  A *a = (A*) _in;
  a->func();
  return NULL;
}

int main()
{
    cout << "Hello World!" << endl;
    A a (1);
    B b (11);
    
    b.func();
    b.A::func();
    A *a_ptr = dynamic_cast <class A *>(&b);
    a_ptr->func();

    pthread_t tid;
    pthread_create(&tid, NULL, thread_func_wrapper, &a);
    sleep (1);
    A a2 (2);
    pthread_create(&tid, NULL, thread_func_wrapper, &a2);
    sleep (1);
    return 0;
}
