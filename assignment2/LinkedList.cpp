#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {

   this->head = nullptr;
   this->tail = nullptr;

}

LinkedList::~LinkedList() {

   Node* current = head;
   while (current != nullptr) {

      Node* nextNode = current->next;
      delete current;

      current = nextNode;
   }
}

LinkedList::LinkedList(const LinkedList& other) {

   this->head = nullptr;
   this->tail = nullptr;
   Node* current = other.head;
   Node* previous = nullptr;

   //deep copy of list
   while (current != nullptr) {
      Node* n = new Node(new Tile(*current->tile), nullptr, previous);

      if (previous == nullptr) {
         this->head = n;

      }
      else {

         previous->next = n;
      }

      previous = n;
      current = current->next;
   }

   tail = previous;

}

int LinkedList::size() const {

   int count = 0;

   Node* current = this->head;

   while (current != nullptr) {
      ++count;
      current = current->next;
   }

   return count;
}

//Get a pointer to the node at index provided
//Contract= the provided index needs to be within the size range of the list
Tile* LinkedList::get(const int index) const {
   int count = 0;
   Node* current = head;

   //used to return null if index provided is out of bounds   
   Node* returnNode = nullptr;

   if (index >= 0 && index < size()) {
      while (count < index) {
         ++count;
         current = current->next;

      }
      returnNode = current;
   }

   return returnNode->tile;
}

///*****WE MAY NOT NEED THIS ONE AND CAN BE DELETED IF WE DONT******
//Adds a node to the front of the list
void LinkedList::addFront(Tile* tile) {

   Node* toAdd = new Node(tile, head, nullptr);
   //check if list is empty and make toAdd the head if so
   if (head != nullptr) {
      head->previous = toAdd;
   }
   else {
      tail = toAdd;

   }
   head = toAdd;

}


//Adds a node with provided tile to the end of the list
void LinkedList::addBack(Tile* tile) {
   Node* toAdd = new Node(tile, nullptr, tail);

   if (tail != nullptr) {
      tail->next = toAdd;

   }
   else {
      //if list is empty, set the head as the new node;
      head = toAdd;
   }
   tail = toAdd;

}


//Remove a specified tile from the list
//N.B. This will only currently delete the first occurance of the provided tile
//it will not delete duplicates.
void LinkedList::removeTile(Tile* tileToDelete) {
   Node* current = head;
   bool successful = false;

   while (current != nullptr && !successful) {

      if (current->tile->isSameTile(tileToDelete)) {
         if (current->previous != nullptr) {
            //set the pointers to skip node
            current->previous->next = current->next;
         }
         else {
            //node is the current head
            head = current->next;
         }

         if (current->next != nullptr) {
            current->next->previous = current->previous;
         }
         else {
            tail = current->previous;
         }

         successful = true;
      }
      current = current->next;

   }
   if (!successful) {
      std::cout << "Tile was not found in the list" << std::endl;
   }



}

//return true if provided tile is in the list
bool LinkedList::tileInList(Tile* tile) {

   bool tileInList = false;
   Node* current = head;

   //Iterate to the end of the list
   while (current != nullptr) {

      if (current->tile->isSameTile(tile)) {
         tileInList = true;
      }

      current = current->next;
   }

   return tileInList;

}

void LinkedList::removeEnd() {

   if (tail == nullptr) {
      std::cout << "There is nothing to delete (list is empty)." << std::endl;

   }
   else if (head == tail) {

      delete tail;
      head = nullptr;
      tail = nullptr;

   }
   else {

      Node* previousToTail = tail->previous;
      previousToTail->next = nullptr;
      delete tail;
      tail = previousToTail;

   }

}

void LinkedList::deleteFront() {

   if (this->head == nullptr) {
      std::cout << "No front element to remove" << std::endl;
   }
   else if (this->head->next == nullptr) {
      Node* temp = this->head;
      this->head = nullptr;

      delete temp;
   }
   else {
      Node* temp = this->head;
      this->head = this->head->next;

      delete temp;
   }
}