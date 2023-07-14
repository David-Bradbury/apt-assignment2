
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:

   Tile(Shape shape, Colour colour);
   
   Shape getShape();
   Colour getColour();

private:
   Shape  shape;
   Colour colour;
   
};



#endif // ASSIGN2_TILE_H
