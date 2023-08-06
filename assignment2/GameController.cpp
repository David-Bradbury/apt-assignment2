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

    this->player1 = new Player(player1);
    this->player2 = new Player(player2);
    this->board = new Board(MAX_ROW, MAX_COL);
    this->tileBag = new LinkedList();
    this->playedTiles = new LinkedList();
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}


GameController::GameController(Player* player1, Player* player2, Board* board, LinkedList* tileBag, LinkedList* playedTiles) {

  try {

    this->player1 = player1;
    this->player2 = player2;
    this->board = board;
    this->tileBag = tileBag;
    this->playedTiles = playedTiles; // load played tiles
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
  delete this->playedTiles;
}


void  GameController::prepareGame() {

  // Filling tile bag and player hands.
  createTileBag();
  setupHands();
  setCurrPlayer(player1);
  // Needed to clear cin buffer for first turn only.
  char randomInput;
  while ((randomInput = std::cin.get()) != '\n') {}
  playGame();
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
        delete tileToAdd;
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
}


void  GameController::setupHands() {

  for (int i = 0; i < FULL_HAND; i++) {

    player1->addToHand(tileBag->get(0));
    tileBag->removeFront();
  }
  for (int i = 0; i < FULL_HAND; i++) {
    player2->addToHand(tileBag->get(0));
    tileBag->removeFront();
  }
}


void GameController::playGame() {

  bool eofReceived = false;

  while (!eofReceived && (player1->getHand()->size() > 0 && player2->getHand()->size() > 0)) {

    printTurn();
    eofReceived = takeInput();
    changeCurrPlayer();
  }

  if (!eofReceived) {
    endGame();

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


bool GameController::takeInput() {
  bool eofReceived = false;
  std::string input;
  std::cout << "> ";
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
        iss >> coor;

        if (!equalsIgnoreCase(command, "at")) {

          std::cout << "Invalid command" << std::endl;
        }
        else if (!checkValidTileCode(t)) {

          std::cout << "Invalid command" << std::endl;
        }
        else if (!checkValidCoordinate(coor)) {

          std::cout << "Invalid command" << std::endl;
        }
        else {
          validInput = placeTile(t, coor);
        }
      }
      else {
        std::cerr << "Invalid number of commands to place a tile" << std::endl;
      }
    }
    else if (equalsIgnoreCase(command, "save")) {
      if (commandCount == 2) {

        iss >> command;
        saveGame(command);
        std::cout << "Game saved successfully" << std::endl;

      }
      else {
        std::cerr << "Invalid number of commands" << std::endl;
      }
    }
    else if (equalsIgnoreCase(command, "quit")) {
      if (commandCount == 1) {
        validInput = true;
        eofReceived = true;
      }
      else {
        std::cerr << "Invalid number of commands" << std::endl;
      }
    }
    else {
      if (!std::cin.eof()) {
        std::cerr << "Invalid Command" << std::endl;
      }
    }
    if (!validInput) {
      if (!std::cin.eof()) {
        std::cout << "> ";
        std::getline(std::cin, input);
        input = input + " &%";
        iss.clear();
        iss.str(input);

        commandCount = -1;

        while (!equalsIgnoreCase(command, "&%")) {

          iss >> command;
          ++commandCount;
        }

        iss.clear();
        iss.str(input);
      }
    }

    // repeat unless valid input or end of file received
  } while (!validInput && !std::cin.eof());

  if (std::cin.eof()) {
    eofReceived = true;
  }
  return eofReceived;
}


bool  GameController::replaceTile(std::string tileCode) {

  bool turnSuccess = false;
  bool validTileCode = checkValidTileCode(tileCode);

  if (validTileCode) {
    try
    {
      Tile* tile = retrievePlayersTile(tileCode);

      // Check if tile is in players hand.
      if (tile != nullptr) {

        // Checks if tilebag has any tiles left.
        if (this->tileBag->size() > 0) {

          // relevant movement of tiles.
          this->currPlayer->getHand()->removeTile(tile);
          this->currPlayer->addToHand(this->tileBag->get(0));
          this->tileBag->removeFront();
          this->tileBag->addBack(tile);
          turnSuccess = true;
        }
        else {
          std::cerr << "No more tiles in the tilebag" << std::endl;
        }
      }
      else {
        std::cerr << "Tile is not in players hand" << std::endl;
      }
    }
    catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
  }
  return turnSuccess;
}


