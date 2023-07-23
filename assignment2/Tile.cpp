#include "Tile.h"

Tile::Tile(Shape shape, Colour colour) {

   this->shape = shape;
   this->colour = colour;

}

Tile::Tile(const Tile& other) {

   this->shape = other.shape;
   this->colour = other.colour;

}

Shape Tile::getShape() {

   return this->shape;
}

Colour Tile::getColour() {

   return this->colour;
}

bool Tile::isSameTile(Tile* other) {
   bool isSame = false;

   if (shape == other->getShape() && colour == other->getColour()) {
      isSame = true;

   }

   return isSame;
}

