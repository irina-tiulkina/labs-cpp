#include <string>
#include "SimpleConsoleFunction.h"

const std::string exitNum = "0";
const std::string labOneNum = "1";

int main() {
  setlocale(LC_ALL, "Russian");
  bool isExit = false;
  while (!isExit) {
    std::string menu = "Меню: \n";
    std::string exitMenu = exitNum + ". Выйти из программы\n";
    std::string labMenuOne = labMenuOne + ".\n ЛР1";

    scf_t::StringToConsole(menu + exitMenu + labMenuOne);
    std::string selectNum = scf_t::StringFromConsoleByLine();

    isExit = selectNum == exitNum;
    if (isExit) {
      return;
    }

    bool isLab1 = selectNum == labOneNum;
    if (isLab1) {
      // .... Какой-то процесс
      continue;
    }

    scf_t::InfoTextToConsole("Введено некорректное значение. Попробуйте снова");
  }
  return 0;
}