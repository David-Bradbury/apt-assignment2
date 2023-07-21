#include "menu.h"
#include <iostream>

enum selection {
    START = 1,
    LOAD = 2,
    CREDITS = 3,
    EXIT = 4
};

Menu::Menu() {
    // We need anything? 

}

Menu::~Menu() {
    // Delete

}

void Menu::printMenu() {

    std::cout << "Menu" << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show Student Information)" << std::endl;
    std::cout << "4. Quit" << std::endl;

    char selection = 0;

    std::cout << "> ";
    std::cin >> selection;

    if (selection == START) {
        startNewGame();
    }
    else if (selection == LOAD) {
        loadGame();
    }
    else if (selection == CREDITS) {
        printCredits();
        printMenu();
    }
    else if (selection == EXIT || selection == '^D') {
        quitGame();
    }
    else {
        std::cout << "You have made an invalid selection, please choose again" << std::endl;
        printMenu();
    }

}

void Menu::startNewGame() {

    std::cout << "Starting A New Game" << std::endl;
    std::cout << std::endl;

    std::string p1Name, p2Name;

    std::cout << "Enter A Name For Player 1" << std::endl;

    std::cout << "> ";
    std::cin >> p1Name;

    std::cout << "Enter A Name For Player 2" << std::endl;

    std::cout << "> ";
    std::cin >> p2Name;

    std::cout << "Lets Play!" << std::endl;

    // Continue with gameplay code.
}

void Menu::loadGame() {

    std::string filename;

    std::cout << "Enter The Filename From Which To Load The Game" << std::endl;

    std::cout << "> ";
    std::cin >> filename;

    //load game from file here, whilst also checking if filename is valid.

}

void Menu::printCredits() {

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

    std::cout << "Name: David Bradbury" << std::endl;
    std::cout << "Student ID: s3858853" << std::endl;
    std::cout << "Email: s3858853@student.rmit.edu.au" << std::endl;

    std::cout << "------------------------------------------" << std::endl;
}

void Menu::quitGame() {

    std::cout << "Goodbye - Thanks For Playing Quirkle" << std::endl;

    // Anything else we need to add.
}