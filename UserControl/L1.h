#pragma once
#include "UserInterfaceClaim.h"
#include "../ConsoleWorkLib/SimpleConsoleFunction.h"
#include "../ConsoleWorkLib/SimpleFileFunctions.h"
#include "../ConsoleWorkLib/StringTransform.h"
#include <vector>

class L1 : public UserInterfaceClaim
{
private:
  std::string GetStrWithoutSimbols(const std::string& s);

protected:
  std::string ProgrammFunction(const std::string& inputDataInString) override;

  std::string GetInputDataFromFile() override ;
  std::string GetInputDataFromConsole() override ;
public:
  L1(TaskInfo task) : UserInterfaceClaim{task} {};
};

