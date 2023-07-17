
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
   //Add to the front of the list
   void addFront(Tile* tile);
   //Add to the back of the list
   void addBack(Tile* tile);
   //delete tile from the list
   void deleteTile(Tile* tileToDelete);
   //check if tile is in list
   bool tileInList(Tile* tile);

private:
   Node* head;
   
};

#endif // ASSIGN2_LINKEDLIST_H
