#include "GameController.h"
#include "Tile.h"
#include "TileCodes.h"
#include "menu.h"
#include <iostream>
#include <exception>
#include <random>
#include <iostream>
#include <sstream>

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

  // Filling tile bag and player hands.
  createTileBag();
  setupHands();
  this->currPlayer = player1;

  printTurn();
  takeInput();
  // playGame();
  // std::string tile;
  // std::cout << "Enter tile > ";
  // std::cin >> tile;

  // std::cout << "tile[0]: " << tile[0] << std::endl;
  // std::cout << "tile[1]: " << tile[1] << std::endl;

  // bool value = replaceTile(tile);

  // std::cout << "Success: " << value << std::endl;

  std::cout << "****Tile Bag Contents****" << std::endl;
  for (int i = 0; i < this->tileBag->size(); ++i) {
    std::cout << "i: " << i << " - " << tileBag->get(i)->getColour() << ", " << tileBag->get(i)->getShape() << std::endl;
  }
  std::cout << "****Players hand Contents****" << std::endl;
  std::cout << "Player 1 hand" << std::endl;
  player1->printHand();
  std::cout << "Player 2 hand" << std::endl;
  player2->printHand();


  // Tile* tile = this->player1->getHand()->get(0);



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


bool GameController::equalIgnoreCase(std::string string1, std::string string2) {
  bool theSameIgnoringCase = true;

  if (string1.length() != string2.length()) {
    theSameIgnoringCase = false;

  }
  else {
    for (unsigned i = 0; i < string1.length(); ++i) {
      if (std::tolower(string1[i]) != std::tolower(string2[i]))
        theSameIgnoringCase = false;


    }
  }

  return theSameIgnoringCase;
}

void  GameController::takeInput() {

  std::string input;
  std::cout << "> ";
  std::getline(std::cin, input);

  input = input + " &%";

  std::istringstream iss(input);
  std::string command;

  bool validInput = false;
  int commandCount = -1;

  while (command != "&%") {
    iss >> command;
    ++commandCount;

  }
  iss.clear();
  iss.str(input);


  while (command != "&%" || !std::cin.eof()) {

    do {
      iss >> command;

      if (equalIgnoreCase(command, "replace")) {
        if (commandCount == 2) {
          std::cout << "run replace tile function" << std::endl;
          iss >> command;
          std::cout << "command: " << command << std::endl;
          validInput = replaceTile(command);

        }
        else {
          std::cerr << "Invalid number of commands" << std::endl;
        }
      }

      if (equalIgnoreCase(command, "place")) {
        if (commandCount == 4) {
          std::cout << "run place tile function" << std::endl;
          //iss >> command;
          //validInput = placeTile(command);

        }
        else {
          std::cerr << "Invalid number of commands with place" << std::endl;
        }
      }

      if (equalIgnoreCase(command, "save")) {
        if (commandCount == 2) {
          std::cout << "run save function" << std::endl;
          //iss >> command;
          //validInput = save(command);

        }
        else {
          std::cerr << "Invalid number of commands" << std::endl;
        }
      }
      if (!validInput) {
        // char randomInput;
        // //empty while loop to consume buffer prior to input
        // while ((randomInput = std::cin.get()) != '\n') {}

        std::cout << "> ";
        std::getline(std::cin, input);
        input = input + " &%";
        iss.clear();
        iss.str(input);




        commandCount = -1;
        std::cout << "Input: " << input << std::endl;

        while (!equalIgnoreCase(command, "&%")) {
          std::cout << command << std::endl;
          iss >> command;
          ++commandCount;

        }

        iss.clear();
        iss.str(input);

        std::cout << "Command count: " << commandCount << std::endl;


      }

    } while (!validInput);

  }


}

void GameController::printTurn() {

  std::cout << this->currPlayer->getName();
  std::cout << ", it's your turn" << std::endl;
  std::cout << std::endl;

  std::cout << "Score for " << this->player1->getName() << ": " << this->player1->getScore() << std::endl;
  std::cout << "Score for " << this->player2->getName() << ": " << this->player2->getScore() << std::endl;
  std::cout << std::endl;
  this->board->printBoard();

  std::cout << std::endl;

  std::cout << "Your hand is" << std::endl;

  this->currPlayer->printHand();

  std::cout << std::endl;

}


void GameController::playGame() {
  // takeInput();

   // while (tileBag->size() > 0 && (player1->getHand()->size() > 0 || player2->getHand()->size() > 0)) {

   //      if(turnID == 1) {
   //        print(turnID);
   //        takeInput();
   //      }


   // }
}


// maybe program by contract function as we assume checks have previously been made to ensure placing tile is a valid move.
bool  GameController::placeTile(std::string tileCode, std::string location) {

  bool tileCanBePlaced = false;
  bool validTileCode = checkValidTileCode(tileCode);

  if (validTileCode) {

    // if (board->boardPosEmpty(location)) {

    // }
    try
    {
      Tile* tile = convertToTile(tileCode);

      delete tile;
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }

  //this->coordinates[16][16].setPlayedTile(new Tile(4, 'R'));
  //this->coordinates[16][16].setHasPlayedTile(true);

  return tileCanBePlaced;
}

bool  GameController::replaceTile(std::string tileCode) {

  bool turnSuccess = false;
  bool validTileCode = checkValidTileCode(tileCode);

  if (validTileCode) {
    try
    {
      Tile* tile = convertToTile(tileCode);

      if (this->tileBag->size() > 0) {

        if (this->currPlayer->getHand()->tileInList(tile)) {
          this->currPlayer->getHand()->removeTile(tile);
          this->currPlayer->addToHand(this->tileBag->get(0));
          this->tileBag->deleteFront();
          this->tileBag->addBack(tile);
          turnSuccess = true;
        }
        else {
          std::cerr << "Tile is not in players hand" << std::endl;
        }
      }
      else {
        std::cerr << "No more tiles in the tilebag" << std::endl;
      }
      delete tile;
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }

  return turnSuccess;
}



void  GameController::scoreTurn() {

}


bool GameController::checkValidTileCode(std::string tileCode) {

  bool validTileCode = false;

  std::toupper(tileCode[0]);
  std::toupper(tileCode[1]);

  int shape = tileCode[1] - '0';

  if (tileCode.length() == 2) {

    //check Colour
    if (tileCode[0] == RED || tileCode[0] == ORANGE || tileCode[0] == YELLOW ||
      tileCode[0] == GREEN || tileCode[0] == BLUE || tileCode[0] == PURPLE) {
      // check Shape
      if (shape >= CIRCLE && shape <= CLOVER) {
        validTileCode = true;
      }
      else {
        std::cerr << "Tilecode is not a valid shape" << std::endl;
      }
    }
    else {
      std::cerr << "Tilecode is not a valid colour" << std::endl;
    }
  }
  else {
    std::cerr << "Tilecode length incorrect" << std::endl;
  }
  return validTileCode;
}


Tile* GameController::convertToTile(std::string tileCode) {

  char colour = tileCode[0];
  int shape = tileCode[1] - '0';

  Tile* tile = new Tile(shape, colour);

  return tile;
}