#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   // Constructors / Destructor
   LinkedList();
   ~LinkedList();
   LinkedList(const LinkedList& other);

   // Return the size of the linked list.
   int size() const;

   // Get a pointer to the node at index provided
   // Contract = the provided index needs to be within the size range of the list.
   Tile* get(const int index) const;

   // Add to the front of the list.
   void addFront(Tile* tile);

   // Add to the back of the list.
   void addBack(Tile* tile);

   // Delete tile from the list.
   // N.B. This will only currently delete the first occurance of the provided tile
   // it will not delete duplicates.
   void removeTile(Tile* tileToDelete);

   // Check if tile is in list.
   bool tileInList(Tile* tile);

   // Remove the end of the list.
   void removeEnd();

   // Remove the front node of the list.
   void removeFront();

   // returns true if list is empty.
   bool isEmpty();


private:

   Node* head;
   Node* tail;

};

#endif // ASSIGN2_LINKEDLIST_H

