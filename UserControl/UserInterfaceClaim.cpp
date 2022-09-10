#include "pch.h"
#include "UserInterfaceClaim.h"

void UserInterfaceClaim::AboutProgrammToConsole()
{
  //scf_t::StringToConsole("� ���������: ");
  scf_t::StringToConsole(TaskInfos.GetAboutTask());
}

void UserInterfaceClaim::CycleProgramm()
{
  //2.3.(2) ������������� ���������
  bool isExitProgram = false;
  while (!isExitProgram) {

    // 2.4.4 (1) �������� �������� ������ �� ����� / �������
    scf_t::StringToConsole("������� " + InputDataFromFileNum + " ���� ������ �������� ������ �� �����, ���� �� ������� ����� ������ ������/������");

    std::string inputData = scf_t::StringFromConsoleByLine() == InputDataFromFileNum ? uic_t::GetInputDataFromFile() : uic_t::GetInputDataFromConsole();

    // 2.4.4 (1) ��������� �������� ������ � ����
    scf_t::StringToConsole("������� " + SaveDataToFileNum + " ���� ������ ��������� �������� ������ � ����, ����� ����� ������ ������/������");
    if (scf_t::StringFromConsoleByLine() == SaveDataToFileNum) {
      SaveDataToFile(inputData);
    }

    // 3. ���������� ������
    std::string resultData = "";
    try {
      resultData = uic_t::ProgrammFunction(inputData);
    }
    catch(std::exception err) {
      scf_t::ErrorTextToConsole(err.what());
      isExitProgram = IsExitToMainMenu();
      continue;
    }
    
    // 2.4.4 (1) ��������� ��������� ������ � ����
    scf_t::StringToConsole("������� " + SaveDataToFileNum + " ���� ������ ��������� ��������� � ����, ����� ����� ������ ������/������");
    if (scf_t::StringFromConsoleByLine() == SaveDataToFileNum) {
      SaveDataToFile(resultData);
    }

    // 2.3.(2) ������������� ��������� ����� �� ���������
    isExitProgram = IsExitToMainMenu();
    continue;
  }
}

bool UserInterfaceClaim::RestoreFile()
{
  scf_t::StringToConsole("����� ���� ��� ���������. ������� " + RestoreFileNum + " ����� ������������ ����, ����� ������ ���� � ����� ������ - ����� ������ ������ ");
  return scf_t::StringFromConsoleByLine() == RestoreFileNum;
}

bool UserInterfaceClaim::IsExitToMainMenu()
{
  scf_t::StringToConsole("������� " + ExitProgrammNum + " ���� ������ ����� �� ���������, ����� ����� ������ ������/������");
  return scf_t::StringFromConsoleByLine() == ExitProgrammNum;
}

std::string UserInterfaceClaim::GetInputDataFromFile()
{
  while (true) {
    scf_t::StringToConsole("������� ������ ���� � �����: ");
    std::string fullFilePath = scf_t::StringFromConsoleByLine();

    try {
      std::string inputData = sff_t::GetStringFromFile(fullFilePath);
      return inputData;
    }
    catch (...) {
      scf_t::ErrorTextToConsole(ProscessGetDataFromFileError);
      continue;
    }
  }
}

std::string UserInterfaceClaim::GetInputDataFromConsole()
{
  scf_t::StringToConsole("������� �����");
  scf_t::InfoTextToConsole("(����� ��������� �����������, ���� � ����� ������ ����� $)");
  std::string line = scf_t::StringFromConsoleByLine();
  while (line[line.size() - 1] != '$') {

    line += +"\n" + scf_t::StringFromConsoleByLine();
  }
  line.pop_back();

  return line;
}

void UserInterfaceClaim::SaveDataToFile(std::string inputText)
{
  while (true) {
    scf_t::StringToConsole("������� ������ ���� � �����: ");
    std::string fullFilePath = scf_t::StringFromConsoleByLine();
    
    // �������� �� ������������� �����
    if (sff_t::FileExists(fullFilePath) && !RestoreFile()) {
      continue;
    }

    try {
      sff_t::SaveStringToFile(inputText, fullFilePath);
      return;
    }
    catch(...){
      scf_t::ErrorTextToConsole(ProcessFileSaveError);
      continue;
    }
  }
}
