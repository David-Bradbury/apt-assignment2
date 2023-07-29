#include "LinkedList.h"
#include "TileCodes.h"
#include <iostream>
#include "menu.h"
#include "Board.h"

#define EXIT_SUCCESS    0

//delete this
#include <sstream>

bool equalIgnoreCase(std::string string1, std::string string2) {
   bool theSameIgnoringCase = true;

    if (string1.length() != string2.length()) {
      theSameIgnoringCase = false;

    } else {
            for (unsigned i = 0; i < string1.length(); ++i) {
         if (std::tolower(string1[i]) != std::tolower(string2[i]))
            theSameIgnoringCase = false;


      }
    }
        
    return theSameIgnoringCase;
}
int main(void) {


   std::string input;

   std::cout << "> ";
   std::getline(std::cin, input);

   input = input + " &%";

   std::istringstream iss(input);
   std::istringstream issCount(input);
   std::string command;

   bool validInput = false;
   int commandCount = -1;

   while(command != "&%") {
       issCount >> command;
      ++commandCount;

   }

    

  while(command != "&%" || !std::cin.eof() ) {

      do {
         iss >> command;

         if(equalIgnoreCase(command, "replace")) {
            if(commandCount == 2) {
               std::cout << "run replace tile function" << std::endl;
               // iss >> command;
               // valiInput = replaceTile(command);

            } else {
               std::cerr << "Invalid number of commands" << std::endl;
            }
         }   

         if(equalIgnoreCase(command, "place")) {
            if(commandCount == 4) {
               std::cout << "run place tile function" << std::endl;
               //iss >> command;
               //validInput = placeTile(command);

            }else {
               std::cerr << "Invalid number of commands with place" << std::endl;
            }
         }

         if(equalIgnoreCase(command, "save")) {
            if(commandCount == 2) {
               std::cout << "run save function" << std::endl;
               //iss >> command;
               //validInput = save(command);
               
            }else {
               std::cerr << "Invalid number of commands" << std::endl;
            }
         }
         if(!validInput) {
            // char randomInput;
            // //empty while loop to consume buffer prior to input
            // while ((randomInput = std::cin.get()) != '\n') {}

            std::cout << "> ";
            std::getline(std::cin, input);
            iss.str(input);
            issCount.str(input);
            //iss.clear();
            input = input + " &%";
            commandCount = -1;
            std::cout <<"Input: " << input << std::endl;

            while(command != "&%") {
               issCount >> command;
               ++commandCount;

            }
            
            std::cout <<"Command count: " << commandCount << std::endl;


         }
         


      } while(!validInput);

   }

  





   Board board;

   board.printBoard();



   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;

   Menu menu;

   menu.printMenu();



   return EXIT_SUCCESS;
}
