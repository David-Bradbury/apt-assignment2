#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Coordinate.h"
#include "LinkedList.h"
#include <vector>
#include <string>

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

  // LinkedList* getNorthTiles(int row, int col);
  // LinkedList* getSouthTiles(int row, int col);
  // LinkedList* getEastTiles(int row, int col);
  // LinkedList* getWestTiles(int row, int col);

  LinkedList* getTileList(int row, int col, int direction, std::string axis);

  void setTile(int row, int col, Tile* tile);


private:

  std::vector<std::vector<Coordinate>> coordinates;
  int rows;
  int cols;

};

#endif // ASSIGN2_BOARD_H