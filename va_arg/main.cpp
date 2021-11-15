#include <iostream>

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

using namespace std;


void func2 (const char * _format, ...)
{
  va_list al, al2;
  va_start (al, _format);
  long addr = 0;
  memcpy (&addr, al, 4);
  al2 = (va_list) addr;
  //al2 = va_arg (al, va_list);
  vprintf (_format, al2);
  va_end (al);  
}

void func1 (const char * _format, ...)
{
  va_list al;
  va_start (al, _format);
  vprintf (_format, al);
  func2 (_format, al);
  va_end (al);  
}

int main()
{
    cout << "Hello World!" << endl;
    func1 ("format: %d %d %f\n", 3, 4, 4.5);
    return 0;
}

