#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Coordinate.h"
#include <vector>

#define MAX_ROW 26;
#define MAX_COL 26;

class Board {
public:

  Board();
  ~Board();

  void printBoard();

  void setRows(int row);
  void setCols(int col);
  int getRows();
  int getCols();
  std::vector < std::vector<Coordinate>> getCoordinates();

  void checkNorth(Coordinate currentCoord);
  void checkSouth(Coordinate currentCoord);
  void checkEast(Coordinate currentCoord);
  void checkWest(Coordinate currentCoord);


private:

  std::vector<std::vector<Coordinate>> coordinates;
  int rows;
  int cols;

};

#endif // ASSIGN2_BOARD_H