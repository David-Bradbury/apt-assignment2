
#include "Node.h"

Node::Node(Tile* tile, Node* next) {
   
   this->next = next;
   this->tile = tile;
}

Node::Node(Node& other) {
   this->next = other.next;

}
