#include "Board.h"
#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include "Coordinate.h"

Board::Board() {

  std::vector<Coordinate> temp;

  for (int i = 0; i < MAX_ROW; i++)
  {
    for (int j = 0; j < MAX_COL; j++)
    {
      temp.push_back(Coordinate(i, j));
    }
    this->coordinates.push_back(temp);
    temp.clear();
  }


  this->coordinates[16][16].setPlayedTile(new Tile(4, 'R'));

  this->coordinates[15][16].setPlayedTile(new Tile(2, 'R'));

  this->coordinates[14][16].setPlayedTile(new Tile(6, 'R'));

  this->coordinates[13][16].setPlayedTile(new Tile(1, 'R'));

  this->coordinates[16][17].setPlayedTile(new Tile(4, 'Y'));

  this->coordinates[16][15].setPlayedTile(new Tile(4, 'B'));



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

bool Board::boardPosEmpty(std::string location) {
      Coordinate position = convertStringToCoord(location); 
 }

Coordinate board::convertStringToCoord(std::string location) {
    if(location.length() == 2) {
        int row = location[0] - 65; // fix magic numbers
        int col = location[1];
        
        
    }
}
