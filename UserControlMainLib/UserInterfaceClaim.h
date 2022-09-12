#pragma once
#include <string>
#include "TaskInfo.h"
#include <iostream>
#include <functional>
#include "../ConsoleWorkLib/SimpleConsoleFunction.cpp"
#include "../ConsoleWorkLib/SimpleFileFunctions.h"

class UserInterfaceClaim
{
private:

  // Пункты меню
  const std::string _inputDataFromFileNum = "1"; // 2.4.4 (1) Пункт меню для возможности получения данных из файла
  const std::string _saveDataToFileNum = "1"; // 2.4.4 (1) Пункт меню для возможности сохранения данных в файл
  const std::string _restoreFileNum = "1"; // 2.4.4 (3) Пункт меню для перезаписи файла
  const std::string _exitProgrammNum = "1"; // 2.3 (2) Пункт меню для выхода из программы

  /// <summary>
  /// 2.3.(1) Для получения информации о программе / задаче / авторе
  /// </summary>
  TaskInfo  TaskInfos;

  /// <summary>
  /// 2.4 (1) Для обработки ошибки сохранения файла
  /// </summary>
  const std::string _processFileSaveError = "Ошибка при сохранении файла. Проверьте путь к файлу";

  /// <summary>
  /// 2.4 (1) Для обработки ошибки получения данных из файла
  /// </summary>
  const std::string _proscessGetDataFromFileError = "Ошибка при получении данных из файла. Проверьте путь к файлу";

  /// <summary>
  /// 2.4.4 (3) Перезаписать файл если такой существует 
  /// </summary>
  /// <returns></returns>
  bool RestoreFile() const;

  bool IsExitToMainMenu() const;

protected:

  /// <summary>
  /// 2.4.4 (1) вводить исходные данные из файла
  /// </summary>
  /// <returns>Входные данные в виде строки</returns>
  std::string GetInputDataFromFile(const std::string& infoForGetDataFromFile) const;
  std::string GetInputDataFromConsole(const std::string& infoForGetDataFromConsole) const;

  /// <summary>
 /// 2.4.4 (1) сохранить исходные данные в файл, сохранить результат работы в файл
 /// </summary>
 /// <param name="inputText">Исходный текст для сохранения</param>
  void SaveDataToFile(std::string str) const;

  /// <summary>
  /// 2.3.(2) Зацикленность программы
  /// </summary>
  void CycleProgramm
  (
    const std::function<std::string(std::string)>& taskFunc,
    const std::string& infoForGetDataFromFile,
    const std::string& infoForGetDataFromConsole
  ) const;

public:

  std::string GetTitleTask() const;

  /// <summary>
  /// 2.3.(1) О программе (назначение, автор, задача, результат )
  /// </summary>
  void AboutProgrammToConsole() const;
  virtual void StartCycleProgramm() const = 0;
  UserInterfaceClaim(const TaskInfo& taskInfo);
  virtual ~UserInterfaceClaim() {};
};

typedef UserInterfaceClaim uic_t;