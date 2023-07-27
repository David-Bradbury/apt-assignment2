#include "GameController.h"
#include "Tile.h"
#include "TileCodes.h"
#include <iostream>
#include <exception>
#include <random>



GameController::GameController(std::string player1, std::string player2) {

  try {
    this->player1 = new Player(1, player1);

  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;

  }


  try {
    this->player2 = new Player(2, player2);

  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;

  }

  try {
    this->board = new Board();
    this->tileBag = new LinkedList();
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;

  }
}

GameController::~GameController() {

}

void  GameController::startGame() {

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

      if (numberOfOccurances < 2) {
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

  // for (int i = 0; i < FULL_HAND; i++) {
  Tile* tile = new Tile(CIRCLE, RED);
  Tile* tile2 = new Tile(CIRCLE, ORANGE);
  Tile* tile3 = new Tile(CIRCLE, BLUE);
  std::cout << "****Before Add to hand****" << std::endl;
  player1->addToHand(tile);
  std::cout << "****After Add To Hand****" << std::endl;
  player1->addToHand(tile);
  player1->addToHand(tile2);
  player1->addToHand(tile2);
  player1->addToHand(tile3);
  player1->addToHand(tile3);
  // std::cout << tileBag->get(0)->getColour() << tileBag->get(0)->getShape() << std::endl;
  // player2->addToHand(tileBag->get(2));

  tileBag->deleteFront();
  // }
  std::cout << "****Tile Bag Contents****" << std::endl;
  for (int i = 0; i < this->tileBag->size(); ++i) {
    std::cout << "i: " << i << " - " << tileBag->get(i)->getColour() << ", " << tileBag->get(i)->getShape() << std::endl;
  }

  // std::cout << "****Players hand Contents****" << std::endl;

  std::cout << "Player 1 hand" << std::endl;
  player1->printHand();

  // std::cout << "Player 2 hand" << std::endl;
  // player2->printHand();

}

void  GameController::takeInput() {

}

void  GameController::placeTile(Tile* tile, char row, int col) {

}
void  GameController::replaceTile(Tile* tile) {

}

void  GameController::scoreTurn() {

}