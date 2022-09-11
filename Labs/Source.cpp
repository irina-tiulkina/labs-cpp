#include <string>
#include <locale.h>
#include "../UserControl/L1.h"
#include "../UserControl/UserInterfaceClaim.h"
#include "../ConsoleWorkLib/SimpleConsoleFunction.cpp"
#include <L2.h>

const std::string exitNum = "0";
const std::string labOneNum = "1";
const std::string labTwoNum = "2";

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL, "Russian");


  while (true) {
    L1 lab1;
    L2 lab2;

    std::string menu = "Меню: \n";
    std::string exitMenu = exitNum + ". Выйти из программы\n";
    std::string labMenuOne = labOneNum + ". " + lab1.GetTitleTask() + "\n";
    std::string labMenuTwo = labTwoNum + ". " + lab2.GetTitleTask() + "\n";
    scf_t::StringToConsole(menu + exitMenu + labMenuOne + labMenuTwo);

    scf_t::StringToConsole("Выберете пункт меню:");
    std::string selectNum = scf_t::StringFromConsoleByLine();

    if (selectNum == exitNum) {
      return 0;
    }

    if (selectNum == labOneNum) {
      lab1.AboutProgrammToConsole();
      lab1.StartCycleProgramm();
      continue;
    }

    if (selectNum == labTwoNum) {
      lab2.AboutProgrammToConsole();
      lab2.StartCycleProgramm();
      continue;
    }

    scf_t::InfoTextToConsole("Введено некорректное значение. Попробуйте снова");
  }
  return 0;
}