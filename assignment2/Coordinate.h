#ifndef ASSIGN2_COORDINATE_H
#define ASSIGN2_COORDINATE_H

#include "Tile.h"

class Coordinate {
public:

  // Constructor/Destructor
  Coordinate(int row, int col);
  ~Coordinate();

  // getters
  int getRowCoordinate();
  int getColCoordinate();

  // setters
  void setPlayedTile(Tile* tile);
  Tile* getPlayedTile();


private:

  int rowCoordinate;
  int colCoordinate;
  Tile* playedTile;

};

#endif // ASSIGN2_COORDINATE_H