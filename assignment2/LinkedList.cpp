
#include "LinkedList.h"

LinkedList::LinkedList() {
   
   head = nullptr;
   
}

LinkedList::~LinkedList() {
}

int LinkedList::size() {

   int count = 0;
   Node* current = head;

   while(current != nullptr) {
      ++count;
      current = current->getNext();

   }

   return count;

}

//Get a pointer to the node at index provided
Node* LinkedList::get(int index) {
   int count = 0;
   Node* current = head;

   if (index >= 0 && index < size()) {
      while(count < index) {
         ++count;
         current = current->getNext();

      }
   }

return current;
}
