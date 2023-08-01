#ifndef ASSIGN2_GAMECONTROLLER_H
#define ASSIGN2_GAMECONTROLLER_H

#include "Coordinate.h"
#include "LinkedList.h"
#include "Board.h"
#include "Player.h"
#include <vector>
#include <string>

#define MAX_TILES   72
#define START_GAME_TILEBAG_LENGTH 60
#define MAX_TILE_OCCURENCES 2
#define PLACED_TILE_MAX_LENGTH 6
#define QWIRKLE 6

enum turn {

  PLAYER_1 = 1,
  PLAYER_2 = 2
};

class GameController {
public:

  GameController(std::string player1, std::string player2);
  GameController(Player player1, Player player2, Board* board, LinkedList* tileBag);
  ~GameController();

  void prepareGame();
  void endGame();
  void quit();
  void saveGame(std::string fileName);

  void createTileBag();
  int generateRandomInt(int min, int max);
  // This method is called when starting a new game and sets up the hands for the players involved in the game. When setting up the hands 
  // Players take turns drawing from the tilebag one at a time until they have full hands (like dealing cards).
  void setupHands();

  bool equalsIgnoreCase(std::string string1, std::string string2);
  void takeInput();

  void printTurn();
  bool placeTile(std::string tileCode, std::string location);
  bool replaceTile(std::string tileCode);


  int scoreTurn(std::string tileCode, std::string location);
  int calculateScore(LinkedList* ll);
  void setCurrPlayer(Player* player);
  void changeCurrPlayer();

  void playGame();

  // Checks that the string passed, follows the rules of the qwirkle tiles, given in Tilecodes.h.
  // Returns custom error messages if not.
  bool checkValidTileCode(std::string tileCode);

  // Checks that the string passed, is a valid coordinate location on the board.
  // Returns custom error messages if not.
  bool checkValidCoordinate(std::string coor);

  // Convert a tileCode to a tile for various functions within the game. Programming by contract as it is assumed
  // the tileCode has been checked with the checkValidTileCode function declared above.
  Tile* convertToTile(std::string tileCode);

  bool checkValidMove(LinkedList* ll, Tile* tile);
  bool checkMatchColour(Tile* tileToPlace, Tile* existingTile);
  bool checkMatchShape(Tile* tileToPlace, Tile* existingTile);





private:

  LinkedList* tileBag;
  LinkedList* playedTiles;
  Player* player1;
  Player* player2;
  Board* board;
  Player* currPlayer;

};

#endif // ASSIGN2_GAMECONTROLLER_H