#include "TransformText.h"

std::string TransformText::GetTransformedText(std::string text)
{
  std::vector<std::string> newText = Split(text, ' ');
  std::string newStr = "";

  for (int i = 0; i < newText.size(); i++) {
    newStr += newText[i] + "!";
  }
  return newStr;
}

std::vector<std::string> TransformText::Split(const std::string& s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}
