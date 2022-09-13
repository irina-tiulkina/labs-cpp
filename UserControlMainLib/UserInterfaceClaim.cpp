#include "pch.h"
#include "UserInterfaceClaim.h"

namespace UserControlMainLib {
  std::string UserInterfaceClaim::GetTitleTask() const
  {
    return TaskInfos.GetTitleTask();
  }

  void UserInterfaceClaim::AboutProgrammToConsole() const
  {
    //scf_t::StringToConsole("� ���������: ");
    GetTextInfosLib::SimpleConsoleFunction::StringToConsole(TaskInfos.GetAboutTask());
  }

  void UserInterfaceClaim::CycleProgramm(
    const std::function<std::string(std::string)>& taskFunc,
    const std::string& infoForGetDataFromFile,
    const std::string& infoForGetDataFromConsole
  ) const
  {
    //2.3.(2) ������������� ���������

    while (true) {

      // 2.4.4 (1) �������� �������� ������ �� ����� / �������
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("������� " + _inputDataFromFileNum + " ���� ������ �������� ������ �� �����, ���� �� ������� ����� ������ ������/������");

      std::string inputData = GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _inputDataFromFileNum ?
        UserInterfaceClaim::GetInputDataFromFile(infoForGetDataFromFile) : UserInterfaceClaim::GetInputDataFromConsole(infoForGetDataFromConsole);

      // 2.4.4 (1) ��������� �������� ������ � ����
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("������� " + _saveDataToFileNum + " ���� ������ ��������� �������� ������ � ����, ����� ����� ������ ������/������");
      if (GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _saveDataToFileNum) {
        SaveDataToFile(inputData);
      }

      // 3. ���������� ������
      std::string resultData = "";
      try {
        resultData = taskFunc(inputData);
        GetTextInfosLib::SimpleConsoleFunction::StringToConsole("���������:");
        GetTextInfosLib::SimpleConsoleFunction::StringToConsole(resultData);
      }
      catch (std::exception err) {
        GetTextInfosLib::SimpleConsoleFunction::ErrorTextToConsole(err.what());
        if (IsExitToMainMenu())
          return;
        continue;
      }

      // 2.4.4 (1) ��������� ��������� ������ � ����
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("������� " + _saveDataToFileNum + " ���� ������ ��������� ��������� � ����, ����� ����� ������ ������/������");
      if (GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _saveDataToFileNum) {
        SaveDataToFile(resultData);
      }

      // 2.3.(2) ������������� ��������� ����� �� ���������
      if (IsExitToMainMenu())
        return;
      continue;
    }
  }

  UserInterfaceClaim::UserInterfaceClaim(const TaskInfo& taskInfo)
  {
    TaskInfos = taskInfo;
  };

  bool UserInterfaceClaim::RestoreFile() const
  {
    GetTextInfosLib::SimpleConsoleFunction::StringToConsole("����� ���� ��� ���������. ������� " + _restoreFileNum + " ����� ������������ ����, ����� ������ ���� � ����� ������ - ����� ������ ������ ");
    return GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _restoreFileNum;
  }

  bool UserInterfaceClaim::IsExitToMainMenu() const
  {
    GetTextInfosLib::SimpleConsoleFunction::StringToConsole("������� " + _exitProgrammNum + " ���� ������ ����� �� ���������, ����� ����� ������ ������/������");
    return GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _exitProgrammNum;
  }

  std::string UserInterfaceClaim::GetInputDataFromFile(const std::string& infoForGetDataFromFile) const
  {
    while (true) {
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("������� ������ ���� � �����: ");
      GetTextInfosLib::SimpleConsoleFunction::InfoTextToConsole(infoForGetDataFromFile);
      std::string fullFilePath = GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine();

      try {
        std::string inputData = GetTextInfosLib::SimpleFileFunctions::GetStringFromFile(fullFilePath);
        GetTextInfosLib::SimpleConsoleFunction::StringToConsole(inputData);
        return inputData;
      }
      catch (...) {
        GetTextInfosLib::SimpleConsoleFunction::ErrorTextToConsole(_proscessGetDataFromFileError);
        continue;
      }
    }
  }

  std::string UserInterfaceClaim::GetInputDataFromConsole(const std::string& infoForGetDataFromConsole) const
  {
    GetTextInfosLib::SimpleConsoleFunction::StringToConsole("������� �����");
    GetTextInfosLib::SimpleConsoleFunction::InfoTextToConsole(infoForGetDataFromConsole);
    std::string line = GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine();
    while (line[line.size() - 1] != '$') {

      line += +"\n" + GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine();
    }
    line.pop_back();

    return line;
  }

  void UserInterfaceClaim::SaveDataToFile(std::string inputText) const
  {
    while (true) {
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("������� ������ ���� � �����: ");
      std::string fullFilePath = GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine();

      // �������� �� ������������� �����
      if (GetTextInfosLib::SimpleFileFunctions::FileExists(fullFilePath) && !RestoreFile()) {
        continue;
      }

      try {
        GetTextInfosLib::SimpleConsoleFunction::InfoTextToConsole("���� �����������...");
        GetTextInfosLib::SimpleFileFunctions::SaveStringToFile(inputText, fullFilePath);
        GetTextInfosLib::SimpleConsoleFunction::InfoTextToConsole("���� ���������� �������");
        return;
      }
      catch (...) {
        GetTextInfosLib::SimpleConsoleFunction::ErrorTextToConsole(_processFileSaveError);
        continue;
      }
    }
  }

}
