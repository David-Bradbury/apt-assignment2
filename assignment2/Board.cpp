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

  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      temp.push_back(Coordinate(i, j));
    }
    this->coordinates.push_back(temp);
    temp.clear();
  }

  this->coordinates[16][16].setPlayedTile(new Tile(4, 'R'));
  this->coordinates[15][16].setPlayedTile(new Tile(3, 'R'));
  this->coordinates[14][16].setPlayedTile(new Tile(2, 'R'));
  // this->coordinates[16][16].setHasPlayedTile(true);

}

Board::~Board() {
  // Delete

}

void Board::printBoard() {
  // Prints the numbers across the top of the board
  for (int i = 0; i < 27; i++)
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
  for (int i = 1; i < 26; i++)
  {
    std::cout << "----";
  }
  std::cout << std::endl;

  char y = 'A';
  // Prints the board
  for (int i = 0; i < 26; i++)
  {
    // Prints the char on the left side of the board
    std::cout << y << "  |";
    y++;

    // Prints the board
    for (int j = 0; j < 26; j++)
    {
      if (this->coordinates[i][j].getHasPlayedTile()) // Can we maybe instead of using a bool, we check for null? (get rid of bool variable)
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

