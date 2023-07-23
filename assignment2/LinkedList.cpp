#include "LinkedList.h"
#include <iostream>

template <class T>
LinkedList<T>::LinkedList() {

   this->head = nullptr;

}
template <class T>
LinkedList<T>::~LinkedList() {

   Node<T>* current = head;
   while (current != nullptr) {

      Node<T>* nextNode = current->next;
      delete current;

      current = nextNode;
   }
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {

   this->head = nullptr;
   Node<T>* current = other.head;
   Node<T>* previous = nullptr;

   //deep copy of list
   while (current != nullptr) {
      Node<T>* n = new Node<T>(new T(*current->T), nullptr);

      if (previous == nullptr) {
         this->head = n;

      }
      else {

         previous->next = n;
      }

      previous = n;
      current = current->next;
   }

}
template <class T>
int LinkedList<T>::size() const {

   int count = 0;
   Node<T>* current = head;

   while (current != nullptr) {
      ++count;
      current = current->next;

   }

   return count;

}
template <class T>
//Get a pointer to the node at index provided
Node<T>* LinkedList<T>::get(const int index) const {
   int count = 0;
   Node<T>* current = head;

   //used to return null if index provided is out of bounds   
   Node<T>* returnNode = nullptr;

   if (index >= 0 && index < size()) {
      while (count < index) {
         ++count;
         current = current->next;

      }
      returnNode = current;
   }

   return returnNode;
}

///*****WE MAY NOT NEED THIS ONE AND CAN BE DELETED IF WE DONT******
//Adds a node to the front of the list
template <class T>
void LinkedList<T>::addFront(T data) {

   Node<T>* toAdd = new Node<T>(data, nullptr);
   //check if list is empty and make toAdd the head if so
   if (head == nullptr) {
      head = toAdd;
   }
   else {
      toAdd->next = head;
      head = toAdd;
   }

}

template <class T>
//Adds a node with provided tile to the end of the list
void LinkedList<T>::addBack(T data) {
   //    Node<T>* toAdd = new Node<T>(data, nullptr);

   //    //If list is empty, make it the head
   //    if (head == nullptr) {
   //       head = toAdd;

   //    }
   //    else {

   //       Node<T>* current = head;
   //       while (current->next != nullptr) {
   //          current = current->next;

   //       }

   //       current->next = toAdd;
   //    }

   // }

   // template <class T>
   // //Delete a specified tile from the list
   // //N.B. This will only currently delete the first occurance of the provided tile
   // //it will not delete duplicates.
   // void LinkedList<T>::deleteTile(T data) {
   //    Node<T>* current = head;
   //    Node<T>* previousNode = nullptr;
   //    Node<T>* nodeToDelete = nullptr;

   //    if (head != nullptr && head->data->isSameTile(tileToDelete)) {
   //       nodeToDelete = head;
   //       head = head->next;

   //    }
   //    else {

   //       while (current != nullptr && nodeToDelete == nullptr) {
   //          if (current->tile->isSameTile(tileToDelete)) {
   //             nodeToDelete = current;
   //          }
   //          else {
   //             previousNode = current;
   //             current = current->next;
   //          }

   //       }

   //       if (nodeToDelete != nullptr) {
   //          if (current->next == nullptr) {
   //             previousNode->next = nullptr;
   //          }
   //          else {
   //             previousNode->next = current->next;
   //          }
   //       }
   //    }

   //    if (nodeToDelete != nullptr) {
   //       delete nodeToDelete;
   //    }


}
template <class T>
//return true if provided tile is in the list
bool LinkedList<T>::inList(T data) {

   bool tileInList = false;
   // Node<T>* current = head;

   // //Iterate to the end of the list
   // while (current != nullptr) {

   //    if (current->tile->isSameTile(tile)) {
   //       tileInList = true;
   //    }

   //    current = current->next;
   // }

   return tileInList;

}

