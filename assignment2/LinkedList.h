
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();

   //retrun node at index
   Node* get(int index);
   void addBack(Tile* tile);

private:
   Node* head;
   
};

#endif // ASSIGN2_LINKEDLIST_H
