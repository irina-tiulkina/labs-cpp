/*
17. ����� �����. ��������� ����� ����� �� ���� ��������� �� ��������: 
������ ����� ������ ������ ������� �� ��������� ���� ���� ��������� 
������, ������ ����� �� ������������� ���� � ��� �����.
*/

#include <iostream>
#include "TransformText.h"
#include "SimpleConsoleFunction.h"
#include "SimpleFileFunctions.h"

const std::string fileNum = "1";
const std::string ignoreSimbNum = "1";
const std::string exitProgrammNum = "1";

std::string GetTextFromFile();
std::string GetTextFromConsole();
void SaveFile(const std::string& textResult);
void InfoConsole();
bool IsExitProgramm();

int main() {
  setlocale(LC_ALL, "Russian"); // ������� ����������� �������

  // 2.3.1 ���������� � ���������
  InfoConsole();

  bool isStartProgramm = true;

  // 2.3.2 ��������� ������������ 
  while (isStartProgramm) {
    scf_t::StringToConsole("������� " + fileNum + ", ���� ���� �� �����. ���� �� ������� - ����� ������ ������/������");
    bool isInputDataFromFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;

    std::string text;
    try {
      // 2.4.4.1 ������� �������� ������ �� �����
      text = isInputDataFromFile ? GetTextFromFile() : GetTextFromConsole();
    }
    catch (const char* msg) {
      scf_t::ErrorTextToConsole(msg);
      if (IsExitProgramm())
        return;
      else {
        continue;
      }
    }

    // 2.4.4.1 ��������� �������� ������ � ����� (���� �������)
    if (!isInputDataFromFile) {
      scf_t::StringToConsole("���� �������� ��������� �������� ������ � ���� ������� " + fileNum + ", ����� ����� ������ �����");
      bool isInputDataSaveToFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;
      if (isInputDataSaveToFile) {
        SaveFile(text);
      }
    }

    scf_t::StringToConsole("\n������� " + ignoreSimbNum + ", ���� ����� ������������ ������� �������� �� ����, ����� ����� ������ ������/������");
    bool isIgnoreSimbols = scf_t::StringFromConsoleByLine() == ignoreSimbNum ? true : false;

    std::string transformedString = TransformText::GetTransformedText(text, isIgnoreSimbols);

    scf_t::StringToConsole("\n���������� �����:");
    scf_t::StringToConsole(transformedString);

    // 2.4.4.1 ��������� �������� � ����
    scf_t::StringToConsole("\n���� ������ ��������� � ���� ������� 1, ����� ����� ������ �������");
    bool isResultDataSaveFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;
    if (isResultDataSaveFile) {
      SaveFile(transformedString);
    }

    //scf_t::StringToConsole("\n���������� ��������� ���������");

    // 2.3.2 ���������������, ����� ������ ���� ��� ����������
    isStartProgramm = IsExitProgramm();
  }
  
  return 0;
}

bool IsExitProgramm() {
  scf_t::StringToConsole("���� ������ ��������� ��������� �������� " + exitProgrammNum + ", ����� ����� ������ ������/������");
  bool isExit = scf_t::StringFromConsoleByLine() == exitProgrammNum ? true : false;
  return isExit;
}

std::string GetTextFromFile() {
  //scf_t::StringToConsole("������� ���� � �����:");
  //std::string filePath = scf_t::StringFromConsoleByLine();
  std::string str;
    str = sff_t::GetStringFromFile();
    return str;
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

void InfoConsole() {
  scf_t::StringToConsole("������������ ������ 1");
  std::string zadacha = "������: ����� �����. ��������� ����� ����� �� ���� ��������� �� ��������:\n ������ ����� ������ ������ ������� �� ��������� ���� ���� ���������\n ������, ������ ����� �� ������������� ���� � ��� �����.";
  scf_t::StringToConsole(zadacha);
  scf_t::StringToConsole("�����: �������� ����� ��������");
  scf_t::StringToConsole("������: 494 ����: 4");
  scf_t::StringToConsole("� ���������� ��������� �������� �����");
}

void SaveFile(const std::string& textResult) {

  /*scf_t::StringToConsole("������� ���� � �����:");
  std::string filePath = scf_t::StringFromConsoleByLine();*/

  try {
    scf_t::InfoTextToConsole("���� ���������� � ����...");
    sff_t::SaveStringToFile(textResult);
    scf_t::InfoTextToConsole("���� ������� ��������");
  }
  catch (const char* msg) {
    scf_t::ErrorTextToConsole(msg);
    throw msg;
  }
}