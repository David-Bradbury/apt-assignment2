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


  // this->coordinates[13][13].setPlayedTile(new Tile(1, 'R'));
  // this->coordinates[12][13].setPlayedTile(new Tile(2, 'R'));
  // this->coordinates[11][13].setPlayedTile(new Tile(3, 'R'));
  // this->coordinates[10][13].setPlayedTile(new Tile(6, 'R'));
  // this->coordinates[14][13].setPlayedTile(new Tile(5, 'R'));

  // this->coordinates[8][13].setPlayedTile(new Tile(2, 'R'));
  // this->coordinates[7][13].setPlayedTile(new Tile(2, 'Y'));
  // this->coordinates[6][13].setPlayedTile(new Tile(2, 'B'));
  // this->coordinates[5][13].setPlayedTile(new Tile(2, 'G'));

  // this->coordinates[9][14].setPlayedTile(new Tile(4, 'R'));
  // this->coordinates[9][15].setPlayedTile(new Tile(4, 'Y'));
  // this->coordinates[9][12].setPlayedTile(new Tile(4, 'B'));

  // this->coordinates[6][14].setPlayedTile(new Tile(2, 'B'));

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

  LinkedList* ll = new LinkedList();
  bool doesNextTileExist = true;

  int oppositeRow = row;
  int oppositeCol = col;

  // Checks South/East depending on axis
  // first add 1 
  if (axis == "ns" && (row < MAX_ROW && row >= 0)) {
    row++;
  }
  else if (col < MAX_ROW && col >= 0) {
    col++;
  }


  while (doesNextTileExist && (row >= 0 && row < MAX_ROW) && (col >= 0 && col < MAX_COL)) {

    if (this->coordinates[row][col].getPlayedTile() != nullptr) {
      ll->addBack(this->coordinates[row][col].getPlayedTile());

      if (axis == "ns" && (row < MAX_ROW && row >= 0)) {
        row++;
      }
      else if (col < MAX_ROW && col >= 0) {
        col++;
      }
      if (col == MAX_COL || col == 0 || row == MAX_ROW || row == 0) {
        doesNextTileExist = false;
      }
    }
    else {
      doesNextTileExist = false;
    }
  }

  // Checks North/West depending on axis
  doesNextTileExist = true;

  if (axis == "ns" && (oppositeRow < MAX_ROW && oppositeRow > 0)) {
    oppositeRow--;
  }
  else if (oppositeCol < MAX_ROW && oppositeCol > 0) {
    oppositeCol--;
  }

  while (doesNextTileExist && (oppositeCol >= 0 && oppositeCol < MAX_COL) && (oppositeRow >= 0 && oppositeRow < MAX_ROW)) {

    if (this->coordinates[oppositeRow][oppositeCol].getPlayedTile() != nullptr) {
      ll->addBack(this->coordinates[oppositeRow][oppositeCol].getPlayedTile());

      if (axis == "ns" && (oppositeRow < MAX_ROW && oppositeRow > 0)) {
        oppositeRow--;
      }
      else if (oppositeCol < MAX_ROW && oppositeCol > 0) {
        oppositeCol--;
      }
      if (oppositeCol == MAX_COL || oppositeCol == 0 || oppositeRow == MAX_ROW || oppositeRow == 0) {
        doesNextTileExist = false;
      }
    }
    else {
      doesNextTileExist = false;
    }
  }

  return ll;
}

