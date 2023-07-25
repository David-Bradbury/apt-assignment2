#include "Coordinate.h"
#include "Tile.h"

Coordinate::Coordinate(int y, int x) {
  this->yCoordinate = y;
  this->xCoordinate = x;
  this->playedTile = nullptr;
  hasPlayedTile = false;
}

Coordinate::~Coordinate() {
  delete this->playedTile;
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

void Coordinate::setHasPlayedTile(bool played) {
  this->hasPlayedTile = played;
}

bool Coordinate::getHasPlayedTile() {
  return this->hasPlayedTile;
}