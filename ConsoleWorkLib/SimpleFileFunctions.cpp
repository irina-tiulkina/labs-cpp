#include "pch.h"
#include "SimpleFileFunctions.h"


const std::string sff_t::inputFilePath = "input.txt";
const std::string sff_t::resutFilePath = "result.txt";

void SimpleFileFunctions::SaveStringToFile(const std::string& text)
{
  std::ofstream out;          // поток для записи
  out.open(resutFilePath); // окрываем файл для записи
  if (out.is_open())
  {
    out << text << std::endl;
  }
  else {
    throw "Не получилось сохранить файл";
  }
  out.close();
}

std::string SimpleFileFunctions::GetStringFromFile()
{
  std::ifstream in(sff_t::inputFilePath); // окрываем файл для чтения
  std::string line;
  if (in.is_open())
  {
    while (std::getline(in, line))
    {
      std::cout << line << std::endl;
    }
  }
  else {
    throw "Не получилось открыть файл, убедитесь что файл существует ";
  }
  in.close();     // закрываем файл

  return line;
}
