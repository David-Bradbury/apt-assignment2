#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Coordinate.h"
#include <vector>

#define MAX_ROW 26
#define MIN_COL 1
#define MAX_COL 26
#define ASCII 65


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

  // This function is programming by contract. It is assumed that the caller of this function has
  // guaranteed that row and col fields passed amount to a valid coordinate.
  bool isBoardPositionEmpty(int row, int col);

  void checkNorth(int row, int col);// maybe pass int row, int col instead.
  void checkSouth(Coordinate currentCoord);
  void checkEast(Coordinate currentCoord);
  void checkWest(Coordinate currentCoord);



private:

  std::vector<std::vector<Coordinate>> coordinates;
  int rows;
  int cols;

};

#endif // ASSIGN2_BOARD_H