bool  GameController::placeTile(std::string tileCode, std::string location) {

  bool tilePlaced = false;
  bool colValidMove = false;
  bool rowValidMove = false;

  location[0] = std::toupper(location[0]);

  int row = location[0] - ASCII;
  int col = 0;

  if (location.length() == 2) {
    col = (location[1] - '0') - 1;
  }
  else {
    std::string column = location.substr(1, 2);
    col = std::stoi(column) - 1;
  }

  // check board position where tile to be placed is empty.
  if (this->board->isBoardPositionEmpty(row, col)) {

    try
    {
      Tile* tile = retrievePlayersTile(tileCode);

      // make sure tile is in hand. 
      if (tile != nullptr) {

        // checks that isn't first turn
        if (this->tileBag->size() < START_GAME_TILEBAG_LENGTH) {

          LinkedList* northSouthLL = board->getTileList(row, col, "ns");
          LinkedList* eastWestLL = board->getTileList(row, col, "ew");

          // Passes only if one of these list isn't empty, meaning there is adjacent tiles on the board.
          if (!northSouthLL->isEmpty() || !eastWestLL->isEmpty()) {

            if (!northSouthLL->isEmpty()) {

              colValidMove = checkValidMove(northSouthLL, tile);
            }
            else {

              colValidMove = true;
            }

            if (!eastWestLL->isEmpty()) {

              rowValidMove = checkValidMove(eastWestLL, tile);
            }
            else {

              rowValidMove = true;
            }
          }
          else {
            std::cerr << "Tile cannot Be placed here, must be connected to another tile" << std::endl;
          }

          if (colValidMove && rowValidMove) {

            this->currPlayer->addToScore(scoreTurn(tileCode, location));
            this->board->setTile(row, col, tile);
            this->playedTiles->addBack(tile);
            this->currPlayer->getHand()->removeTile(tile);

            if (this->tileBag->size() > 0) {

              this->currPlayer->addToHand(this->tileBag->get(0));
              this->tileBag->removeFront();
            }

            tilePlaced = true;
          }

          delete northSouthLL;
          delete eastWestLL;

        }
        else {
          //first turn
          this->board->setTile(row, col, tile);
          this->playedTiles->addBack(tile);
          this->currPlayer->getHand()->removeTile(tile);

          if (this->tileBag->size() > 0) {

            this->currPlayer->addToHand(this->tileBag->get(0));
            this->tileBag->removeFront();
          }

          this->currPlayer->addToScore(1);
          tilePlaced = true;
        }
      }
      else {
        std::cerr << "Tile not in your hand." << std::endl;
      }

    }
    catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
  }
  else {
    std::cerr << "Tile can not be placed at this location as another tile has already been placed." << std::endl;
  }

  return tilePlaced;
}


bool GameController::checkValidMove(LinkedList* ll, Tile* tile) {

  bool tileCanBePlaced = false;

  bool colourMatch = true;
  bool shapeMatch = true;
  bool overallColourMatch = true;
  bool overallShapeMatch = true;
  bool overallMatch = true;

  // Check if tiles placed does not exceed max length of 6 tiles.
  if (ll->size() < PLACED_TILE_MAX_LENGTH) {

    // Checking to see if there is a duplicate tile in the list.
    if (!ll->tileInList(tile)) {

      for (int i = 0; i < ll->size(); i++) {

        colourMatch = checkMatchColour(tile, ll->get(i));

        if (!colourMatch) {
          overallColourMatch = false;
        }
      }
      for (int i = 0; i < ll->size(); i++) {

        shapeMatch = checkMatchShape(tile, ll->get(i));

        if (!shapeMatch) {
          overallShapeMatch = false;
        }
      }

      if ((!overallColourMatch && !overallShapeMatch) || (overallColourMatch && overallShapeMatch)) {
        overallMatch = false;
      }

      if (overallMatch) {
        tileCanBePlaced = true;
      }
      else {
        std::cerr << "Illegal Move" << std::endl;
      }
    }
    else {
      std::cerr << "Tile can not be placed as it is a duplicate tile" << std::endl;
    }
  }
  else {
    std::cerr << "Tile can not be placed, as it exceeds maximum placed tile length of 6." << std::endl;
  }

  return tileCanBePlaced;
}


