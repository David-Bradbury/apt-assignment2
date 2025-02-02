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

  // Instantiates the private coordinates vector variable  
  for (int i = 0; i < MAX_ROW; i++) {

    for (int j = 0; j < MAX_COL; j++) {

      temp.push_back(Coordinate(i, j));
    }

    this->coordinates.push_back(temp);
    temp.clear();
  }
}


Board::~Board() {
  // Nothing to delete

}

Board::Board(const Board& other) {
  this->rows = other.rows;
  this->cols = other.cols;
  this->coordinates = other.coordinates;
}


void Board::printBoard() {

  // Prints the numbers across the top of the board
  for (int i = 0; i <= MAX_COL; i++) {

    if (i > 0 && i < 11) {

      std::cout << " " << i << " ";
    }
    else if (i > 10) {

      std::cout << i << " ";
    }
    else {

      std::cout << "   ";
    }
  }

  std::cout << std::endl;

  // Prints the line under the numbers at the top of the board
  for (int i = 1; i < MAX_COL; i++) {

    if (i % 3 == 0) {

      std::cout << "----";
    }
    else {

      std::cout << "---";
    }
  }

  std::cout << std::endl;

  char y = 'A';
  // Prints the board
  for (int i = 0; i < MAX_ROW; i++) {
    // Prints the char on the left side of the board
    std::cout << y << "  |";
    y++;

    // Prints the board
    for (int j = 0; j < MAX_COL; j++) {
      // Prints tile if a tile has been played
      if (this->coordinates[i][j].getPlayedTile() != nullptr) {
        std::cout << "" << this->coordinates[i][j].getPlayedTile()->getColour() << this->coordinates[i][j].getPlayedTile()->getShape();
      }
      else {
        std::cout << "  ";
      }
      std::cout << "|";
    }
    std::cout << std::endl;
  }
}

// Checks if board position has a tile played and returns a boolean result.
bool Board::isBoardPositionEmpty(int row, int col) {

  bool isEmpty = false;

  if (coordinates[row][col].getPlayedTile() == nullptr) {
    isEmpty = true;
  }

  return isEmpty;
}


LinkedList* Board::getTileList(int row, int col, std::string axis) {

  LinkedList* tileList = new LinkedList();

  bool doesNextTileExist = true;
  int oppositeRow = row;
  int oppositeCol = col;

  // Checks South/East depending on axis
  // first add 1
  if (axis == "ns" && (row < MAX_ROW && row >= 0)) {
    row++;
  }
  else if (axis == "ew" && col < MAX_ROW && col >= 0) {
    col++;
  }

  // loop until coordinates will not return a tile. Also doing out of bounds checking.
  while (doesNextTileExist && (row >= 0 && row < MAX_ROW) && (col >= 0 && col < MAX_COL)) {

    if (this->coordinates[row][col].getPlayedTile() != nullptr) {
      tileList->addBack(this->coordinates[row][col].getPlayedTile());

      if (axis == "ns" && (row < MAX_ROW && row >= 0)) {
        row++;
      }
      else if (axis == "ew" && col < MAX_ROW && col >= 0) {
        col++;
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
  else if (axis == "ew" && oppositeCol < MAX_ROW && oppositeCol > 0) {
    oppositeCol--;
  }

  // Same as previous while loop, just in the opposite direction.
  while (doesNextTileExist && (oppositeCol >= 0 && oppositeCol < MAX_COL) && (oppositeRow >= 0 && oppositeRow < MAX_ROW)) {

    if (this->coordinates[oppositeRow][oppositeCol].getPlayedTile() != nullptr) {
      tileList->addBack(this->coordinates[oppositeRow][oppositeCol].getPlayedTile());

      if (axis == "ns" && (oppositeRow < MAX_ROW && oppositeRow >= 0)) {
        oppositeRow--;

        if (oppositeRow < 0) {
          doesNextTileExist = false;
        }
      }
      else if (axis == "ew" && oppositeCol < MAX_ROW && oppositeCol >= 0) {
        oppositeCol--;

        if (oppositeCol < 0) {
          doesNextTileExist = false;
        }
      }
    }
    else {
      doesNextTileExist = false;
    }
  }
  return tileList;
}


std::string Board::getCoordinatesAsString() {

  std::string saveData;

  for (unsigned int i = 0; i < this->coordinates.size(); i++) {
    for (unsigned int j = 0; j < this->coordinates[i].size(); j++) {
      if (this->coordinates[i][j].getPlayedTile() != nullptr) {

        saveData += this->coordinates[i][j].getPlayedTile()->getColour();
        saveData += std::to_string(this->coordinates[i][j].getPlayedTile()->getShape());
        saveData += '@';
        saveData += char(this->coordinates[i][j].getRowCoordinate() + ASCII);
        saveData += std::to_string(this->coordinates[i][j].getColCoordinate() + 1);
        saveData += ',';
      }
    }
  }

  // Remove trailing ','
  saveData.resize(saveData.length() - 1);
  return saveData;
}





int Board::getRows() {
  return this->rows;
}


int Board::getCols() {
  return this->cols;
}


void Board::setTile(int row, int col, Tile* tile) {
  this->coordinates[row][col].setPlayedTile(tile);
}


void Board::setRows(int row) {
  this->rows = row;
}


void Board::setCols(int col) {
  this->cols = col;
}
