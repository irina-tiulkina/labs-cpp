#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <wtypes.h>
#include <minwinbase.h>

class SimpleFileFunctions
{
private:
public:
  static void SaveStringToFile(const std::string& text, const std::string& path);
  static std::string GetStringFromFile(const std::string& path);
  static bool FileExists(const std::string& path);
  static bool IsReadOnlyFile(const std::string& path);
};

typedef SimpleFileFunctions sff_t;