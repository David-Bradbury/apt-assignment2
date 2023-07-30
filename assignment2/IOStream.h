#ifndef IOSTREAM
#define IOSTREAM

// #include "Node.h"
#include <iostream>
#include "LinkedList.h"
#include <vector>
#include <string>

class IOStream {
public:

  IOStream();
  ~IOStream();


  //Saves game and returns true if successful
  bool saveGame(std::string data, std::string fileName);
  //returns saved game as a string.
  std::string loadGame(std::string fileName);
  std::string getFileType(std::string fileName);

private:

};

#endif // IOSTREAM