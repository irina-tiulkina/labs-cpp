#pragma once
#include <string>
#include "TaskInfo.h"
#include <iostream>
#include <functional>
#include "../ConsoleWorkLib/SimpleConsoleFunction.cpp"
#include "../ConsoleWorkLib/SimpleFileFunctions.h"

class UserInterfaceClaim
{
private:

  // ������ ����
  const std::string _inputDataFromFileNum = "1"; // 2.4.4 (1) ����� ���� ��� ����������� ��������� ������ �� �����
  const std::string _saveDataToFileNum = "1"; // 2.4.4 (1) ����� ���� ��� ����������� ���������� ������ � ����
  const std::string _restoreFileNum = "1"; // 2.4.4 (3) ����� ���� ��� ���������� �����
  const std::string _exitProgrammNum = "1"; // 2.3 (2) ����� ���� ��� ������ �� ���������

  /// <summary>
  /// 2.3.(1) ��� ��������� ���������� � ��������� / ������ / ������
  /// </summary>
  TaskInfo  TaskInfos;

  /// <summary>
  /// 2.4 (1) ��� ��������� ������ ���������� �����
  /// </summary>
  const std::string _processFileSaveError = "������ ��� ���������� �����. ��������� ���� � �����";

  /// <summary>
  /// 2.4 (1) ��� ��������� ������ ��������� ������ �� �����
  /// </summary>
  const std::string _proscessGetDataFromFileError = "������ ��� ��������� ������ �� �����. ��������� ���� � �����";

  /// <summary>
  /// 2.4.4 (3) ������������ ���� ���� ����� ���������� 
  /// </summary>
  /// <returns></returns>
  bool RestoreFile() const;

  bool IsExitToMainMenu() const;

protected:

  /// <summary>
  /// 2.4.4 (1) ������� �������� ������ �� �����
  /// </summary>
  /// <returns>������� ������ � ���� ������</returns>
  std::string GetInputDataFromFile(const std::string& infoForGetDataFromFile) const;
  std::string GetInputDataFromConsole(const std::string& infoForGetDataFromConsole) const;

  /// <summary>
 /// 2.4.4 (1) ��������� �������� ������ � ����, ��������� ��������� ������ � ����
 /// </summary>
 /// <param name="inputText">�������� ����� ��� ����������</param>
  void SaveDataToFile(std::string str) const;

  /// <summary>
  /// 2.3.(2) ������������� ���������
  /// </summary>
  void CycleProgramm
  (
    const std::function<std::string(std::string)>& taskFunc,
    const std::string& infoForGetDataFromFile,
    const std::string& infoForGetDataFromConsole
  ) const;

public:

  std::string GetTitleTask() const;

  /// <summary>
  /// 2.3.(1) � ��������� (����������, �����, ������, ��������� )
  /// </summary>
  void AboutProgrammToConsole() const;
  virtual void StartCycleProgramm() const = 0;
  UserInterfaceClaim(const TaskInfo& taskInfo);
  virtual ~UserInterfaceClaim() {};
};

typedef UserInterfaceClaim uic_t;