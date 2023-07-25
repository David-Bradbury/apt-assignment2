  #include "GameController.h"
  #include "Tile.h"
  #include "TileCodes.h"
  #include <iostream>
  #include <exception>
  #include <random>



  GameController::GameController(std::string player1, std::string player2) {
    
    try{
      this->player1 = new Player(1, player1);

    } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;

    }


    try{
      this->player2 = new Player(2, player2);

    } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;

    }

    try{
      this->board = new Board();

    } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;

    }

  }

   GameController::~GameController() {

  }

  void  GameController::startGame() {
    std::cout << "Before create tile bag creation" << std::endl;

    createTileBag();

  }
  
  void  GameController::endGame() {

  }
  void  GameController::quit() {

  }
  void  GameController::saveGame(std::string fileName) {

  }

  void  GameController::createTileBag() {


    int min = 0;
    int max = 5;
    int tileCount = 0;
    char colours[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE };
    int shapes[6] = {1, 2, 3, 4, 5, 6};
    int numberOfOccurances = 0;
    std::cout << "before while loop" << std::endl;

    while(tileCount < MAX_TILES) {
      std::cout << "In while loop" << std::endl;
      numberOfOccurances = 0;
      try
      {
        Tile* tileToAdd = new Tile(shapes[generateRandomInt(min, max)], colours[generateRandomInt(min, max)]);

        for(int i = 0; i < this->tileBag->size(); ++i) {
          if(tileToAdd->getShape() == tileBag->get(i)->tile->getShape() && tileToAdd->getColour() == tileBag->get(i)->tile->getColour()) {
            ++numberOfOccurances;

          }
        }

        if(numberOfOccurances < 2) {
          tileBag->addBack(tileToAdd);

        } else {
          delete tileToAdd;
        }



      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << std::endl;
      }

      std::cout << "****Tile Bag Contents****" << std::endl;

      for(int i = 0; i < this->tileBag->size(); ++i) {
        std::cout << tileBag->get(i)->tile->getShape() << ", " << tileBag->get(i)->tile->getColour() << std::endl;
      }
      

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