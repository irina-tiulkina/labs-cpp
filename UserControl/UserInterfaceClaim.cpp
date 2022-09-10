#include "pch.h"
#include "UserInterfaceClaim.h"

std::string UserInterfaceClaim::GetTitleTask() const
{
  return TaskInfos.GetTitleTask();
}

void UserInterfaceClaim::AboutProgrammToConsole() const
{
  //scf_t::StringToConsole("� ���������: ");
  scf_t::StringToConsole(TaskInfos.GetAboutTask());
}

void UserInterfaceClaim::CycleProgramm(const std::function<std::string(std::string)>& taskFunc) const
{
  //2.3.(2) ������������� ���������

  while (true) {

    // 2.4.4 (1) �������� �������� ������ �� ����� / �������
    scf_t::StringToConsole("������� " + _inputDataFromFileNum + " ���� ������ �������� ������ �� �����, ���� �� ������� ����� ������ ������/������");

    std::string inputData = scf_t::StringFromConsoleByLine() == _inputDataFromFileNum ? uic_t::GetInputDataFromFile() : uic_t::GetInputDataFromConsole();

    // 2.4.4 (1) ��������� �������� ������ � ����
    scf_t::StringToConsole("������� " + _saveDataToFileNum + " ���� ������ ��������� �������� ������ � ����, ����� ����� ������ ������/������");
    if (scf_t::StringFromConsoleByLine() == _saveDataToFileNum) {
      SaveDataToFile(inputData);
    }

    // 3. ���������� ������
    std::string resultData = "";
    try {
      resultData = taskFunc(inputData);
      scf_t::StringToConsole("���������:");
      scf_t::StringToConsole(resultData);
    }
    catch(std::exception err) {
      scf_t::ErrorTextToConsole(err.what());
      if (IsExitToMainMenu())
        return;
      continue;
    }
    
    // 2.4.4 (1) ��������� ��������� ������ � ����
    scf_t::StringToConsole("������� " + _saveDataToFileNum + " ���� ������ ��������� ��������� � ����, ����� ����� ������ ������/������");
    if (scf_t::StringFromConsoleByLine() == _saveDataToFileNum) {
      SaveDataToFile(resultData);
    }

    // 2.3.(2) ������������� ��������� ����� �� ���������
    if (IsExitToMainMenu())
      return;
    continue;
  }
}

UserInterfaceClaim::UserInterfaceClaim(const TaskInfo &taskInfo)
{
  TaskInfos = taskInfo;
};

bool UserInterfaceClaim::RestoreFile() const
{
  scf_t::StringToConsole("����� ���� ��� ���������. ������� " + _restoreFileNum + " ����� ������������ ����, ����� ������ ���� � ����� ������ - ����� ������ ������ ");
  return scf_t::StringFromConsoleByLine() == _restoreFileNum;
}

bool UserInterfaceClaim::IsExitToMainMenu() const
{
  scf_t::StringToConsole("������� " + _exitProgrammNum + " ���� ������ ����� �� ���������, ����� ����� ������ ������/������");
  return scf_t::StringFromConsoleByLine() == _exitProgrammNum;
}

std::string UserInterfaceClaim::GetInputDataFromFile() const
{
  while (true) {
    scf_t::StringToConsole("������� ������ ���� � �����: ");
    std::string fullFilePath = scf_t::StringFromConsoleByLine();

    try {
      std::string inputData = sff_t::GetStringFromFile(fullFilePath);
      scf_t::StringToConsole(inputData);
      return inputData;
    }
    catch (...) {
      scf_t::ErrorTextToConsole(_proscessGetDataFromFileError);
      continue;
    }
  }
}

std::string UserInterfaceClaim::GetInputDataFromConsole() const
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

void UserInterfaceClaim::SaveDataToFile(std::string inputText) const
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
      scf_t::ErrorTextToConsole(_processFileSaveError);
      continue;
    }
  }
}
