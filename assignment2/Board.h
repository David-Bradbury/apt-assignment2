#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Coordinate.h"
#include <vector>

class Board {
public:

  Board();
  ~Board();

  void printBoard();

  void checkNorth(Coordinate currentCoord);
  void checkSouth(Coordinate currentCoord);
  void checkEast(Coordinate currentCoord);
  void checkWest(Coordinate currentCoord);


private:

  std::vector<std::vector<Coordinate>> coordinates;

};

#endif // ASSIGN2_BOARD_H