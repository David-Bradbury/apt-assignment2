
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
      current = current->next;

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
         current = current->next;

      }
   }

return current;
}

void LinkedList::addBack(Tile* tile) {
   Node* toAdd = new Node(tile, nullptr);

   if(head == nullptr) {
      head = toAdd;
   }
   Node* current = head;
   while(current->next != nullptr) {
      current = current->next;

   }

   current->next = toAdd;

}
