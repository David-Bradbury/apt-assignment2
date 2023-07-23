#include "Node.h"

template <class T>
Node<T>::Node(T data, Node<T>* next) {

   // Colour colour = tile->getColour();
   // Shape shape = tile->getShape();

   this->next = next;
   this->data = data;
}
template <class T>
Node<T>::~Node() {

   delete this->generic;
}
template <class T>
Node<T>::Node(const Node& other) {

   this->next = nullptr;
   this->data = other.data;

}

