#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Coordinate.h"
#include <vector>

#define MAX_ROW 26
#define MAX_COL 26
#define ASCII 65

class Board {
public:

  Board();
  ~Board();

  void printBoard();

  Coordinate getNorth(Coordinate currentCoord); // maybe pass int row, int col instead.
  Coordinate getSouth(Coordinate currentCoord);
  Coordinate getEast(Coordinate currentCoord);
  Coordinate getWest(Coordinate currentCoord);

   bool boardPosEmpty(std::string location);
   Coordinate convertStringToCoord(std::string location);


private:

  std::vector<std::vector<Coordinate>> coordinates;

};

#endif // ASSIGN2_BOARD_H