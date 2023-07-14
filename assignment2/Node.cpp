
#include "Node.h"

Node::Node(Tile* tile, Node* next) {

   Colour colour = tile->getColour();
   Shape shape = tile->getShape();

   this->next = next;
   this->tile =  new Tile(shape, colour);
}

Node::~Node() {

   delete this->tile;
}

Node::Node(const Node& other) {

   this->next = other.next;
   this-> tile = new Tile(*other.tile);

}

Node* Node::getNext() {
   return this->next;
}
