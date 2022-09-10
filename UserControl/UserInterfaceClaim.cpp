#include "pch.h"
#include "UserInterfaceClaim.h"

void UserInterfaceClaim::AboutProgrammToConsole()
{
  //scf_t::StringToConsole("О программе: ");
  scf_t::StringToConsole(TaskInfos.GetAboutTask());
}

void UserInterfaceClaim::CycleProgramm()
{
  //2.3.(2) Зацикленность программы
  bool isExitProgram = false;
  while (!isExitProgram) {

    // 2.4.4 (1) получить исходные данные из файла / консоли
    scf_t::StringToConsole("Введите " + InputDataFromFileNum + " если хотите получить данные из файла, если из консоли любой другой символ/строку");

    std::string inputData = scf_t::StringFromConsoleByLine() == InputDataFromFileNum ? uic_t::GetInputDataFromFile() : uic_t::GetInputDataFromConsole();

    // 2.4.4 (1) сохранить исходные данные в файл
    scf_t::StringToConsole("Введите " + SaveDataToFileNum + " если хотите сохранить исходные данные в файл, иначе любой другой символ/строку");
    if (scf_t::StringFromConsoleByLine() == SaveDataToFileNum) {
      SaveDataToFile(inputData);
    }

    // 3. Выоленнеие задачи
    std::string resultData = "";
    try {
      resultData = uic_t::ProgrammFunction(inputData);
    }
    catch(std::exception err) {
      scf_t::ErrorTextToConsole(err.what());
      isExitProgram = IsExitToMainMenu();
      continue;
    }
    
    // 2.4.4 (1) сохранить результат работы в файл
    scf_t::StringToConsole("Введите " + SaveDataToFileNum + " если хотите сохранить результат в файл, иначе любой другой символ/строку");
    if (scf_t::StringFromConsoleByLine() == SaveDataToFileNum) {
      SaveDataToFile(resultData);
    }

    // 2.3.(2) Зацикленность программы Выход из программы
    isExitProgram = IsExitToMainMenu();
    continue;
  }
}

bool UserInterfaceClaim::RestoreFile()
{
  scf_t::StringToConsole("Такой файл уже существет. Введите " + RestoreFileNum + " чтобы перезаписать файл, чтобы ввести путь к файлу заного - любой другой символ ");
  return scf_t::StringFromConsoleByLine() == RestoreFileNum;
}

bool UserInterfaceClaim::IsExitToMainMenu()
{
  scf_t::StringToConsole("Нажмите " + ExitProgrammNum + " если хотите выйти из программы, иначе любой другой символ/строку");
  return scf_t::StringFromConsoleByLine() == ExitProgrammNum;
}

std::string UserInterfaceClaim::GetInputDataFromFile()
{
  while (true) {
    scf_t::StringToConsole("Введите полный путь к файлу: ");
    std::string fullFilePath = scf_t::StringFromConsoleByLine();

    try {
      std::string inputData = sff_t::GetStringFromFile(fullFilePath);
      return inputData;
    }
    catch (...) {
      scf_t::ErrorTextToConsole(ProscessGetDataFromFileError);
      continue;
    }
  }
}

std::string UserInterfaceClaim::GetInputDataFromConsole()
{
  scf_t::StringToConsole("Введите текст");
  scf_t::InfoTextToConsole("(текст считается законченным, если в конце строки стоит $)");
  std::string line = scf_t::StringFromConsoleByLine();
  while (line[line.size() - 1] != '$') {

    line += +"\n" + scf_t::StringFromConsoleByLine();
  }
  line.pop_back();

  return line;
}

void UserInterfaceClaim::SaveDataToFile(std::string inputText)
{
  while (true) {
    scf_t::StringToConsole("Введите полный путь к файлу: ");
    std::string fullFilePath = scf_t::StringFromConsoleByLine();
    
    // Проверка на существование файла
    if (sff_t::FileExists(fullFilePath) && !RestoreFile()) {
      continue;
    }

    try {
      sff_t::SaveStringToFile(inputText, fullFilePath);
      return;
    }
    catch(...){
      scf_t::ErrorTextToConsole(ProcessFileSaveError);
      continue;
    }
  }
}
