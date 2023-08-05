#include "menu.h"
#include "GameController.h"
#include <iostream>
#include <limits>
#include <exception>
#include "IOStream.h"
#include <sstream>
#include "Player.h"
#include <fstream>


Menu::Menu() {
    // We need anything? 

}


Menu::~Menu() {
    // Delete

}


void Menu::printMenu() {



    int input = 0;
    bool validInput = false;
    bool endOfFile = false;
    bool creditsRan = false;

    while (!validInput && input != EXIT && !endOfFile) {
        std::cout << "Menu" << std::endl;
        std::cout << "-----" << std::endl;
        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits (Show Student Information)" << std::endl;
        std::cout << "4. Quit" << std::endl;
        if(!creditsRan) {
            std::cout << "> ";
            creditsRan = false;
        }
        
        while (std::cin.peek() == '\n') {
            std::cout << "> ";
            std::cin.get(); // Consume the newline character
        }
            
      



        if (std::cin >> input) {


            if (input == START) {
                startNewGame();
                validInput = true;
            }
            else if (input == LOAD) {
                endOfFile = loadGame();
                validInput = true;
            }
            else if (input == CREDITS) {
                creditsRan = printCredits();
            }
            else if(input != EXIT) {
                std::cout << "Invalid Input" << std::endl;

            }

        }
        else {

            if (std::cin.eof()) {
                endOfFile = true;

            }
            else {
                std::cout << "Invalid Input" << std::endl;
                //clears error state from bad input to prevent infinite loop
                std::cin.clear();

                //empty while loop to consume and discard bad input from user until newline is reached.
                //uses std::cin.get() to keep receiving input.
                char randomInput;
                while ((randomInput = std::cin.get()) != '\n') {}
            }
        }
    }
}


