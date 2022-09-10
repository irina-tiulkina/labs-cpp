#pragma once
#include "UserInterfaceClaim.h"
#include "../ConsoleWorkLib/SimpleConsoleFunction.h"
#include "../ConsoleWorkLib/SimpleFileFunctions.h"
#include "../ConsoleWorkLib/StringTransform.h"
#include <vector>

class L1 : public UserInterfaceClaim
{
private:
  std::string GetStrWithoutSimbols(const std::string& s, const char& c) const;
 
protected:
  /// <summary>
  ///  ��� ������� ������������ ������
  /// </summary>
  /// <param name="inputDataInString">������� ������ ���������� �� �����/�������</param>
  /// <returns>���������� ��������� ������ ���������, �������� ������������ ������, � ���� ������ ��� ������ � �������/����</returns>
  std::string ProgrammFunction(const std::string& inputDataInString) const;
public:
  void StartCycleProgramm() const override;
  L1(TaskInfo task) : UserInterfaceClaim{task} {};
  ~L1() {};
};

