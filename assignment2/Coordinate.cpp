#include "Coordinate.h"
#include "Tile.h"

//Establishing key variables to be reference on the board.
Coordinate::Coordinate(int row, int col) {
  this->rowCoordinate = row;
  this->colCoordinate = col;
  this->playedTile = nullptr;
}


Coordinate::~Coordinate() {
  delete this->playedTile; // LinkedList take care of this?
}

// Gets row co-ordinate.
int Coordinate::getRowCoordinate() {
  return this->rowCoordinate;
}

// Gets column co-ordinate.
int Coordinate::getColCoordinate() {
  return this->colCoordinate;
}

// Identifies played tile.
void Coordinate::setPlayedTile(Tile* tile) {
  this->playedTile = tile;
}

// Returns played tile.
Tile* Coordinate::getPlayedTile() {
  return this->playedTile;
}

