#include <iostream>

namespace sp
{
   using namespace std;

   template<typename T> class shared_ptr_my
   {
      T* po = nullptr;
      size_t* rc = new size_t(0);

      void inc() { ++(*rc); }
      void dec() { --(*rc); }

   public:
      shared_ptr_my()
      {
         cout << "default .ctor called, rc = " << *rc << endl;
      }

      shared_ptr_my(T* p)
      {
         inc();
         cout << ".ctor with new address called, rc = " << *rc << endl;
         po = p;
      }

      shared_ptr_my(const shared_ptr_my<T>& other)
      {
         cout << "copy .ctor called, rc = " << *rc;
         rc = other.rc;
         inc();
         cout << ", new rc = " << *rc;
         po = other.po;
         cout << endl;
      }

      shared_ptr_my<T>& operator= (const shared_ptr_my<T>& other)
      {
         if (&other != this)
         {
            cout << "operator= called, rc = " << *rc;
            if (*rc != 0)
            {
               dec();
               cout << ", new rc = " << *rc;
               if (*rc == 0)
               {
                  delete po;
                  cout << ", object removed";
               }
            }
            rc = other.rc;
            inc();
            po = other.po;
         }
         cout << endl;
         return *this;
      }

      ~shared_ptr_my()
      {
         cout << ".dtor called, rc = " << *rc;
         if (*rc > 0)
         {
            dec();
            cout << ", new rc = " << *rc;
         }
         if (*rc == 0 && po)
         {
            delete po;
            po = nullptr;
            cout << ", object removed";
         }
         cout << endl;
      }
   };

   void shared_ptr_test()
   {
      cout << "1:" << endl;
      shared_ptr_my<int> p1 = new int(5);
      cout << "2:" << endl;
      shared_ptr_my<int> p2 = p1;
      cout << "3:" << endl;
      shared_ptr_my<int> p3 = new int(53);
      cout << "4:" << endl;
      p3 = p2;
      cout << "5:" << endl;
      shared_ptr_my<int> p4;
      cout << "6:" << endl;
      p3 = p1;
      cout << "7:" << endl;
      shared_ptr_my<int> p5(p1);
      shared_ptr_my<int> p6(p1);
      shared_ptr_my<int> p7(p1);
      shared_ptr_my<int> p8(p1);
   }

}