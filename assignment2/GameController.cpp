#include "GameController.h"
#include "Tile.h"
#include "TileCodes.h"
#include "menu.h"
#include <iostream>
#include <exception>
#include <random>



GameController::GameController(std::string player1, std::string player2) {

  try {
    this->player1 = new Player(1, player1);
    this->player2 = new Player(2, player2);
    this->board = new Board();
    this->tileBag = new LinkedList();
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

GameController::~GameController() {

}

void  GameController::prepareGame() {
  // Not sure about changing menu structure.
  createTileBag();
  setupHands();


}

void  GameController::endGame() {

}
void  GameController::quit() {

}
void  GameController::saveGame(std::string fileName, std::string data) {

}

void  GameController::createTileBag() {

  int min = 0;
  int max = 5;
  int tileCount = 0;
  char colours[6] = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE };
  int shapes[6] = { 1, 2, 3, 4, 5, 6 };
  int numberOfOccurances = 0;


  while (tileCount < MAX_TILES) {
    numberOfOccurances = 0;
    try
    {
      Tile* tileToAdd = new Tile(shapes[generateRandomInt(min, max)], colours[generateRandomInt(min, max)]);

      for (int i = 0; i < this->tileBag->size(); i++) {
        if (tileToAdd->getShape() == tileBag->get(i)->getShape() && tileToAdd->getColour() == tileBag->get(i)->getColour()) {
          ++numberOfOccurances;
        }
      }

      if (numberOfOccurances < MAX_TILE_OCCURENCES) {
        tileBag->addBack(tileToAdd);
        tileCount++;
      }

      else {
        delete tileToAdd;
      }

    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }


  }
  // Remove after testing
  std::cout << "****Tile Bag Contents****" << std::endl;
  for (int i = 0; i < this->tileBag->size(); ++i) {
    std::cout << "i: " << i << " - " << tileBag->get(i)->getColour() << ", " << tileBag->get(i)->getShape() << std::endl;
  }

}

int GameController::generateRandomInt(int min, int max) {
  std::random_device engine;
  // std::default_random_engine engine(10);
  std::uniform_int_distribution<int> uniform_dist(min, max);
  return uniform_dist(engine);

}


void  GameController::setupHands() {

  for (int i = 0; i < FULL_HAND; i++) {
    player1->addToHand(tileBag->get(0));
    tileBag->deleteFront();
    player2->addToHand(tileBag->get(0));
    tileBag->deleteFront();
  }

  // All following code needs to be removed, here for testing.
  std::cout << "****Tile Bag Contents****" << std::endl;
  for (int i = 0; i < this->tileBag->size(); ++i) {
    std::cout << "i: " << i << " - " << tileBag->get(i)->getColour() << ", " << tileBag->get(i)->getShape() << std::endl;
  }
  std::cout << "****Players hand Contents****" << std::endl;
  std::cout << "Player 1 hand" << std::endl;
  player1->printHand();
  std::cout << "Player 2 hand" << std::endl;
  player2->printHand();
}

void  GameController::takeInput() {
  // cin > command

  // string.split(command)  

  // if (place)
  //  checkHand(2nd string.split);
  //  if (checkHand == true) {
  //   at string is correct "place g6 at b4" "place g6 to b4"

  // convert tile string to int in gamecontroller class in own function.
  //   checkBoard(b4) // to see if move is valid, and that board position is free. pass 2 ints, row and col. Most likely involde multiple function 
  // calls from this function to determine bool value. The rules need to be checked here
  //   if (checkBoard == true)

  //   placeTile

//}
  // convert string coords to int in coord class. DB
// also need to add the replace, exit and save input handling too.

// Need to figure out where to print messages from.
// need to rearrange class structure to start with gamecontroller, then create a menu within the gamecontroller.
}

// maybe program by contract function as we assume checks have previously been made to ensure placing tile is a valid move.
void  GameController::placeTile(Tile* tile, char row, int col) {

  //this->coordinates[16][16].setPlayedTile(new Tile(4, 'R'));
  //this->coordinates[16][16].setHasPlayedTile(true);
}

void  GameController::replaceTile(Tile* tile) {

}

void  GameController::scoreTurn() {

}