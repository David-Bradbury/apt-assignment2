#ifndef COORDINATE
#define COORDINATE

#include "Tile.h"

class Coordinate {
public:

  Coordinate(int y, int x);
  ~Coordinate();

  int getYCoordinate();
  int getXCoordinate();
  void setPlayedTile(Tile* tile);
  Tile* getPlayedTile();
  void setHasPlayedTile(bool played);
  bool getHasPlayedTile();


private:
  int yCoordinate;
  int xCoordinate;
  Tile* playedTile;
  bool hasPlayedTile;

};

#endif // COORDINATE