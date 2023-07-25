#include "LinkedList.h"
#include "TileCodes.h"
#include <iostream>
#include "Menu.h"

#define EXIT_SUCCESS    0


int main(void) {
  
   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;
   
   Menu menu;
  
   menu.printMenu();
  


   return EXIT_SUCCESS;
}
