#include "IOStream.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "LinkedList.h"
#include <sstream>


IOStream::IOStream() {
  // We need anything? 

}


IOStream::~IOStream() {
  // Delete

}


bool IOStream::saveGame(std::string data, std::string fileName) {

  bool successStatus = false;
  std::ofstream file;
  std::string fileType = ".save";
  std::string save = "saved_games/";
  save.append(fileName);
  save.append(fileType);
  std::stringstream stream;

  stream.str(data);

  try {
    file.open(save);
    file << data;
    file.close();
    successStatus = true;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return successStatus;
}

std::string IOStream::loadGame(std::string fileName) {

  std::ifstream file;
  std::string fileType = getFileType(fileName);
  std::string save = "saved_games/";
  save.append(fileName);
  char c;

  std::string game;

  if (fileType != "save") {
    std::cerr << "Incorrect Filetype entered" << std::endl;
  }
  else {

    try {

      file.open(save);
      while ((c = file.get()) != EOF) {
        game += c;
      }

      file.close();
    }
    catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
  }

  return game;
}


std::string IOStream::getFileType(std::string fileName)
{
  int stopLocation = fileName.find_first_of('.');
  std::string fileType = fileName.substr(stopLocation + 1, fileName.size() - stopLocation);
  return fileType;
}