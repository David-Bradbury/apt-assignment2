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

  //   // UNCOMMENT TO TEST GENERICS IN LINKEDLIST
  // LinkedList<Tile> test;
  // Tile te = Tile(4, 'Y');
  // test.addFront(te);
  // LinkedList<Tile> test = LinkedList<Tile>();
  // LinkedList<int> test;
  // std::cout << test.get(0);

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

  this->coordinates[25][18].setPlayedTile(new Tile(3, 'O'));
  this->coordinates[25][18].setHasPlayedTile(true);

  this->coordinates[24][18].setPlayedTile(new Tile(2, 'O'));
  this->coordinates[24][18].setHasPlayedTile(true);
  // int boardSize = this->coordinates.size();
  // for (int i = 0; i < boardSize; i++)
  // {
  //   for (int j = 0; j < boardSize; j++)
  //   {
  //     std::cout << "y" << this->coordinates[i][j].getYCoordinate() << " x" << this->coordinates[i][j].getXCoordinate() << " Tile " << this->coordinates[i][j].getPlayedTile() << std::endl;
  //   }
  // }
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
      // if (this->coordinates[i][j].getHasPlayedTile())
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

// // void Board::setTile(Tile tile, std::string location) {

// }