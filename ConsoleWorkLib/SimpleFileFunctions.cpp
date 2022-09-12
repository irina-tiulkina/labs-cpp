#include "pch.h"
#include "SimpleFileFunctions.h"



void sff_t::SaveStringToFile(const std::string& text, const std::string& path)
{
  std::ofstream out; // поток для записи
  out.open(path); // окрываем файл для записи
  if (out.is_open())
  {
    out << text << std::endl;
  }
  else {
    throw "Не получилось сохранить файл";
  }
  out.close();
}

std::string sff_t::GetStringFromFile(const std::string& path)
{
  std::ifstream in(path); // окрываем файл для чтения
  std::string str = "";
  if (in.is_open())
  {
    std::string line;
    while (std::getline(in, line))
    {
      //std::cout << line << std::endl;
      str += line + '\n';
    }
  }
  else {
    throw "Не получилось открыть файл, убедитесь что файл существует ";
  }
  in.close();     // закрываем файл

  return str;
}

bool sff_t::FileExists(const std::string& path)
{
  bool isExist = false;
  std::ifstream fin(path);

  if (fin.is_open())
    isExist = true;

  fin.close();
  return isExist;
}

// Проверка на атрибуты файла, если файл который вы хотите использовать 
// м.б. открыт только в режиме чтения возвращает false, иначе true
bool sff_t::IsReadOnlyFile(const std::string& path) {
  WIN32_FIND_DATAA findData;
  LPCSTR name = path.c_str();
  FindFirstFileA(name, &findData);
  if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
    return true;
  }
  else 
    return false;
}