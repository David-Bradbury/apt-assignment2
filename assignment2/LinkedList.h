#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

template <class T>
class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   LinkedList(const LinkedList& other);
   //return the size of the linked list
   int size() const;

   //retrun node at index
   Node<T>* get(const int index) const;
   //Add to the front of the list
   // template <class T>
   void addFront(T data);
   //Add to the back of the list
   void addBack(T data);
   //delete tile from the list
   void deleteTile(T data);
   //check if tile is in list
   bool inList(T data);

private:
   Node<T>* head;

};

#endif // ASSIGN2_LINKEDLIST_H

