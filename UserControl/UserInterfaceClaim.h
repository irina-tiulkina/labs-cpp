#pragma once
#include <string>
#include "TaskInfo.h"
#include "SimpleConsoleFunction.h"
#include "SimpleFileFunctions.h"
#include "StringTransform.h"

class UserInterfaceClaim
{
private:

  // Пункты меню
  const std::string InputDataFromFileNum = "1"; // 2.4.4 (1) Пункт меню для возможности получения данных из файла
  const std::string SaveDataToFileNum = "1"; // 2.4.4 (1) Пункт меню для возможности сохранения данных в файл
  const std::string RestoreFileNum = "1"; // 2.4.4 (3) Пункт меню для перезаписи файла
  const std::string ExitProgrammNum = "1"; // 2.3 (2) Пункт меню для выхода из программы

  /// <summary>
  /// 2.3.(1) Для получения информации о программе / задаче / авторе
  /// </summary>
  TaskInfo  TaskInfos;

  /// <summary>
  /// 2.4 (1) Для обработки ошибки сохранения файла
  /// </summary>
  const std::string ProcessFileSaveError = "Ошибка при сохранении файла. Проверьте путь к файлу";

  /// <summary>
  /// 2.4 (1) Для обработки ошибки получения данных из файла
  /// </summary>
  const std::string ProscessGetDataFromFileError = "Ошибка при получении данных из файла. Проверьте путь к файлу";

  /// <summary>
  /// 2.4.4 (3) Перезаписать файл если такой существует 
  /// </summary>
  /// <returns></returns>
  bool RestoreFile();

  bool IsExitToMainMenu();

protected:

  UserInterfaceClaim(TaskInfo taskInfo) {
    TaskInfos = taskInfo;
  };

  /// <summary>
  /// 2.4.4 (1) вводить исходные данные из файла
  /// </summary>
  /// <returns>Входные данные в виде строки</returns>
  virtual std::string GetInputDataFromFile();
  virtual std::string GetInputDataFromConsole();

  /// <summary>
/// 2.4.4 (1) сохранить исходные данные в файл, сохранить результат работы в файл
/// </summary>
/// <param name="inputText">Исходный текст для сохранения</param>
  void SaveDataToFile(std::string str);


  /// <summary>
  ///  Для решения поставленной задачи
  /// </summary>
  /// <param name="inputDataInString">входные данные полученные из файла/консоли</param>
  /// <returns>Возвращает результат работы программы, решающей поставленную задачу, в виде строки для записи в консоль/файл</returns>
  virtual std::string ProgrammFunction(const std::string& inputDataInString) = 0;

public:
  
  std::string GetTitleTask() { return TaskInfos.GetTitleTask(); }

  /// <summary>
  /// 2.3.(1) О программе (назначение, автор, задача, результат )
  /// </summary>
  void AboutProgrammToConsole();

  /// <summary>
  /// 2.3.(2) Зацикленность программы
  /// </summary>
  void CycleProgramm();

};

typedef UserInterfaceClaim uic_t;