
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   void addToBack();

   //retrun node at index
   Node* get(int index);

private:
   Node* head;
   
};

#endif // ASSIGN2_LINKEDLIST_H
