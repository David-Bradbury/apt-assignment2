#include "Board.h"
#include <iostream>
#include <vector>
// #include "Tile.h"

Board::Board() {
  // We need anything? 
  // this->board = new std::vector<std::vector<Tile>>;

  std::vector<Tile> temp;

  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      if (j % 2 == 0)
      {
        temp.push_back(Tile(2, 'R'));
      }
      else
      {
        temp.push_back(Tile(3, 'O'));
      }
    }
    this->board.push_back(temp);
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

  // std::string tempTile = "";
  bool tile = false;
  char y = 'A';
  // Prints the board
  for (int i = 0; i < 26; i++)
  {
    // Prints the char on the left side of the board
    std::cout << y << "  |";
    y++;

    // this->board[1][1] = Tile(2, 'R');

    // Prints the board
    for (int j = 0; j < 26; j++)
    {
      if (!this->board.empty() && this->board[i][j].getShape() > 0)
      {
        tile = true;
      }
      if (j < 10)
      {
        if (tile)
        {
          std::cout << this->board[i][j].getColour() << this->board[i][j].getShape();
        }
        else
        {
          std::cout << "  ";
        }
      }
      else
      {
        if (tile)
        {
          std::cout << "" << this->board[i][j].getColour() << this->board[i][j].getShape();
        }
        else
        {
          std::cout << "  ";
        }
      }
      std::cout << "|";
      tile = false;
      // tempTile = "";
    }
    std::cout << std::endl;
  }
}

void Board::setTile() {

}