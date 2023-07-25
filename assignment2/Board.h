#ifndef BOARD
#define BOARD

#include "Coordinate.h"
#include <vector>

class Board {
public:

  Board();
  ~Board();

  void printBoard();


private:

  std::vector<std::vector<Coordinate>> coordinates;

};

#endif // BOARD