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
 ///  Для решения поставленной задачи
 /// </summary>
 /// <param name="inputDataInString">входные данные полученные из файла/консоли</param>
 /// <returns>Возвращает результат работы программы, решающей поставленную задачу, в виде строки для записи в консоль/файл</returns>
  std::string ProgrammFunction(const std::string& inputDataInString) const;

  void StartCycleProgramm() const override;
  LabOne(TaskInfo task) : UserInterfaceClaim{ task } {};
  LabOne() : UserInterfaceClaim{ TaskInfo() } {};
  ~LabOne() {};
};

