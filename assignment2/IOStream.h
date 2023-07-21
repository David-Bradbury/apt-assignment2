#ifndef IOSTREAM
#define IOSTREAM

// #include "Node.h"

class IOStream {
public:

   IOStream();
   ~IOStream();


   //Saves game and returns true if successful
   bool saveGame();
   //Loads game (possibly make it return a string?)
   void loadGame();

private:

};

#endif // IOSTREAM