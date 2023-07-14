
#include "LinkedList.h"
#include "TileCodes.h"
#include <iostream>

#define EXIT_SUCCESS    0


int main(void) {

   LinkedList* list = new LinkedList();
   

   std::cout << "TODO: Implement Qwirkle!" << std::endl;
   Tile* tile1 = new Tile(CIRCLE, RED);
   Tile* tile2 = new Tile(STAR_4, PURPLE);
   Tile* tile3 = new Tile(SQUARE, BLUE);
   Tile* tile4 = new Tile(CLOVER, YELLOW);
   std::cout<< list->size()<<std::endl;
   list->addBack(tile1);
   std::cout<< tile1->getColour()<< " "<< tile1->getShape()<<std::endl;
   std::cout<< list->get(1)->tile->getColour()<<std::endl;
   list->addBack(tile2);
   list->addBack(tile3);
   list->addBack(tile4);
std::cout << "TODO: Implement Qwirkle!" << std::endl;
   for(int i = 0; i != list->size()+1 ; i++ ) {

      std::cout<< "list[" << i << "] "<< list->get(i)->tile->getColour()<< " "<< list->get(i)->tile->getShape()<<std::endl;
   }
   delete list;


   return EXIT_SUCCESS;
}