void Menu::startNewGame() {

    std::cout << "Starting A New Game" << std::endl;
    std::cout << std::endl;

    std::string p1Name, p2Name;

    std::cout << "Enter A Name For Player 1 (uppercase characters only)" << std::endl;
    std::cout << "> ";

    bool validInput = false;
    bool eofReceived = false;

    while (!validInput && !eofReceived) {
        if (std::cin >> p1Name) {
            if (!isValidName(p1Name)) {
                std::cout << "Error: please enter a valid name for Player 1 (uppercase characters only)" << std::endl;
                std::cout << "> ";
            }
            else {
                validInput = true;
            }
        }
        else if (std::cin.eof()) {
            eofReceived = true;
        }
        else {
            //clear error state and consume contents of buffer
            std::cin.clear();
            char randomInput;
            while ((randomInput = std::cin.get()) != '\n') {}
            std::cout << "Error: please enter a valid name for Player 1 (uppercase characters only)" << std::endl;
            std::cout << "> ";
        }
    }

    if (!eofReceived) {

        std::cout << "Enter A Name For Player 2 (uppercase characters only)" << std::endl;
        std::cout << "> ";

        validInput = false;

        while (!validInput && !eofReceived) {
            if (std::cin >> p2Name) {
                if (!isValidName(p2Name)) {
                    std::cout << "Error: please enter a valid name for Player 2 (uppercase characters only)" << std::endl;
                    std::cout << "> ";
                }
                else {
                    validInput = true;
                }
            }
            else if (std::cin.eof()) {
                eofReceived = true;
            }
            else {
                //clear error state and consume contents of buffer
                std::cin.clear();
                char randomInput;
                while ((randomInput = std::cin.get()) != '\n') {}
                std::cout << "Error: please enter a valid name for Player 2 (uppercase characters only)" << std::endl;
                std::cout << "> ";
            }
        }

    }

    if (!eofReceived) {


        std::cout << "Player 1's Name = " << p1Name << std::endl;
        std::cout << "Player 2's Name = " << p2Name << std::endl;

        std::cout << "Lets Play!" << std::endl;

        try {
            GameController* gc = new GameController(p1Name, p2Name);
            gc->prepareGame();
            delete gc;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    }
}


bool Menu::isValidName(std::string& input) {
    bool valid = true;


    for (char c : input) {
        if (!std::isalpha(c) || !std::isupper(c)) {
            valid = false;

        }
    }

    return valid;

}


bool Menu::loadGame() {


    std::string filename;
    std::string save = "saved_games/";
    bool validFileName = true;
    bool eofReceived = false;


    do {
        validFileName = true;
        save = "saved_games/";
        std::cout << "Enter the filename from which to load the game" << std::endl;

        std::cout << "> ";
        std::cin >> filename;      
        save.append(filename);
        std::ifstream file(save);

        if (file.fail()) {
            std::cerr << "Error: bad file name" << std::endl;
            validFileName = false;
        } 

    } while(!validFileName && !std::cin.eof());



    if (std::cin.eof()) {
        eofReceived = true;
    }

    if (!eofReceived) {



        //load game from file here, whilst also checking if filename is valid.

        IOStream load = IOStream();
        std::string game = load.loadGame(save);

        std::stringstream stream;
        stream.str(game);

        // Create Player One

        std::string p1Name, p2Name;
        stream >> p1Name;

        int p1Score;
        stream >> p1Score;

        std::string hand;
        stream >> hand;

        std::stringstream stream2;
        stream2.str(hand);

        LinkedList* p1Hand = new LinkedList;

        std::string hand1;
        while (std::getline(stream2, hand1, ','))
        {
            char colour = std::toupper(hand1[0]);
            int shape = hand1[1] - '0';

            Tile* tile = new Tile(shape, colour);
            p1Hand->addBack(tile);
            delete tile;
        }

        Player p1 = Player(p1Name, p1Hand, p1Score);

        // Create Player Two

        stream >> p2Name;

        int p2Score;
        stream >> p2Score;

        std::string hand2;
        stream >> hand2;

        std::stringstream stream3;
        stream3.str(hand2);

        LinkedList* p2Hand = new LinkedList;

        std::string hand3;
        while (std::getline(stream3, hand3, ','))
        {
            char colour = std::toupper(hand3[0]);
            int shape = hand3[1] - '0';

            Tile* tile = new Tile(shape, colour);
            p2Hand->addBack(tile);
            delete tile;
        }

        Player p2 = Player(p2Name, p2Hand, p2Score);

        // Get Board Size and create board

        std::string boardSize;
        stream >> boardSize;

        std::stringstream boardSizeStream;
        boardSizeStream.str(boardSize);
        int boardRow;
        std::string row;
        std::getline(boardSizeStream, row, ',');
        boardRow = stoi(row);
        int boardCol;
        boardSizeStream >> boardCol;

        std::string boardState;
        stream >> boardState;
        std::stringstream boardStateStream;
        boardStateStream.str(boardState);

        Board* board = new Board(boardRow, boardCol);


        // Load Board State
        std::string state;
        while (std::getline(boardStateStream, state, ','))
        {
            if (state.size() <= 2)
            {

            }
            else
            {
                char colour = std::toupper(state[0]);
                int shape = state[1] - '0';

                Tile* tile = new Tile(shape, colour);

                int row = state[3] - ASCII;
                int col = (stoi(state.substr(4)) - 1);

                board->setTile(row, col, tile);
                // delete tile;
                // Deleting breaks the board state as it is a board of pointers.
                // Need to handle the deleting elsewhere.
            }
        }

        // Create/load Tile Bag

        std::string tempTileBag;
        stream >> tempTileBag;
        std::stringstream tileBagStream;
        tileBagStream.str(tempTileBag);

        LinkedList* tileBag = new LinkedList();
        std::string tempTile;

        while (std::getline(tileBagStream, tempTile, ','))
        {
            char colour = std::toupper(tempTile[0]);
            int shape = tempTile[1] - '0';

            Tile* tile = new Tile(shape, colour);

            tileBag->addBack(tile);
            delete tile;
        }

        std::string currentPlayer;
        stream >> currentPlayer;

        GameController gc = GameController(p1, p2, board, tileBag);

        if (p1.getName() == currentPlayer)
        {
            gc.setCurrPlayer(&p1);
        }
        else
        {
            gc.setCurrPlayer(&p2);
        }

          // Needed to clear cin buffer for first turn only.
        char randomInput;
        while ((randomInput = std::cin.get()) != '\n') {}
        gc.playGame();

    }
    return eofReceived;
}

bool Menu::printCredits() {

    std::cout << "------------------------------------------" << std::endl;

    std::cout << "Name: David Bradbury" << std::endl;
    std::cout << "Student ID: s3775590" << std::endl;
    std::cout << "Email: s3775590@student.rmit.edu.au" << std::endl;

    std::cout << "Name: Josh Coppen" << std::endl;
    std::cout << "Student ID: s3775648" << std::endl;
    std::cout << "Email: s3775648@student.rmit.edu.au" << std::endl;

    std::cout << "Name: Jack Lynch" << std::endl;
    std::cout << "Student ID: s3782003" << std::endl;
    std::cout << "Email: s3782003@student.rmit.edu.au" << std::endl;

    std::cout << "Name: David Pulvirenti" << std::endl;
    std::cout << "Student ID: s3858853" << std::endl;
    std::cout << "Email: s3858853@student.rmit.edu.au" << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    return true;
}



