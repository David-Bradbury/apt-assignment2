#include "Coordinate.h"
#include "Tile.h"

Coordinate::Coordinate(int y, int x) {
  this->yCoordinate = y;
  this->xCoordinate = x;
  this->playedTile = nullptr;
}

Coordinate::~Coordinate() {
  delete this->playedTile; // LinkedList take care of this?
}

int Coordinate::getYCoordinate() {
  return this->yCoordinate;
}
int Coordinate::getXCoordinate() {
  return this->xCoordinate;
}

void Coordinate::setPlayedTile(Tile* tile) {
  this->playedTile = tile;
}

Tile* Coordinate::getPlayedTile() {
  return this->playedTile;
}