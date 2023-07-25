#include "LinkedList.h"
#include "TileCodes.h"
#include <iostream>
#include "Menu.h"
#include "Board.h"

#define EXIT_SUCCESS    0


int main(void) {

   Board board;

   board.printBoard();


  
   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;
   
   Menu menu;
  
   menu.printMenu();
  


   return EXIT_SUCCESS;
}
