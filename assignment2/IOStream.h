#ifndef IOSTREAM
#define IOSTREAM

// #include "Node.h"
#include <iostream>
#include "LinkedList.h"

class IOStream {
public:

  IOStream();
  ~IOStream();


  //Saves game and returns true if successful
  bool saveGame(std::string data, std::string fileName);
  //Loads game (possibly make it return a string?)
  void loadGame(std::string fileName);
  std::string getFileType(std::string fileName);

  LinkedList getTileBag(std::string tiles);

private:

};

#endif // IOSTREAM