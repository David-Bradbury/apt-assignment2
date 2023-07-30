#include "GameController.h"
#include "Tile.h"
#include "TileCodes.h"
#include <iostream>
#include <exception>
#include <random>
#include "IOStream.h"
#include <sstream>
#include <string>


GameController::GameController(std::string player1, std::string player2) {

  try {
    this->player1 = new Player(1, player1);
    this->tileBag = new LinkedList();

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

  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;

  }

}

GameController::~GameController() {

}

void  GameController::startGame() {
  std::cout << "Before create tile bag creation" << std::endl;

  createTileBag();

  saveGame();

}

void  GameController::endGame() {

}
void  GameController::quit() {

}
void  GameController::saveGame() {
  IOStream stream;

  // char randomInput;

  // while ((randomInput = std::cin.get()) != '\n') {}

  std::cout << "Enter A filename for save (filetype must be .save)" << std::endl;
  std::cout << "> ";
  std::string fileName;
  std::cin >> fileName;

  std::string saveData = "";
  // Player One Name
  saveData += this->player1->getName();
  saveData += '\n';
  // Player One Score
  saveData += std::to_string(this->player1->getScore());
  saveData += '\n';
  // Player One hand
  // LinkedList* p1Hand = this->player1->getHand();
  // std::cout << p1Hand->get(1);
  // for (int i = 0; i < p1Hand->size(); i++)
  for (int i = 0; i < this->player1->getHand()->size(); i++)
  {
    // saveData += p1Hand->get(i)->tile->getColour();
    // saveData += this->player1->getHand()->get(i)->tile->getColour();
    // saveData += std::to_string(p1Hand->get(i)->tile->getShape());
    saveData += ',';
  }
  saveData += '\n';

  // Player Two Name
  saveData += this->player2->getName();
  saveData += '\n';
  // Player Two Score
  saveData += std::to_string(this->player2->getScore());
  saveData += '\n';
  // Player Two hand
  // LinkedList* p2Hand = this->player2->getHand();

  // for (int i = 0; i < p2Hand->size(); i++)
  // {
  //   saveData += p2Hand->get(i)->tile->getColour();
  //   saveData += std::to_string(p2Hand->get(i)->tile->getShape());
  //   saveData += ',';
  // }
  saveData += '\n';

  // Board Shape
  saveData += std::to_string(this->board->getRows()) + "," + std::to_string(this->board->getCols());

  saveData += '\n';
  // Board State
  std::vector<std::vector<Coordinate>> positions = this->board->getCoordinates();

  for (unsigned int i = 0; i < positions.size(); i++)
  {
    for (unsigned int j = 0; j < positions[i].size(); j++)
    {
      if (positions[i][j].getPlayedTile() != nullptr)
      {
        saveData += positions[i][j].getPlayedTile()->getColour();
        saveData += std::to_string(positions[i][j].getPlayedTile()->getShape());
        saveData += ',';
      }

    }
  }
  // Remove trailing ','
  saveData.resize(saveData.length() - 1);
  saveData += '\n';
  // Board Tile Bag
  for (int i = 0; i < this->tileBag->size(); i++)
  {
    saveData += tileBag->get(i)->tile->getColour();
    saveData += std::to_string(tileBag->get(i)->tile->getShape());
    saveData += ',';
  }
  // Remove trailing ','
  saveData.resize(saveData.length() - 1);
  saveData += '\n';

  // Current Player Name
  // saveData += this.currPlayer.getName();

  stream.saveGame(saveData, fileName);
}




void  GameController::createTileBag() {


  int min = 0;
  int max = 5;
  int tileCount = 0;
  char colours[6] = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE };
  int shapes[6] = { 1, 2, 3, 4, 5, 6 };
  int numberOfOccurances = 0;
  std::cout << "before while loop" << std::endl;

  while (tileCount < MAX_TILES) {
    std::cout << "In while loop" << std::endl;
    numberOfOccurances = 0;
    try
    {
      Tile* tileToAdd = new Tile(shapes[generateRandomInt(min, max)], colours[generateRandomInt(min, max)]);

      for (int i = 0; i < this->tileBag->size(); ++i) {
        if (tileToAdd->getShape() == tileBag->get(i)->tile->getShape() && tileToAdd->getColour() == tileBag->get(i)->tile->getColour()) {
          ++numberOfOccurances;

        }
      }

      if (numberOfOccurances < 2) {
        tileBag->addBack(tileToAdd);
        ++tileCount;

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
    std::cout << i << ": " << tileBag->get(i)->tile->getShape() << ", " << tileBag->get(i)->tile->getColour() << std::endl;
  }

}

int GameController::generateRandomInt(int min, int max) {
  std::random_device engine;
  std::uniform_int_distribution<int> uniform_dist(min, max);
  return uniform_dist(engine);

}


void  GameController::setupHands() {


}

void  GameController::takeInput() {

}
void  GameController::placeTile(Tile* tile, char row, int col) {

}
void  GameController::replaceTile(Tile* tile) {

}

void  GameController::scoreTurn() {

}