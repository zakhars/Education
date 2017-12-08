#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Compiler-generated special operations
class A
{
   int a;
public:

   A() //=default
   {
      a = 0;
      cout << "A::A()" << endl; 
   }

   A(const A& other) //=default
   {
      a = other.a;
      cout << "A::A(A&)" << endl; 
   }

   A& operator=(const A& other) //=default 
   {
      a = other.a;
      cout << "A::operator=(A&)" << endl; 
      return *this; 
   }

   ~A() //=default
   {
      cout << "A::~A()" << endl; 
   }

};

int main_tmp()
{
   // What is called for each line below?
   A a1;
   A a2(a1);
   A a3 = A(a1);
   A a4 = a1;
   a4 = a1;
   A a5 {a2};
   cout << "-----" << endl;
   auto copy_arg = [](A arg) {};
   copy_arg(a1);
   cout << "-----" << endl;
   auto ref_arg = [](A& arg) {};
   ref_arg(a1);
   cout << "-----" << endl;

   return 0;
}


// Any class that manages a resource (e.g. smart pointer) needs to implement The Big Three:
//   - copy constructor
//   - copy assignment
//   - destructor 

class dynamic_array
{
    size_t m_size;
    int* m_pdata;

public:

    // default constructor
    dynamic_array(size_t size = 0, int val = 42)
        : m_size(size),
          m_pdata(m_size ? new int[m_size] : nullptr)
    {
       std::fill(m_pdata, m_pdata + m_size, val);
    }

    // copy-constructor 
    dynamic_array(const dynamic_array& other) // (BTW, why argument passed by reference?)
        : m_size(other.m_size),
          m_pdata(m_size ? new int[m_size] : nullptr)
    {
        std::copy(other.m_pdata, other.m_pdata + m_size, m_pdata);
    }
      
    // destructor
    ~dynamic_array()
    {
        delete [] m_pdata;
    }

    // Most complex is copy assignment.
    //dynamic_array& operator=(const dynamic_array& other);

#pragma region Hide
    
    
    dynamic_array& operator=(dynamic_array other) // address (1) - argument by value, and (3) copy .ctor used, no repeat.
    {
        swap(*this, other); // address (2)
        return *this;
    }

    void swap(dynamic_array& first, dynamic_array& second) noexcept
    {
      // member-by-member copy
      std::swap(first.m_size, second.m_size);
      std::swap(first.m_pdata, second.m_pdata);
    }
    
    dynamic_array(dynamic_array&& other) // Ñ++11
      : dynamic_array()
    {
        // swap is possible as default .ctor was called so other can be destructed after swap
        swap(*this, other);
    }

    void work_with_resource_which_can_throw(size_t size) { if (size == 10) throw exception(); }
#pragma endregion

};

// Examples of unsafe code:
//    - deallocate old, allocate new memory
//    - insert element to container
//    - update one field and fail to update another

/*
// Copy constructor - naive solution
dynamic_array& dynamic_array::operator=(const dynamic_array& other)
{
    if (this != &other) // problem (1)
    {
        // get rid of the old data
        delete [] m_pdata; 
        m_pdata = nullptr; // avoid the attempt to delete already deleted memory

        // allocate memory for new data
        m_size = other.m_size; // problem (2)
        work_with_resource_which_can_throw(other.m_size); // problem (2)
        m_pdata = m_size ? new int[m_size] : nullptr; // problem (3)

        // copy new data
        std::copy(other.m_pdata, other.m_pdata + m_size, m_pdata); // problem (3)
    }
    return *this;
}
*/

// (1) Why need this check?
//    - avoid useless copy
//    - avoid destruction by mistake
//
// But (1):
//    - occurs rarely
//    - has performance penalty
//
// (2) Only basic exception guarantee: size already set to a new value but data was not deleted due to exception
//
// (3) Code duplication - small here, but can be large for large classes


/*
// Try to fix problem (2) - exception safety
dynamic_array& dynamic_array::operator=(const dynamic_array& other)
{
    if (this != &other) // (1)
    {
        // get the new data ready before we replace the old - create a copy
        size_t new_size = other.m_size;
        work_with_resource_which_can_throw(other.m_size);
        int* new_pdata = new_size ? new int[new_size]() : nullptr; // (3)
        std::copy(other.m_pdata, other.m_pdata + new_size, new_pdata); // (3)

        // replace the old data (non-throwing)
        delete [] m_pdata;
        m_size = new_size;
        m_pdata = new_pdata;
    }
    return *this;
}
*/

// We can do better! Copy-and-swap fixes all 3 issues
// Copy-and-swap:
//   - avoids code duplication
//   - avoids performance issues
//   - provides strong exception guarantee
//
// Copy-and-swap sequence:
//   - copy argument using copy constructor
//   - swap object internals with obtained copy
//   - destroy copy by taking data from it
//
// To implement copy-and-swap we need to have:
//   - copy constructor
//   - swap function (can't use std::swap as it uses operator= itself and copy .ctor)
//   - destructor
//
// Before we call swap, all the new data is already allocated, copied, and ready to be used. 
// This gives a strong exception guarantee for free (provided by compiler): 
// we won't even enter the function if construction of the copy fails, 
// and it's impossible to alter the state of *this

/*
// Next looks same but here we're loosing optimization opportunity in C++11 with rvalue and move .ctor
dynamic_array& dynamic_array::operator=(dynamic_array& other)
{
    dynamic_array tmp(other);
    swap(*this, other);
    return *this;
}
*/

// Remember about single resposibility principle
// https://en.wikipedia.org/wiki/Single_responsibility_principle


int main_tmp2()
{
   dynamic_array ar1(5, 3);
   dynamic_array ar2;
   dynamic_array ar3 = ar1;
   dynamic_array ar4(10, 4);
   try
   {
      ar3 = move(ar4);
   }
   catch (exception&) 
   {
      cout << "ar3 is in inconsistent state now" << endl;
   }
   return 0;
}
