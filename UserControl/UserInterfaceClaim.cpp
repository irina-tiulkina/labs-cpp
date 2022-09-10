#include "pch.h"
#include "UserInterfaceClaim.h"

std::string UserInterfaceClaim::GetTitleTask() const
{
  return TaskInfos.GetTitleTask();
}

void UserInterfaceClaim::AboutProgrammToConsole() const
{
  //scf_t::StringToConsole("О программе: ");
  scf_t::StringToConsole(TaskInfos.GetAboutTask());
}

void UserInterfaceClaim::CycleProgramm(const std::function<std::string(std::string)>& taskFunc) const
{
  //2.3.(2) Зацикленность программы

  while (true) {

    // 2.4.4 (1) получить исходные данные из файла / консоли
    scf_t::StringToConsole("Введите " + _inputDataFromFileNum + " если хотите получить данные из файла, если из консоли любой другой символ/строку");

    std::string inputData = scf_t::StringFromConsoleByLine() == _inputDataFromFileNum ? uic_t::GetInputDataFromFile() : uic_t::GetInputDataFromConsole();

    // 2.4.4 (1) сохранить исходные данные в файл
    scf_t::StringToConsole("Введите " + _saveDataToFileNum + " если хотите сохранить исходные данные в файл, иначе любой другой символ/строку");
    if (scf_t::StringFromConsoleByLine() == _saveDataToFileNum) {
      SaveDataToFile(inputData);
    }

    // 3. Выоленнеие задачи
    std::string resultData = "";
    try {
      resultData = taskFunc(inputData);
      scf_t::StringToConsole("Результат:");
      scf_t::StringToConsole(resultData);
    }
    catch(std::exception err) {
      scf_t::ErrorTextToConsole(err.what());
      if (IsExitToMainMenu())
        return;
      continue;
    }
    
    // 2.4.4 (1) сохранить результат работы в файл
    scf_t::StringToConsole("Введите " + _saveDataToFileNum + " если хотите сохранить результат в файл, иначе любой другой символ/строку");
    if (scf_t::StringFromConsoleByLine() == _saveDataToFileNum) {
      SaveDataToFile(resultData);
    }

    // 2.3.(2) Зацикленность программы Выход из программы
    if (IsExitToMainMenu())
      return;
    continue;
  }
}

UserInterfaceClaim::UserInterfaceClaim(const TaskInfo &taskInfo)
{
  TaskInfos = taskInfo;
};

bool UserInterfaceClaim::RestoreFile() const
{
  scf_t::StringToConsole("Такой файл уже существет. Введите " + _restoreFileNum + " чтобы перезаписать файл, чтобы ввести путь к файлу заного - любой другой символ ");
  return scf_t::StringFromConsoleByLine() == _restoreFileNum;
}

bool UserInterfaceClaim::IsExitToMainMenu() const
{
  scf_t::StringToConsole("Нажмите " + _exitProgrammNum + " если хотите выйти из программы, иначе любой другой символ/строку");
  return scf_t::StringFromConsoleByLine() == _exitProgrammNum;
}

std::string UserInterfaceClaim::GetInputDataFromFile() const
{
  while (true) {
    scf_t::StringToConsole("Введите полный путь к файлу: ");
    std::string fullFilePath = scf_t::StringFromConsoleByLine();

    try {
      std::string inputData = sff_t::GetStringFromFile(fullFilePath);
      scf_t::StringToConsole(inputData);
      return inputData;
    }
    catch (...) {
      scf_t::ErrorTextToConsole(_proscessGetDataFromFileError);
      continue;
    }
  }
}

std::string UserInterfaceClaim::GetInputDataFromConsole() const
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

void UserInterfaceClaim::SaveDataToFile(std::string inputText) const
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
      scf_t::ErrorTextToConsole(_processFileSaveError);
      continue;
    }
  }
}
