#include "Board.h"
#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include "Coordinate.h"
#include <string>

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

  this->coordinates[13][13].setPlayedTile(new Tile(1, 'R'));
  this->coordinates[12][13].setPlayedTile(new Tile(2, 'R'));
  this->coordinates[11][13].setPlayedTile(new Tile(3, 'R'));
  this->coordinates[10][13].setPlayedTile(new Tile(6, 'R'));

  this->coordinates[8][13].setPlayedTile(new Tile(4, 'R'));
  this->coordinates[7][13].setPlayedTile(new Tile(4, 'Y'));
  this->coordinates[6][13].setPlayedTile(new Tile(4, 'B'));
  this->coordinates[5][13].setPlayedTile(new Tile(4, 'G'));
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

// LinkedList* Board::getNorthTiles(int row, int col) {

//   bool doesNorthTileExist = true;

//   int northRow = row - 1;
//   LinkedList* northLL = nullptr;

//   while (doesNorthTileExist) {

//     if (this->coordinates[northRow][col].getPlayedTile() != nullptr) {
//       northLL->addBack(this->coordinates[northRow][col].getPlayedTile());
//       northRow--;
//     }
//     else {
//       doesNorthTileExist = false;
//     }
//   }
//   return northLL;
// }


// Add comment about linkedlist ownership tranferring to calling function.
LinkedList* Board::getTileList(int row, int col, int direction, std::string axis) {

  bool doesNextTileExist = true;

  if (axis == "row") {
    row = row + direction;
  }
  else {
    col = col + direction;
  }

  LinkedList* ll = new LinkedList();

  while (doesNextTileExist) {

    if (this->coordinates[row][col].getPlayedTile() != nullptr) {
      ll->addBack(this->coordinates[row][col].getPlayedTile());

      if (axis == "row") {
        row = row + direction;
      }
      else {
        col = col + direction;
      }
    }
    else {
      doesNextTileExist = false;
    }
  }
  return ll;
}

void Board::setTile(int row, int col, Tile* tile) {
  this->coordinates[row][col].setPlayedTile(tile);
}
