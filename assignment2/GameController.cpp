#include "GameController.h"
#include "Tile.h"
#include "TileCodes.h"
#include "menu.h"
#include <iostream>
#include "IOStream.h"
#include <exception>
#include <random>
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
  delete this->player1;
  delete this->player2;
  delete this->board;
  delete this->tileBag;
}

void  GameController::prepareGame() {
  // Not sure about changing menu structure.

  // Filling tile bag and player hands.
  createTileBag();
  setupHands();
  this->currPlayer = player1;

  // saveGame();
  // IOStream load = IOStream();
  // // std::vector<std::string> game = load.loadGame("test.save");

  // std::string game = load.loadGame("test.save");

  // std::stringstream stream;
  // stream.str(game);

  printTurn();
  takeInput();

  std::cout << "****Tile Bag Contents****" << std::endl;
  for (int i = 0; i < this->tileBag->size(); ++i) {
    std::cout << "i: " << i << " - " << tileBag->get(i)->getColour() << ", " << tileBag->get(i)->getShape() << std::endl;
  }
  std::cout << "****Players hand Contents****" << std::endl;
  std::cout << "Player 1 hand" << std::endl;
  this->player1->printHand();
  std::cout << "Player 2 hand" << std::endl;
  player2->printHand();

}

void  GameController::endGame() {

  std::cout << "Game Over" << std::endl;
  std::cout << "Score for " << this->player1->getName() << ": " << this->player1->getScore() << std::endl;
  std::cout << "Score for " << this->player2->getName() << ": " << this->player2->getScore() << std::endl;

  if (this->player1->getScore() > this->player2->getScore()) {
    std::cout << "Player " << this->player1->getName() << " won!" << std::endl;
  }
  else if (this->player1->getScore() < this->player2->getScore()) {
    std::cout << "Player " << this->player2->getName() << " won!" << std::endl;
  }
  else if (this->player1->getScore() == this->player2->getScore()) {
    std::cout << "It is a draw!" << std::endl;
  }

  //quitGame();

}
void  GameController::quit() {

}
void  GameController::saveGame() {
  IOStream stream;

  // char randomInput;

  // while ((randomInput = std::cin.get()) != '\n') {}

  std::cout << "Enter A filename for save" << std::endl;
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
  // for (int i = 0; i < this->player1->getHand()->size(); i++)
  // {
    // saveData += p1Hand->get(i)->tile->getColour();
    // saveData += this->player1->getHand()->get(i)->tile->getColour();
    // saveData += std::to_string(p1Hand->get(i)->tile->getShape());
  //   saveData += ',';
  // }
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
    saveData += tileBag->get(i)->getColour();
    saveData += std::to_string(tileBag->get(i)->getShape());

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


bool GameController::equalsIgnoreCase(std::string string1, std::string string2) {
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
  //consume buffer to prepare for taking input
  char randomInput;
  while ((randomInput = std::cin.get()) != '\n') {}
  std::getline(std::cin, input);
  //append delimeter
  input = input + " &%";

  std::istringstream iss(input);
  std::string command;

  bool validInput = false;
  //instantiate at -1 to account for delimeter
  int commandCount = -1;

  while (command != "&%") {
    iss >> command;
    ++commandCount;

  }
  iss.clear();
  iss.str(input);




  do {
    iss >> command;

    if (equalsIgnoreCase(command, "replace")) {
      if (commandCount == 2) {
        iss >> command;
        validInput = replaceTile(command);
      }
      else {
        std::cerr << "Replace command only takes one tile" << std::endl; // probs need better error messages
      }
    }
    else if (equalsIgnoreCase(command, "place")) {
      if (commandCount == 4) {
        std::string t;
        std::string coor;
        iss >> t;
        iss >> command;
        iss >>coor;
        
        if (!equalsIgnoreCase(command, "at")) {
          std::cout << "Invalid command" << std::endl;

        }
        else if (!checkValidTileCode(t)) {
          std::cout << "Invalid command" << std::endl;

        } else if (!checkValidCoordinate(coor)) {
          std::cout << "Invalid command" << std::endl;

        } else {
           std::cout << "run place tile function" << std::endl;
        
        }

      }
      else {
        std::cerr << "Invalid number of commands with 'place'" << std::endl;
      }
    }
    else if (equalsIgnoreCase(command, "save")) {
      if (commandCount == 2) {
        std::cout << "run save function" << std::endl;

      }
      else {
        std::cerr << "Invalid number of commands" << std::endl;
      }
    }
    else if (equalsIgnoreCase(command, "quit")) {
      if (commandCount == 1) {
        std::cout << "run quit function" << std::endl;
      }
      else {
        std::cerr << "Invalid number of commands" << std::endl;
      }
    }
    else {
      std::cerr << "Invalid Command" << std::endl;
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
      //std::cout << "Input: " << input << std::endl;

      while (!equalsIgnoreCase(command, "&%")) {
        //std::cout << command << std::endl;
        iss >> command;
        ++commandCount;

      }

      iss.clear();
      iss.str(input);

    }

  } while (!validInput && !std::cin.eof()); // repeat unless valid input or end of file received

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

// method where the game loop is executed until end
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

  char colour = std::toupper(tileCode[0]);
  int shape = tileCode[1] - '0';

  if (tileCode.length() == 2) {

    //check Colour
    if (colour == RED || colour == ORANGE || colour == YELLOW ||
      colour == GREEN || colour == BLUE || colour == PURPLE) {
      // check Shape
      if (shape >= CIRCLE && shape <= CLOVER) {
        validTileCode = true;
      }
      else {
        std::cerr << shape << " is not a valid shape" << std::endl;
      }
    }
    else {
      std::cerr << colour << " is not a valid colour" << std::endl;
    }
  }
  else {
    std::cerr << "Tilecode length incorrect" << std::endl;
  }
  return validTileCode;
}

bool GameController::checkValidCoordinate(std::string coor) { 
  bool validCoordinate = false;

  if (coor.length() == 2) {
    
    char row = std::toupper(coor[0]);
    int col = coor[1] - '0';

    if(std::isalpha(row) && col <= MAX_COL && col >= MIN_COL) {
      validCoordinate = true;

    } 
    }else if(coor.length() == 3) {

      char row = std::toupper(coor[0]);
      std::string column = coor.substr(1,2);

      if(!std::isalpha(column[0]) || !std::isalpha(column[1])) {

           std::cout << "not a valid coordinate 2nd if statement" << std::endl;
       
      } else {
        int col = std::stoi(column);
        if(std::isalpha(row) && col <= MAX_COL && col >= MIN_COL) {
          validCoordinate = true;
        }
      }

  } else {
    std::cout << "Not a valid coordinate" << std::endl;
  }

  

  return validCoordinate;

}

Tile* GameController::convertToTile(std::string tileCode) {

  char colour = std::toupper(tileCode[0]);
  int shape = tileCode[1] - '0';

  Tile* tile = new Tile(shape, colour);

  return tile;
}