#ifndef IOSTREAM
#define IOSTREAM

// #include "Node.h"
#include <iostream>

class IOStream {
public:

  IOStream();
  ~IOStream();


  //Saves game and returns true if successful
  template<class T>
  bool saveGame(T data, std::string fileName);
  //Loads game (possibly make it return a string?)
  void loadGame(std::string fileName);
  std::string getFileType(std::string fileName);

private:

};

#endif // IOSTREAM