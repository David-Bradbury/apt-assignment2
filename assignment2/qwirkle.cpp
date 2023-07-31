#include "LinkedList.h"
#include "TileCodes.h"
#include <iostream>
#include "menu.h"
#include "Board.h"

#define EXIT_SUCCESS    0

//delete this
#include <sstream>



int main(void) {

   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;

   Menu menu;

   menu.printMenu();
   std::cout << std::endl;

   std::cout << "Goodbye" << std::endl;



   return EXIT_SUCCESS;
}
