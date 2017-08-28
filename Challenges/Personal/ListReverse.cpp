#pragma once

struct Node
{
   int data;
   Node* next;
   Node(int d) : data(d), next(nullptr) {}
};

void RotateList() 
{
   Node* head = new Node(1);
   head->next = new Node(3);
   head->next->next = new Node(2);

   Node* p1 = head;
   Node* p2 = p1->next;
   Node* p3 = (p2 ? p2->next : nullptr);
   while(p2)
   {
      p2->next = p1;
      p1 = p2;
      p2 = p3;
      p3 = (p3 ? p3->next : nullptr);
   }
   head->next = nullptr;
   head = p1;
}
