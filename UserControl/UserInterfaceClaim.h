#pragma once
#include <string>
#include "TaskInfo.h"
#include "../ConsoleWorkLib/SimpleConsoleFunction.h"
#include "../ConsoleWorkLib/SimpleFileFunctions.h"
#include "../ConsoleWorkLib/StringTransform.h"

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
  bool RestoreFile();

  bool IsExitToMainMenu();

protected:

  /// <summary>
  /// 2.4.4 (1) ������� �������� ������ �� �����
  /// </summary>
  /// <returns>������� ������ � ���� ������</returns>
  virtual std::string GetInputDataFromFile();
  virtual std::string GetInputDataFromConsole();

  /// <summary>
/// 2.4.4 (1) ��������� �������� ������ � ����, ��������� ��������� ������ � ����
/// </summary>
/// <param name="inputText">�������� ����� ��� ����������</param>
  void SaveDataToFile(std::string str);


  /// <summary>
  ///  ��� ������� ������������ ������
  /// </summary>
  /// <param name="inputDataInString">������� ������ ���������� �� �����/�������</param>
  /// <returns>���������� ��������� ������ ���������, �������� ������������ ������, � ���� ������ ��� ������ � �������/����</returns>
  virtual std::string ProgrammFunction(const std::string& inputDataInString) = 0 { return ""; };

public:
  
  std::string GetTitleTask();

  /// <summary>
  /// 2.3.(1) � ��������� (����������, �����, ������, ��������� )
  /// </summary>
  void AboutProgrammToConsole();

  /// <summary>
  /// 2.3.(2) ������������� ���������
  /// </summary>
  void CycleProgramm();

  UserInterfaceClaim(const TaskInfo &taskInfo);
};

typedef UserInterfaceClaim uic_t;