#ifndef BOARD
#define BOARD

#include "Tile.h"
#include <vector>

class Board {
public:

  Board();
  ~Board();

  //Print Board
  void printBoard();
  //Sets Tile in board
  // void setTile(Tile tile, std::string location);

private:
  std::vector<std::vector<Tile>> playedTiles;

};

#endif // BOARD