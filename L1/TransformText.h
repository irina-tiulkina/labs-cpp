#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class TransformText
{
private:
  static std::vector<std::string> Split(const std::string& s, char delim);
public:
  static std::string GetTransformedText(std::string text);
};

