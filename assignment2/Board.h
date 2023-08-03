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

  // Contructor / Destructor
  Board(int rows, int cols);
  ~Board();

  // Prints the board out to terminal.
  void printBoard();

  // This function is programming by contract. It is assumed that the caller of this function has
  // guaranteed that row and col fields passed amount to a valid coordinate.
  bool isBoardPositionEmpty(int row, int col);

  // Returns a linked list of tiles, that are connected to the position and row/col. Contract 
  // programming. It is assumed the row and col passed to this function are within th bounds of the
  // board coordinates.
  LinkedList* getTileList(int row, int col, std::string axis);

  // getters
  std::vector < std::vector<Coordinate>> getCoordinates();
  int getRows();
  int getCols();

  // setters
  void setTile(int row, int col, Tile* tile);
  void setRows(int row);
  void setCols(int col);


private:

  std::vector<std::vector<Coordinate>> coordinates;
  int rows;
  int cols;

};

#endif // ASSIGN2_BOARD_H