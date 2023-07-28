#ifndef ASSIGN2_COORDINATE_H
#define ASSIGN2_COORDINATE_H

#include "Tile.h"

class Coordinate {
public:

  Coordinate(int row, int col);
  ~Coordinate();

  int getRowCoordinate();
  int getColCoordinate();
  void setPlayedTile(Tile* tile);
  Tile* getPlayedTile();


private:
  int rowCoordinate;
  int colCoordinate;
  Tile* playedTile;

};

#endif // ASSIGN2_COORDINATE_H