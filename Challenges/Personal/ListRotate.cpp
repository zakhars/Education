#include <iostream>
#include <memory>

using namespace std;

template<typename T> struct Node
{
   T val;
   Node* next;
   Node(T v) : val(v), next(nullptr) {}
};


template<typename T>
pair<size_t, Node<T>*> GetListSizeAndTail(Node<T>* head)
{
   size_t sz = 0;
   Node<T>* tail = nullptr;
   while (head != nullptr)
   {
      ++sz;
      if (head->next == nullptr)
      {
         tail = head;
      }
      head = head->next;
   }
   return make_pair(sz, tail);
}

// head->1->2->3->4->nullptr

template<typename T> 
void RotateList(Node<T>*& head, int shift)
{
   auto list_params = GetListSizeAndTail(head);
   auto sz = list_params.first;
   auto& tail = list_params.second;
   shift %= sz;
   if (shift == 0)
   {
      return;
   }

   auto cur = head;
   if (shift > 0)
   {
      for (size_t i = 0; i < sz - shift - 1; ++i)
      {
         cur = cur->next;
      }
   }
   else if (shift < 0)
   {
      for (int i = 0; i < abs(shift) - 1; ++i)
      {
         cur = cur->next;
      }
   }
   tail->next = head;
   head = cur->next;
   cur->next = nullptr;
}

int RotateList_Test()
{
   Node<int>* head = new Node<int>(1);
   head->next = new Node<int>(2);
   head->next->next = new Node<int>(3);
   head->next->next->next = new Node<int>(4);

   RotateList(head, 3);

   Node<int>* current = head;
   while (current != nullptr)
   {
      cout << current->val << " ";
      Node<int>* node_next = current->next;
      delete current;
      current = node_next;
   }
   cout << endl;

   return 0;
}