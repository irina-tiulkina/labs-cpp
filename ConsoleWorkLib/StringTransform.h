#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

class StringTransform
{
public:
  static std::string Replace(const std::string& text, char oldVal, const std::string& newVal);
  static std::vector<std::string> Split(const std::string& s, char delim);
};

typedef StringTransform st_t;
