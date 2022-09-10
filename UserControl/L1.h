#pragma once
#include "UserInterfaceClaim.h"

class L1 : uic_t
{
private:
  std::string GetStrWithoutSimbols(const std::string& s);

protected:
  std::string ProgrammFunction(const std::string& inputDataInString) override;
};

