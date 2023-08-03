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

  // Constructors / Destructors
  GameController(std::string player1, std::string player2);
  // Overloaded Constructor for loading game.
  GameController(Player player1, Player player2, Board* board, LinkedList* tileBag);
  ~GameController();

  // The function that prepares the game by creating the tilebag, dealing the player
  // hands, sets the current player and calls the gameplay loop.
  void prepareGame();

  // Creates a tileBag of tiles for the game, of shapes and colours. There are 2 instances of each
  // combination of tile shape and colours for a total of 72 tiles. They are also created in a 
  //  random order.
  void createTileBag();

  // This method is called when starting a new game and sets up the hands for the players 
  // involved in the game. When setting up the hands, Players take turns drawing from the tilebag
  // one at a time until they have full hands (like dealing cards). Programming by contract, will 
  // not work without 2 players initiated and a tilebag with 12 or more tiles.
  void setupHands();

  // Function where the gameplay loop is called until the end of a game. There must be defined 
  // players and a tilebag for this function to work.
  void playGame();

  // Prints all the information need for a player to make a turn. 
  void printTurn();

  // Function where players input are taken and and handled. If it is a valid command passes over
  // to relevant function.
  void takeInput();

  // Takes a tilecode and if it is in the players hand, replaces the tile with the next tile in
  // the tilebag. The contract part of the this function is that a valid tilecode has been passed.
  // To determine if a tilecode is valid, use the checkValidTileCode function.
  bool replaceTile(std::string tileCode);

  // Makes a serious of checks (based on the game rules) and if it passes all of them, it places
  // a tile on the board. Returns a boolean which is used to see whether input needs to be taken
  // again before the end of the turn. Contract is that tileCode and location need to be 
  // independantly validated before using in this function.
  bool placeTile(std::string tileCode, std::string location);

  // More checks to ensure move is valid, called by the placeTile function multiple times for both
  // the northSouth and eastWest linkedlists. Checks for duplicate tiles, the max length, and that 
  // the tile rules are followed before returning whether a tile can be placed. 
  bool checkValidMove(LinkedList* ll, Tile* tile);

  // Sets up the string which is used to save the game, using the IOStream class.
  void saveGame(std::string fileName);

  // Scores the turn of a player after making a turn. To do so it uses the two lists of tiles 
  // adjacent to the placed tile. It does not actually add to the score but calls another 
  // method which does.
  // The contract involved assumes that a valid move has been played, and that this method can
  // not be used on the first turn.
  int scoreTurn(std::string tileCode, std::string location);

  // Adds the score of the size of the linkedlist to the player. Also detemines if there has been
  // a QWIRKLE, and if so doubles the score of the linkedlist.
  int calculateScore(LinkedList* ll);

  // Prints the messages needed at the end of the game, notifying the winner and the scores.
  void endGame();

  // Function to ignore cases when comparing strings.
  bool equalsIgnoreCase(std::string string1, std::string string2);

  // Checks that the string passed, follows the rules of the qwirkle tiles, given in Tilecodes.h.
  // Returns custom error messages if not.
  bool checkValidTileCode(std::string tileCode);

  // Checks that the string passed, is a valid coordinate location on the board.
  bool checkValidCoordinate(std::string coor);

  // Convert a tileCode to a tile for various functions within the game. Programming by contract
  // as it is assumed the tileCode has been checked with the checkValidTileCode function declared
  // above.
  Tile* retrievePlayersTile(std::string tileCode);

  // Check if there is a match of colour between a tile to place and an existing tile.
  bool checkMatchColour(Tile* tileToPlace, Tile* existingTile);

  // Check if there is a match of shape between a tile to place and an existing tile.
  bool checkMatchShape(Tile* tileToPlace, Tile* existingTile);

  // Set Current Player to player of callers choice.
  void setCurrPlayer(Player* player);

  // Rotates Current player between player 1 and player 2.
  void changeCurrPlayer();

  // Generates a random in from a min to max level. Used in the creation of the tilebag.
  int generateRandomInt(int min, int max);


private:

  LinkedList* tileBag;
  LinkedList* playedTiles;
  Player* player1;
  Player* player2;
  Board* board;
  Player* currPlayer;

};

#endif // ASSIGN2_GAMECONTROLLER_H

