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
  ///  Для решения поставленной задачи
  /// </summary>
  /// <param name="inputDataInString">входные данные полученные из файла/консоли</param>
  /// <returns>Возвращает результат работы программы, решающей поставленную задачу, в виде строки для записи в консоль/файл</returns>
  std::string ProgrammFunction(const std::string& inputDataInString) const;
public:
  void StartCycleProgramm() const override;
  L1(TaskInfo task) : UserInterfaceClaim{task} {};
  ~L1() {};
};

