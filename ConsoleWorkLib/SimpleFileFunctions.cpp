#include "pch.h"
#include "SimpleFileFunctions.h"


const std::string sff_t::inputFilePath = "input.txt";
const std::string sff_t::resutFilePath = "result.txt";

void SimpleFileFunctions::SaveStringToFile(const std::string& text)
{
  std::ofstream out;          // ����� ��� ������
  out.open(resutFilePath); // �������� ���� ��� ������
  if (out.is_open())
  {
    out << text << std::endl;
  }
  else {
    throw "�� ���������� ��������� ����";
  }
  out.close();
}

std::string SimpleFileFunctions::GetStringFromFile()
{
  std::ifstream in(sff_t::inputFilePath); // �������� ���� ��� ������
  std::string line;
  if (in.is_open())
  {
    while (std::getline(in, line))
    {
      std::cout << line << std::endl;
    }
  }
  else {
    throw "�� ���������� ������� ����, ��������� ��� ���� ���������� ";
  }
  in.close();     // ��������� ����

  return line;
}
