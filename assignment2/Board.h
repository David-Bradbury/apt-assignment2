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

  // bool boardPosEmpty(std::string location);
  // Coordinate convertStringToCoord(std::string location);

  void setRows(int row);
  void setCols(int col);
  int getRows();
  int getCols();
  std::vector < std::vector<Coordinate>> getCoordinates();

  void checkNorth(Coordinate currentCoord);// maybe pass int row, int col instead.
  void checkSouth(Coordinate currentCoord);
  void checkEast(Coordinate currentCoord);
  void checkWest(Coordinate currentCoord);



private:

  std::vector<std::vector<Coordinate>> coordinates;
  int rows;
  int cols;

};

#endif // ASSIGN2_BOARD_H