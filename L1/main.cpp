/*
17. ����� �����. ��������� ����� ����� �� ���� ��������� �� ��������: 
������ ����� ������ ������ ������� �� ��������� ���� ���� ��������� 
������, ������ ����� �� ������������� ���� � ��� �����.
*/

/*
* �������: 
* 1. ��� ������ � ��������� ������ ����
* 2. ��� ������ � '\n'
*/

#include <iostream>
#include "TransformText.h"
#include "SimpleConsoleFunction.h"

std::string GetTextFromFile();
std::string GetTextFromConsole();
void SaveFile();

int main() {
  setlocale(LC_ALL, "Russian"); // ������� ����������� �������
  const std::string fileNum = "1";
  const std::string ignoreSimbNum = "1";

  scf_t::StringToConsole("������� " + fileNum + ", ���� ���� �� �����. ���� �� ������� - ����� ������ ������/������"); // !!!!!
  bool fromFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;

  std::string text;
  try {
     text = fromFile? GetTextFromFile() : GetTextFromConsole();
  }
  catch (std::string msg) {
    scf_t::ErrorTextToConsole("������ ��� ��������� ������: " + msg);
    return 0;
  }

  scf_t::StringToConsole("\n������� " + ignoreSimbNum +", ���� ����� ������������ ������� �������� �� ����, ����� ����� ������ ������/������");
  bool isIgnoreSimbols = scf_t::StringFromConsoleByLine() == ignoreSimbNum ? true : false;

  std::string transformedString = TransformText::GetTransformedText(text, isIgnoreSimbols);

  scf_t::StringToConsole("\n���������� �����:");
  scf_t::StringToConsole(transformedString);

  scf_t::StringToConsole("\n\n\n���� ������ ��������� � ���� ������� 1, ����� ����� ������ �������"); // !!!!
  bool saveFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;
  if (saveFile) {
    SaveFile();
  }
    
  std::cin.get();
  return 0;
}

std::string GetTextFromFile() {
  scf_t::StringToConsole("������� ���� � �����:");
  std::string filePath = scf_t::StringFromConsoleByLine();

  return "file";
}

std::string GetTextFromConsole() {
  scf_t::StringToConsole("������� �����");
  scf_t::InfoTextToConsole("(����� ��������� �����������, ���� � ����� ������ ����� $)");
  std::string line = scf_t::StringFromConsoleByLine();
  while (line[line.size() - 1] != '$') {

    line += +"\n" + scf_t::StringFromConsoleByLine();
  }
  line.pop_back();

  return line;
}

void SaveFile() {
  scf_t::InfoTextToConsole("���� ���������� � ����...");
}