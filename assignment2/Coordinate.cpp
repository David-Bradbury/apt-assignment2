#include "Coordinate.h"
#include "Tile.h"

Coordinate::Coordinate(int row, int col) {
  this->rowCoordinate = row;
  this->colCoordinate = col;
  this->playedTile = nullptr;
}


Coordinate::~Coordinate() {
  delete this->playedTile; // LinkedList take care of this?
}


int Coordinate::getRowCoordinate() {
  return this->rowCoordinate;
}


int Coordinate::getColCoordinate() {
  return this->colCoordinate;
}


void Coordinate::setPlayedTile(Tile* tile) {
  this->playedTile = tile;
}


Tile* Coordinate::getPlayedTile() {
  return this->playedTile;
}