void  GameController::saveGame(std::string fileName) {

  IOStream stream;
  std::string saveData = "";

  // Player One Name
  saveData += this->player1->getName();
  saveData += '\n';

  // Player One Score
  saveData += std::to_string(this->player1->getScore());
  saveData += '\n';

  // Player One hand
  for (int i = 0; i < this->player1->getHand()->size(); i++) {

    saveData += this->player1->getHand()->get(i)->getColour();
    saveData += std::to_string(this->player1->getHand()->get(i)->getShape());
    saveData += ',';
  }

  // Remove trailing ','
  saveData.resize(saveData.length() - 1);
  saveData += '\n';

  // Player Two Name
  saveData += this->player2->getName();
  saveData += '\n';

  // Player Two Score
  saveData += std::to_string(this->player2->getScore());
  saveData += '\n';

  // Player Two hand
  for (int i = 0; i < this->player2->getHand()->size(); i++) {

    saveData += this->player2->getHand()->get(i)->getColour();
    saveData += std::to_string(this->player2->getHand()->get(i)->getShape());
    saveData += ',';
  }

  // Remove trailing ','
  saveData.resize(saveData.length() - 1);
  saveData += '\n';

  // Board Shape
  saveData += std::to_string(this->board->getRows()) + "," + std::to_string(this->board->getCols());
  saveData += '\n';

  // Board State

  if (this->playedTiles->size() == 0) {
    saveData += " ";
  }
  else {
    saveData += this->board->getCoordinates();
  }

  saveData += '\n';

  // Board Tile Bag
  for (int i = 0; i < this->tileBag->size(); i++) {

    saveData += tileBag->get(i)->getColour();
    saveData += std::to_string(tileBag->get(i)->getShape());
    saveData += ',';
  }

  // Remove trailing ','
  saveData.resize(saveData.length() - 1);
  saveData += '\n';

  // Current Player Name
  saveData += this->currPlayer->getName();

  // Save the game
  stream.saveGame(saveData, fileName);

}


int  GameController::scoreTurn(std::string tileCode, std::string location) {

  int score = 0;
  location[0] = std::toupper(location[0]);

  int row = location[0] - ASCII;
  int col = 0;

  if (location.length() == 2) {
    col = (location[1] - '0') - 1;
  }
  else {
    std::string column = location.substr(1, 2);
    col = std::stoi(column) - 1;
  }

  try {

    Tile* tile = retrievePlayersTile(tileCode);

    LinkedList* northSouthLL = board->getTileList(row, col, "ns");
    LinkedList* eastWestLL = board->getTileList(row, col, "ew");

    if (!northSouthLL->isEmpty()) {

      northSouthLL->addBack(tile);
      score += calculateScore(northSouthLL);
    }
    if (!eastWestLL->isEmpty()) {

      eastWestLL->addBack(tile);
      score += calculateScore(eastWestLL);
    }

    delete northSouthLL;
    delete eastWestLL;

  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return score;
}


int GameController::calculateScore(LinkedList* ll) {

  int score = 0;
  for (int i = 0; i < ll->size(); i++) {
    score++;
  }

  if (score == QWIRKLE) {
    score = score * 2;
    std::cout << "QWIRKLE!!!" << std::endl;
  }

  return score;
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

    if (std::isalpha(row) && col <= MAX_COL && col >= MIN_COL) {
      validCoordinate = true;
    }
  }
  else if (coor.length() == 3) {

    char row = std::toupper(coor[0]);
    std::string column = coor.substr(1, 2);

    if (std::isalpha(column[0]) || std::isalpha(column[1])) {
    }
    else {
      int col = std::stoi(column);
      if (std::isalpha(row) && col <= MAX_COL && col >= MIN_COL) {
        validCoordinate = true;
      }
    }
  }

  return validCoordinate;
}


Tile* GameController::retrievePlayersTile(std::string tileCode) {

  Tile* tile = nullptr;

  char colour = std::toupper(tileCode[0]);
  int shape = tileCode[1] - '0';

  Tile* tempTile = new Tile(shape, colour);

  if (this->currPlayer->getHand()->tileInList(tempTile)) {

    for (int i = this->currPlayer->getHand()->size() - 1; i >= 0; i--) {

      if (colour == this->currPlayer->getHand()->get(i)->getColour() && shape == this->currPlayer->getHand()->get(i)->getShape()) {
        tile = this->currPlayer->getHand()->get(i);
      }
    }
  }

  delete tempTile;
  return tile;
}


bool GameController::checkMatchColour(Tile* tileToPlace, Tile* existingTile) {
  bool match = false;

  if (tileToPlace->getColour() == existingTile->getColour()) {
    match = true;
  }
  return match;
}


bool GameController::checkMatchShape(Tile* tileToPlace, Tile* existingTile) {
  bool match = false;

  if (tileToPlace->getShape() == existingTile->getShape()) {
    match = true;
  }

  return match;
}


void GameController::setCurrPlayer(Player* player) {
  this->currPlayer = player;
}


void GameController::changeCurrPlayer() {
  if (this->currPlayer == this->player1) {
    this->currPlayer = this->player2;
  }
  else {
    this->currPlayer = this->player1;
  }
}


int GameController::generateRandomInt(int min, int max) {

  std::random_device engine;
  std::uniform_int_distribution<int> uniform_dist(min, max);

  return uniform_dist(engine);
}

