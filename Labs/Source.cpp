#include <string>
#include <locale.h>
#include "../UserControl/L1.h"
#include "../UserControl/UserInterfaceClaim.h"
#include "../ConsoleWorkLib/SimpleConsoleFunction.cpp"

const std::string exitNum = "0";
const std::string labOneNum = "1";

int main() {
  setlocale(LC_ALL, "Russian");

  while (true) {
    TaskInfo task1 = TaskInfo();
    L1 lab1( task1 );

    std::string menu = "����: \n";
    std::string exitMenu = exitNum + ". ����� �� ���������\n";
    std::string labMenuOne = labOneNum + ". " + lab1.GetTitleTask() + "\n";
    scf_t::StringToConsole(menu + exitMenu + labMenuOne);

    scf_t::StringToConsole("�������� ����� ����:");
    std::string selectNum = scf_t::StringFromConsoleByLine();

    if (selectNum == exitNum) {
      return 0;
    }

    if (selectNum == labOneNum) {
      lab1.AboutProgrammToConsole();
      lab1.StartCycleProgramm();
      continue;
    }

    scf_t::InfoTextToConsole("������� ������������ ��������. ���������� �����");
  }
  return 0;
}