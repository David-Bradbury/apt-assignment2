#ifndef ASSIGN2_COORDINATE_H
#define ASSIGN2_COORDINATE_H

#include "Tile.h"

class Coordinate {
public:

  Coordinate(int y, int x);
  ~Coordinate();

  int getYCoordinate();
  int getXCoordinate();
  void setPlayedTile(Tile* tile);
  Tile* getPlayedTile();


private:
  int yCoordinate;
  int xCoordinate;
  Tile* playedTile;

};

#endif // ASSIGN2_COORDINATE_H