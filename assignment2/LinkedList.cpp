
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
   
   this-> head = nullptr;
   
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

   //used to return null if index provided is out of bounds   
   Node* returnNode = nullptr;

   if (index >= 0 && index < size()) {
      while(count < index) {
         ++count;
         current = current->next;

      }
      returnNode = current;
   }

return returnNode;
}

void LinkedList::addFront(Tile* tile) {

   Node* toAdd = new Node(tile, nullptr);
   //check if list is empty and make toAdd the head if so
   if (head == nullptr) {
      head = toAdd;
   } else {
      toAdd->next = head;
      head = toAdd; 
   }

}

//Adds a node with provided tile to the end of the list
void LinkedList::addBack(Tile* tile) {
   Node* toAdd = new Node(tile, nullptr);

   //If list is empty, make it the head
   if(head == nullptr) {
      head = toAdd;

   } else {

      Node* current = head;
      while(current->next != nullptr) {
         current = current->next;

      }

      current->next = toAdd;
   }

}