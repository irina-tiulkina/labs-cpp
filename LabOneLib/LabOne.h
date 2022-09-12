#pragma once
#include <vector>
#include <string>
#include "../UserControlMainLib/TaskInfo.h"
#include "../UserControlMainLib/UserInterfaceClaim.h"
#include "../ConsoleWorkLib/StringTransform.h"

class LabOne final : public UserInterfaceClaim
{
private:
  std::string GetStrWithoutSimbols(const std::string& s, const char& c) const;

public:
  /// <summary>
 ///  ��� ������� ������������ ������
 /// </summary>
 /// <param name="inputDataInString">������� ������ ���������� �� �����/�������</param>
 /// <returns>���������� ��������� ������ ���������, �������� ������������ ������, � ���� ������ ��� ������ � �������/����</returns>
  std::string ProgrammFunction(const std::string& inputDataInString) const;

  void StartCycleProgramm() const override;
  LabOne(TaskInfo task) : UserInterfaceClaim{ task } {};
  LabOne() : UserInterfaceClaim{ TaskInfo() } {};
  ~LabOne() {};
};

