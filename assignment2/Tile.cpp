#include "Tile.h"

Tile::Tile(Shape shape, Colour colour) {

   this->shape = shape;
   this->colour = colour;

}

// Ensure shape and colour are seperate variables.
bool Tile::isSameTile(Tile* other) {

   bool isSame = false;

   if (shape == other->getShape() && colour == other->getColour()) {
      isSame = true;
   }
   return isSame;
}

// Getter for shape.
Shape Tile::getShape() {
   return this->shape;
}

// Getter for colour.
Colour Tile::getColour() {
   return this->colour;
}



