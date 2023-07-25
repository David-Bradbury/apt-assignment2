#include "Board.h"
#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Node.h"
#include "Node.cpp"
#include "Tile.h"
#include "Coordinate.h"

Board::Board() {

  std::vector<Coordinate> temp;

  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      temp.push_back(Coordinate(i, j));
    }
    this->coordinates.push_back(temp);
    temp.clear();
  }

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
      if (this->coordinates[i][j].getHasPlayedTile())
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

