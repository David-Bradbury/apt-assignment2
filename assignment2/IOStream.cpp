#include "IOStream.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "LinkedList.h"
#include <string>
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
  // char c;
  // int i = 0;
    // try
    // {
  file.open(save);
  // while (i < data.size())
  // {
  //   // Save to file
  //   // c = contents ??
  //   file.put(c);
  //   i++;
  // }
  std::cout << "Before input" << std::endl;
  // file << "WHY";
  std::cout << "after save" << std::endl;
  // while (!stream.eof())
  // {
    //   // Save to file
    //   // c = contents ??
    //   // getline(stream, '/n');
    //   // file.app(getline(stream, '/n'));
    // file.app(stream.get(c));
  file << data;
  //   // i++;
// }
  file.close();
  successStatus = true;
  // }
  // catch (const std::filesystem::filesystem_error& e)
  // {
  //   std::cerr << e.what() << '\n';
  // }
  // catch (const std::exception& e)
  // {
  //   std::cerr << e.what() << '\n';
  // }

  std::cout << "end of function" << std::endl;
  return successStatus;
}

void IOStream::loadGame(std::string fileName) {
  // Possibly save to string and return string?
  std::fstream file;
  std::string fileType = getFileType(fileName);
  std::string save = "saved_games/";
  save.append(fileName);
  // LinkedList gameContents = LinkedList();
  char c;
  if (fileType != "save")
  {
    std::cerr << "Incorrect Filetype entered" << std::endl;
  }
  else
  {
    // try
    // {
    file.open(save);
    while ((c = file.get()) != EOF)
    {
      // Not sure if vector of vectors or linkedList is the best approach.
    }

    file.close();
    // }
    // catch (const std::filesystem::filesystem_error& e)
    // {
    //   std::cerr << e.what() << '\n';
    // }
    // catch (const std::exception& e)
    // {
    //   std::cerr << e.what() << '\n';
    // }

  }

}

// Gets file type from a passed string
std::string IOStream::getFileType(std::string fileName)
{
  int stopLocation = fileName.find_first_of('.');
  std::string fileType = fileName.substr(stopLocation + 1, fileName.size() - stopLocation);
  return fileType;
}

LinkedList getTileBag(std::string tiles)
{
  LinkedList tileBag;
  // std::stringstream stream;
  // stream.str(tiles);
  // std::string tempTile = "";
  // while (!stream.eof())
  // {

  //   // Shape shape = stream >>
  //   //   tileBag.addFront();
  // }
  // // 

  return tileBag;
}