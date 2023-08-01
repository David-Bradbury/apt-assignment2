#include "Board.h"
#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include "Coordinate.h"
#include <string>

Board::Board(int rows, int cols) {

  std::vector<Coordinate> temp;
  this->rows = rows;
  this->cols = cols;

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
  this->coordinates[14][13].setPlayedTile(new Tile(5, 'R'));

  this->coordinates[8][13].setPlayedTile(new Tile(2, 'R'));
  this->coordinates[7][13].setPlayedTile(new Tile(2, 'Y'));
  this->coordinates[6][13].setPlayedTile(new Tile(2, 'B'));
  this->coordinates[5][13].setPlayedTile(new Tile(2, 'G'));

  this->coordinates[9][14].setPlayedTile(new Tile(4, 'R'));
  this->coordinates[9][15].setPlayedTile(new Tile(4, 'Y'));
  this->coordinates[9][12].setPlayedTile(new Tile(4, 'B'));

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


void Board::setTile(int row, int col, Tile* tile) {
  this->coordinates[row][col].setPlayedTile(tile);
}


LinkedList* Board::getTileList(int row, int col, std::string axis) {

  bool doesNextTileExist = true;
  int row2 = row;
  int col2 = col;
  // first add 1 
  if (axis == "col") {
    row++;
  }
  else {
    col++;
  }

  LinkedList* ll = new LinkedList();

  while (doesNextTileExist) {

    if (this->coordinates[row][col].getPlayedTile() != nullptr) {
      ll->addBack(this->coordinates[row][col].getPlayedTile());

      if (axis == "col") {
        row++;
      }
      else {
        col++;
      }
    }
    else {
      doesNextTileExist = false;
    }
  }
  doesNextTileExist = true;

  if (axis == "col") {
    row2--;
  }
  else {
    col2--;
  }

  while (doesNextTileExist) {

    if (this->coordinates[row2][col2].getPlayedTile() != nullptr) {
      ll->addBack(this->coordinates[row2][col2].getPlayedTile());

      if (axis == "col") {
        row2 = row2 - 1;
      }
      else {
        col2 = col2 - 1;
      }
    }

    else {
      doesNextTileExist = false;
    }
  }
  return ll;
}

