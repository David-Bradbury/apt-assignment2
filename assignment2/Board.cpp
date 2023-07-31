#include "Board.h"
#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include "Coordinate.h"

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

  // this->coordinates[16][16].setPlayedTile(new Tile(4, 'R'));
  // this->coordinates[15][16].setPlayedTile(new Tile(3, 'R'));
  // this->coordinates[14][16].setPlayedTile(new Tile(2, 'R'));
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
//need to add more checks
// bool Board::boardPosEmpty(std::string location) {
//     bool isEmpty = false;
//       Coordinate* position = convertStringToCoord(location); 

//     if(position->getPlayedTile() == nullptr) {
//         isEmpty = true;
//     }
//     return isEmpty;
//  }

// Coordinate* Board::convertStringToCoord(std::string location) {

//     Coordinate* coord = nullptr;
//     if(location.length() == 2) {
//         int row = location[0] - ASCII; 
//         int col = location[1] - 1;

//       //  cooord = new Coordinate(row, col);
//     } else {
//         std::cerr << "location length is invalid" << std::endl;
//     }
//     return coord;
// }

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

void Board::setTile(int row, int col, Tile* tile)
{
  this->coordinates[row][col].setPlayedTile(tile);
}

std::vector < std::vector<Coordinate>> Board::getCoordinates()
{
  return this->coordinates;
}

