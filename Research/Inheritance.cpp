#pragma once
#include <iostream>

namespace cpp
{
   using namespace std;
   class A
   {
   public:
      A() { std::cout << "A\n"; }
      virtual ~A() { std::cout << "~A\n"; }

      virtual void f1(int a) { std::cout << "A::f1\n"; }
      int f2(int a) { return 0; }

   };

   class B : public A
   {
   public:
      B() { std::cout << "B\n"; }
      ~B() { std::cout << "~B\n"; }
      void f1(int a) override { std::cout << "B::f1\n"; };
   };

   void TestInheritance()
   {
      B b;
      b.f1(1);
      cout << "-----" << endl;
      A a;
      a.f1(1);
      cout << "-----" << endl;
      A* pa = new B();
      pa->f1(1);
      delete pa;
   }

} // cpp