#ifndef ASSIGN2_GAMECONTROLLER_H
#define ASSIGN2_GAMECONTROLLER_H

#include "Coordinate.h"
#include "LinkedList.h"
#include "Board.h"
#include "Player.h"
#include <vector>
#include <string>

#define MAX_TILES   72
#define MAX_TILE_OCCURENCES 2

class GameController {
public:

  GameController(std::string player1, std::string player2);
  ~GameController();

  void startGame();
  void endGame();
  void quit();
  void saveGame(std::string fileName, std::string data);

  void createTileBag();
  int generateRandomInt(int min, int max);
  // This method is called when starting a new game and sets up the hands for the players involved in the game. When setting up the hands 
  // Players take turns drawing from the tilebag one at a time until they have full hands (like dealing cards).
  void setupHands();

  void takeInput();
  void placeTile(Tile* tile, char row, int col);
  void replaceTile(Tile* tile);

  void scoreTurn();




private:

  LinkedList* tileBag;
  LinkedList* playedTiles;
  Player* player1;
  Player* player2;
  Board* board;
  int turnID;




};

#endif // ASSIGN2_GAMECONTROLLER_H