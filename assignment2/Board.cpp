#include "Board.h"
#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include "Coordinate.h"

Board::Board() {

  std::vector<Coordinate> temp;
  this->rows = MAX_ROW;
  this->cols = MAX_COL;

  for (int i = 0; i < MAX_ROW; i++)
  {
    for (int j = 0; j < MAX_COL; j++)
    {
      temp.push_back(Coordinate(i, j));
    }
    this->coordinates.push_back(temp);
    temp.clear();
  }

  this->coordinates[13][13].setPlayedTile(new Tile(4, 'R'));
}

Board::~Board() {
  // Delete

}

void Board::printBoard() {
  // Prints the numbers across the top of the board
  for (int i = 0; i <= MAX_COL; i++)
  {
    if (i > 0 && i < 11)
    {
      std::cout << " " << i << " ";
    }
    else if (i > 10)
    {
      std::cout << i << " ";
    }
    else
    {
      std::cout << "   ";
    }
  }

  std::cout << std::endl;
  // Prints the line under the numbers at the top of the board
  for (int i = 1; i < MAX_COL; i++)
  {
    if (i % 3 == 0) {
      std::cout << "----";
    }
    else
      std::cout << "---";
  }
  std::cout << std::endl;

  char y = 'A';
  // Prints the board
  for (int i = 0; i < MAX_ROW; i++)
  {
    // Prints the char on the left side of the board
    std::cout << y << "  |";
    y++;

    // Prints the board
    for (int j = 0; j < MAX_COL; j++)
    {

      if (this->coordinates[i][j].getPlayedTile() != nullptr)
      {
        std::cout << "" << this->coordinates[i][j].getPlayedTile()->getColour() << this->coordinates[i][j].getPlayedTile()->getShape();
      }
      else
      {
        std::cout << "  ";
      }
      std::cout << "|";

    }

    std::cout << std::endl;
  }
}

void Board::setRows(int row) {
  this->rows = row;
}

void Board::setCols(int col) {
  this->cols = col;
}

int Board::getRows() {
  return this->rows;
}

int Board::getCols() {
  return this->cols;
}

std::vector < std::vector<Coordinate>> Board::getCoordinates()
{
  return this->coordinates;
}


bool Board::isBoardPositionEmpty(int row, int col) {

  bool isEmpty = false;

  if (coordinates[row][col].getPlayedTile() == nullptr) {
    isEmpty = true;
  }

  return isEmpty;
}

// LinkedList* Board::checkNorth(char row, int col, ) {

/*
  bool doesNorthTileExist = true;
  int northRow = row - 1;

  LinkedList* northLL = nullptr;

  while (doesNorthTileExist) {

    if (coordinates[northRow][col].getPlayedTile() != nullptr) {
      northLL.AddBack(coordinates[northRow][col].getPlayedTile());
      northRow--;
    }
    else {
      doesNorthTileExist = false;
    }
  }
  return northLL;
*/
// }

