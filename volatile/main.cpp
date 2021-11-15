#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

//volatile int opt = 1;
int opt = 1;

void Fn(void) {
    cout << "in Fn ()" << endl;
    start:
        if (opt == 1)
            goto start;
        else
            cout << "Fn (): opt = 0" << endl;    
}

void Wait()
{
    cout << "in wait ()" << endl;
    while (opt) {
        usleep(1000); // ждать 1000 миллисекунд
    }
    cout << "end of wait ()" << endl;
}
    
void Fn2(void) {
  cout << "in Fn2()" << endl;
  sleep (2);
  cout << "Fn2 (): opt = 0" << endl;
  opt = 0;
}

int main()
{
    cout << "Hello World!" << endl;
    thread thr1 (Fn2);
    Fn ();  
    //Wait ();  
    thr1.join();  
    return 0;
}

/*
void Fn(void) {
    start:
    int opt = 1;
    if (true)
        goto start;
)
*/

