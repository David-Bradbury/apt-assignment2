#include "LinkedList.h"
#include "TileCodes.h"
#include <iostream>
#include "Menu.h"
#include "Board.h"

#define EXIT_SUCCESS    0


int main(void) {
   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;

   Menu menu;

   menu.printMenu();

   Board board;

   board.printBoard();


   return EXIT_SUCCESS;
}