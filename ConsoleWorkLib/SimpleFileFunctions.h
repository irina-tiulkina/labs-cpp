#pragma once
#include <string>
#include <iostream>
#include <fstream>

class SimpleFileFunctions
{
private:
  static const std::string inputFilePath;
  static const std::string resutFilePath;
public:
  static void SaveStringToFile(const std::string& text);
  static std::string GetStringFromFile();
};

typedef SimpleFileFunctions sff_t;