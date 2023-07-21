
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

   this->next = nullptr;
   this-> tile = new Tile(*other.tile);

}


