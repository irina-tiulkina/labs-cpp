#include "pch.h"
#include "SimpleConsoleFunction.h"

void scf_t::StringToConsole(const std::string& text)
{
  std::cout << text << std::endl;
}

std::string scf_t::StringFromConsoleByLine()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  std::string str;
  std::getline(std::cin, str);
  return str;
}

void scf_t::ErrorTextToConsole(const std::string& text)
{
  SetColor(ConsoleColor::LightRed, ConsoleColor::Black);
  StringToConsole(text);
  SetStandartColor();
}

void scf_t::InfoTextToConsole(const std::string& text)
{
  SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
  StringToConsole(text);
  SetStandartColor();
}

void scf_t::ColorTextToConsole(const std::string& text, ConsoleColor color)
{
  SetColor(color, ConsoleColor::Black);
  StringToConsole(text);
  SetStandartColor();
}

void scf_t::SetColor(ConsoleColor text, ConsoleColor background)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
}

void SimpleConsoleFunction::SetStandartColor()
{
  SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
}
