#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>
#include "LinkedList.h"
#include <vector>
#include <string>

class IOStream {
public:

  // Contructor / Destructor
  IOStream();
  ~IOStream();

  // Saves game and returns true if successful.
  bool saveGame(std::string data, std::string fileName);

  // Returns saved game as a string.
  std::string loadGame(std::string fileName);

  // Gets file type from a passed string.
  std::string getFileType(std::string fileName);

private:

};

#endif // IOSTREAM