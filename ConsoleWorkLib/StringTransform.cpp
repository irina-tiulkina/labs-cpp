#include "pch.h"
#include "StringTransform.h"

std::string StringTransform::Replace(const std::string& text, char oldVal, const std::string& newVal)
{
  std::string s = text;
  size_t pos;
  while ((pos = s.find(oldVal)) != std::string::npos) {
    s.replace(pos, 1, newVal);
  }
  return s;
}

std::vector<std::string> StringTransform::Split(const std::string& s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

