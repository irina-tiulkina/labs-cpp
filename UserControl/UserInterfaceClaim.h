#pragma once
#include <string>
#include "TaskInfo.h"
#include "SimpleConsoleFunction.h"
#include "SimpleFileFunctions.h"
#include "StringTransform.h"

class UserInterfaceClaim
{
private:

  // ������ ����
  const std::string InputDataFromFileNum = "1"; // 2.4.4 (1) ����� ���� ��� ����������� ��������� ������ �� �����
  const std::string SaveDataToFileNum = "1"; // 2.4.4 (1) ����� ���� ��� ����������� ���������� ������ � ����
  const std::string RestoreFileNum = "1"; // 2.4.4 (3) ����� ���� ��� ���������� �����
  const std::string ExitProgrammNum = "1"; // 2.3 (2) ����� ���� ��� ������ �� ���������

  /// <summary>
  /// 2.3.(1) ��� ��������� ���������� � ��������� / ������ / ������
  /// </summary>
  TaskInfo  TaskInfos;

  /// <summary>
  /// 2.4 (1) ��� ��������� ������ ���������� �����
  /// </summary>
  const std::string ProcessFileSaveError = "������ ��� ���������� �����. ��������� ���� � �����";

  /// <summary>
  /// 2.4 (1) ��� ��������� ������ ��������� ������ �� �����
  /// </summary>
  const std::string ProscessGetDataFromFileError = "������ ��� ��������� ������ �� �����. ��������� ���� � �����";

  /// <summary>
  /// 2.4.4 (3) ������������ ���� ���� ����� ���������� 
  /// </summary>
  /// <returns></returns>
  bool RestoreFile();

  bool IsExitToMainMenu();

protected:

  UserInterfaceClaim(TaskInfo taskInfo) {
    TaskInfos = taskInfo;
  };

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
  virtual std::string ProgrammFunction(const std::string& inputDataInString) = 0;

public:
  
  std::string GetTitleTask() { return TaskInfos.GetTitleTask(); }

  /// <summary>
  /// 2.3.(1) � ��������� (����������, �����, ������, ��������� )
  /// </summary>
  void AboutProgrammToConsole();

  /// <summary>
  /// 2.3.(2) ������������� ���������
  /// </summary>
  void CycleProgramm();

};

typedef UserInterfaceClaim uic_t;