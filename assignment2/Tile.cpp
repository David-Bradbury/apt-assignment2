
#include "Tile.h"

Tile::Tile (Shape shape, Colour colour) {
    
    this->shape = shape;
    this->colour = colour;

}

Shape Tile::getShape() {

   return this->shape;
}

Colour Tile::getColour() {

   return this->colour;
}
