#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

int objs = 0;

template<class T>
class my_shared_ptr
{
private:
  T * ptr = nullptr;
  uint * refCount = nullptr;
  int objcounter;

public:
  my_shared_ptr() : ptr(nullptr), refCount(new uint(0)) // default constructor
  {
      objcounter = ++objs;
      cout << "ptr default constructor, objects counter: "<< objcounter << " refcounter: "<< *refCount << endl;
  }

  my_shared_ptr(T * ptr) : ptr(ptr), refCount(new uint(1)) // constructor
  {
      objcounter = ++objs;
      cout << "ptr constructor with *, objects counter: "<< objcounter << " refcounter: "<< *refCount << endl;
  }

  /*** Copy Semantics ***/
  my_shared_ptr(const my_shared_ptr & obj) // copy constructor
  {
    objcounter = ++objs;
    this->ptr = obj.ptr; // share the underlying pointer
    this->refCount = obj.refCount;
    if (nullptr != obj.ptr)
    {
      (*this->refCount)++; // if the pointer is not null, increment the refCount
    }
    cout << "ptr copy constructor, objets counter: "<< objcounter << " refcounter: "<< *refCount << endl;
  }

  my_shared_ptr& operator=(const my_shared_ptr & obj) // copy assignment
  {
    objcounter = ++objs;
    cleanup(); // cleanup any existing data
    // Assign incoming object's data to this object
    this->ptr = obj.ptr; // share the underlying pointer
    this->refCount = obj.refCount;
    if (nullptr != obj.ptr)
    {
      (*this->refCount)++; // if the pointer is not null, increment the refCount
    }
    
    cout << "assigment constructor, objects counter: "<< objcounter << "refcounter: "<< *refCount << endl;
  }

  /*** Move Semantics ***/
  my_shared_ptr(my_shared_ptr && dyingObj) // move constructor
  {
    this->ptr = dyingObj.ptr; // share the underlying pointer
    this->refCount = dyingObj.refCount;

    dyingObj.ptr = dyingObj.refCount = nullptr; // clean the dying object
  }

  my_shared_ptr& operator=(my_shared_ptr && dyingObj) // move assignment
  {
    cleanup(); // cleanup any existing data
    
    this->ptr = dyingObj.ptr; // share the underlying pointer
    this->refCount = dyingObj.refCount;

    dyingObj.ptr = dyingObj.refCount = nullptr; // clean the dying object
  }

  uint get_count() const
  {
    return *refCount; // *this->refCount
  }

  T* get() const
  {
    return this->ptr;
  }

  T* operator->() const
  {
    return this->ptr;
  }

  T& operator*() const
  {
    return this->ptr;
  }

  ~my_shared_ptr() // destructor
  {
    cleanup();
  }

private:
  void cleanup()
  {
    (*refCount)--;
    cout<< "cleanup (), objects counter: " << objcounter << " refCounter: " << *refCount << endl;
    if (*refCount == 0)
    {
      if (nullptr != ptr)
        delete ptr;
      delete refCount;
    }
  }
};


class A {
    public:
    my_shared_ptr<A> ain;
    A () { cout << "ctor A" << endl; };
    ~A () { cout << "dtor A" << endl; }
};
int main()
{
    
    cout<<"Hello World"<<endl;
    my_shared_ptr<A> a(new A());
    //cout << "init ain" << endl;
    //a->ain = a;
    //cout << "after init ain" << endl;
    vector <my_shared_ptr<A>> v;
    cout << "after v" << endl;
    v.push_back(a);
    
    return 0;
}
