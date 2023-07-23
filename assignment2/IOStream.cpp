#include "IOStream.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "LinkedList.h"

IOStream::IOStream() {
  // We need anything? 

}

IOStream::~IOStream() {
  // Delete

}

template<class T>
bool IOStream::saveGame(T content, std::string fileName) {

  bool successStatus = false;
  std::ofstream file;
  std::string fileType = getFileType(fileName);
  int c;
  int i = 0;
  if (fileType != "save")
  {
    std::cerr << "Incorrect Filetype entered" << std::endl;
  }
  else
  {
    try
    {
      file.open(fileName);
      while (i < contents.size())
      {
        // Save to file
        // c = contents ??
        file.put(c);
        i++;
      }
      file.close();
      successStatus = true;
    }
    catch (const std::filesystem::filesystem_error& e)
    {
      std::cerr << e.what() << '\n';
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }

  }

  return successStatus;
}

void IOStream::loadGame(std::string fileName) {
  // Possibly save to string and return string?
  std::ifstream file;
  std::string fileType = getFileType(fileName);
  LinkedList gameContents = LinkedList();
  char c;
  if (fileType != "save")
  {
    std::cerr << "Incorrect Filetype entered" << std::endl;
  }
  else
  {
    try
    {
      file.open(fileName);
      while ((c = file.get()) != EOF)
      {
        // Not sure if vector of vectors or linkedList is the best approach.
      }

      file.close();
    }
    catch (const std::filesystem::filesystem_error& e)
    {
      std::cerr << e.what() << '\n';
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }

  }

}

// Gets file type from a passed string
std::string IOStream::getFileType(std::string fileName)
{
  int stopLocation = fileName.find_first_of('.');
  std::string fileType = fileName.substr(stopLocation + 1, fileName.size() - stopLocation);
  return fileType;
}
