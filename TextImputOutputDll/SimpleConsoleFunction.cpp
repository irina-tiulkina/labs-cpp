#include "pch.h"
#include "SimpleConsoleFunction.h"

void SimpleConsoleFunction::StringToConsole(std::string text)
{
  std::cout << text << std::endl;
}

std::string SimpleConsoleFunction::StringFromConsoleByWord()
{
  std::string str;
  std::cin >> str;
  return str;
}

std::string SimpleConsoleFunction::StringFromConsoleByLine()
{
  std::string str;
  std::getline(std::cin, str);
  return str;
}
