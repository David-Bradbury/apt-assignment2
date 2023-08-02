#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   LinkedList(const LinkedList& other);
   //return the size of the linked list
   int size() const;

   //retrun node at index
   Tile* get(const int index) const;
   //Add to the front of the list
   void addFront(Tile* tile);
   //Add to the back of the list
   void addBack(Tile* tile);
   //delete tile from the list
   void removeTile(Tile* tileToDelete);
   //check if tile is in list
   bool tileInList(Tile* tile);
   //remove the end of the list
   void removeEnd();

   void deleteFront();

   bool isEmpty();

private:
   Node* head;
   Node* tail;

};

#endif // ASSIGN2_LINKEDLIST_H

