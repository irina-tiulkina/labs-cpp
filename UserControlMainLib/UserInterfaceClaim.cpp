#include "pch.h"
#include "UserInterfaceClaim.h"

namespace UserControlMainLib {
  std::string UserInterfaceClaim::GetTitleTask() const
  {
    return TaskInfos.GetTitleTask();
  }

  void UserInterfaceClaim::AboutProgrammToConsole() const
  {
    //scf_t::StringToConsole("О программе: ");
    GetTextInfosLib::SimpleConsoleFunction::StringToConsole(TaskInfos.GetAboutTask());
  }

  void UserInterfaceClaim::CycleProgramm(
    const std::function<std::string(std::string)>& taskFunc,
    const std::string& infoForGetDataFromFile,
    const std::string& infoForGetDataFromConsole
  ) const
  {
    //2.3.(2) Зацикленность программы

    while (true) {

      // 2.4.4 (1) получить исходные данные из файла / консоли
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Введите " + _inputDataFromFileNum + " если хотите получить данные из файла, если из консоли любой другой символ/строку");

      std::string inputData = GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _inputDataFromFileNum ?
        UserInterfaceClaim::GetInputDataFromFile(infoForGetDataFromFile) : UserInterfaceClaim::GetInputDataFromConsole(infoForGetDataFromConsole);

      // 2.4.4 (1) сохранить исходные данные в файл
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Введите " + _saveDataToFileNum + " если хотите сохранить исходные данные в файл, иначе любой другой символ/строку");
      if (GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _saveDataToFileNum) {
        SaveDataToFile(inputData);
      }

      // 3. Выоленнеие задачи
      std::string resultData = "";
      try {
        resultData = taskFunc(inputData);
        GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Результат:");
        GetTextInfosLib::SimpleConsoleFunction::StringToConsole(resultData);
      }
      catch (std::exception err) {
        GetTextInfosLib::SimpleConsoleFunction::ErrorTextToConsole(err.what());
        if (IsExitToMainMenu())
          return;
        continue;
      }

      // 2.4.4 (1) сохранить результат работы в файл
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Введите " + _saveDataToFileNum + " если хотите сохранить результат в файл, иначе любой другой символ/строку");
      if (GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _saveDataToFileNum) {
        SaveDataToFile(resultData);
      }

      // 2.3.(2) Зацикленность программы Выход из программы
      if (IsExitToMainMenu())
        return;
      continue;
    }
  }

  UserInterfaceClaim::UserInterfaceClaim(const TaskInfo& taskInfo)
  {
    TaskInfos = taskInfo;
  };

  bool UserInterfaceClaim::RestoreFile() const
  {
    GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Такой файл уже существет. Введите " + _restoreFileNum + " чтобы перезаписать файл, чтобы ввести путь к файлу заного - любой другой символ ");
    return GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _restoreFileNum;
  }

  bool UserInterfaceClaim::IsExitToMainMenu() const
  {
    GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Нажмите " + _exitProgrammNum + " если хотите выйти из программы, иначе любой другой символ/строку");
    return GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine() == _exitProgrammNum;
  }

  std::string UserInterfaceClaim::GetInputDataFromFile(const std::string& infoForGetDataFromFile) const
  {
    while (true) {
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Введите полный путь к файлу: ");
      GetTextInfosLib::SimpleConsoleFunction::InfoTextToConsole(infoForGetDataFromFile);
      std::string fullFilePath = GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine();

      try {
        std::string inputData = GetTextInfosLib::SimpleFileFunctions::GetStringFromFile(fullFilePath);
        GetTextInfosLib::SimpleConsoleFunction::StringToConsole(inputData);
        return inputData;
      }
      catch (...) {
        GetTextInfosLib::SimpleConsoleFunction::ErrorTextToConsole(_proscessGetDataFromFileError);
        continue;
      }
    }
  }

  std::string UserInterfaceClaim::GetInputDataFromConsole(const std::string& infoForGetDataFromConsole) const
  {
    GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Введите текст");
    GetTextInfosLib::SimpleConsoleFunction::InfoTextToConsole(infoForGetDataFromConsole);
    std::string line = GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine();
    while (line[line.size() - 1] != '$') {

      line += +"\n" + GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine();
    }
    line.pop_back();

    return line;
  }

  void UserInterfaceClaim::SaveDataToFile(std::string inputText) const
  {
    while (true) {
      GetTextInfosLib::SimpleConsoleFunction::StringToConsole("Введите полный путь к файлу: ");
      std::string fullFilePath = GetTextInfosLib::SimpleConsoleFunction::StringFromConsoleByLine();

      // Проверка на существование файла
      if (GetTextInfosLib::SimpleFileFunctions::FileExists(fullFilePath) && !RestoreFile()) {
        continue;
      }

      try {
        GetTextInfosLib::SimpleConsoleFunction::InfoTextToConsole("Файл сохраняется...");
        GetTextInfosLib::SimpleFileFunctions::SaveStringToFile(inputText, fullFilePath);
        GetTextInfosLib::SimpleConsoleFunction::InfoTextToConsole("Файл сохранился успешно");
        return;
      }
      catch (...) {
        GetTextInfosLib::SimpleConsoleFunction::ErrorTextToConsole(_processFileSaveError);
        continue;
      }
    }
  }

}
