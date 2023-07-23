#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

template <class T>
class Node {
public:

   Node(T data, Node<T>* next);
   ~Node();
   Node(const Node<T>& other);


   T data;
   Node<T>* next;
};

#endif // ASSIGN2_NODE_H
