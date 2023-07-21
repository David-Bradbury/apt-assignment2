#include "Menu.h"
#include <iostream>
#include <limits>



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

    int input = 0;
    bool validInput = false;

    while(!validInput && input != EXIT) {

        std::cout << "> ";


        if(std::cin >> input){

            if (input == START) {
                startNewGame();
                validInput = true;
            }
            else if (input == LOAD) {
                loadGame();
                validInput = true;
            }
            else if (input == CREDITS) {
                printCredits();
                validInput = true;
            }
            else if (input == EXIT) {
                quitGame();
            }
            else {
                std::cout << "Invalid Input" << std::endl;

            }
        } else {
            std::cout << "Invalid Input" << std::endl;
            //clears error state from bad input to prevent infinite loop
            std::cin.clear();
            
            //empty while loop to consume and discard bad input from user until newline is reached.
            //uses std::cin.get() to keep receiving input.
            char randomInput;
            while((randomInput = std::cin.get()) != '\n') {

            }

        }

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

}