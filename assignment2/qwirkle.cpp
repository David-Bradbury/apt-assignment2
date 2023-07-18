
#include "LinkedList.h"
#include "TileCodes.h"
#include <iostream>

#define EXIT_SUCCESS    0


int main(void) {
      std::cout << "TODO: Implement Qwirkle!" << std::endl;
   //Testing Linked List----------------------------
   LinkedList* list = new LinkedList();
   
   Tile* tile1 = new Tile(CIRCLE, RED);
   Tile* tile2 = new Tile(STAR_4, PURPLE);
   Tile* tile3 = new Tile(SQUARE, BLUE);
   Tile* tile4 = new Tile(CLOVER, YELLOW);
   std::cout<<"List size prior to addtions: " << list->size()<<std::endl;
   list->addBack(tile1);
   list->addBack(tile2);
   list->addBack(tile3);
   list->addBack(tile4);
   // list->addBack(tile1);
   // list->addBack(tile2);
   // list->addBack(tile3);
   // list->addBack(tile4);
   std::cout<< "testing add back"<<std::endl;
   for(int i = 0; i != list->size() ; i++ ) {

      std::cout<< "list[" << i << "] "<< list->get(i)->tile->getColour()<< " "<< list->get(i)->tile->getShape()<<std::endl;
   }

   // std::cout<< "testing add front"<<std::endl;

   // list->addFront(tile2);
   // list->addFront(tile1);

   //    for(int i = 0; i != list->size() ; i++ ) {

   //    std::cout<< "list[" << i << "] "<< list->get(i)->tile->getColour()<< " "<< list->get(i)->tile->getShape()<<std::endl;
   // }


   std::cout<<"Size of Linked List: " << list->size()<<std::endl;

  // list->deleteTile(tile1);
   list->deleteTile(tile2);
   //list->deleteTile(tile3);
   list->deleteTile(tile4);

         for(int i = 0; i != list->size() ; i++ ) {

      std::cout<< "list[" << i << "] "<< list->get(i)->tile->getColour()<< " "<< list->get(i)->tile->getShape()<<std::endl;
   }

   std::cout <<"Is it in the list: " << list->tileInList(tile2) << std::endl;
   list->deleteTile(tile2);
   std::cout <<"Is it in the list after delete: " << list->tileInList(tile2) << std::endl;


   std::cout<<"Size of Linked List: " << list->size()<<std::endl;
   delete list;
   //------------------------------------------------


   return EXIT_SUCCESS;
}
