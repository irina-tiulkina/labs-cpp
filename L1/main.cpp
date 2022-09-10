/*
17. Задан текст. Составить новый текст из букв заданного по принципу: 
первое слово нового текста состоит их последних букв слов заданного 
текста, второе слово из предпоследних букв и так далее.
*/

#include <iostream>
#include "TransformText.h"
#include "SimpleConsoleFunction.h"
#include "SimpleFileFunctions.h"

const std::string fileNum = "1";
const std::string ignoreSimbNum = "1";
const std::string exitProgrammNum = "1";

std::string GetTextFromFile();
std::string GetTextFromConsole();
void SaveFile(const std::string& textResult);
void InfoConsole();
bool IsExitProgramm();

int main() {
  setlocale(LC_ALL, "Russian"); // Русская локализация консоли

  // 2.3.1 Информация о программе
  InfoConsole();

  bool isStartProgramm = true;

  // 2.3.2 Программа закольцована 
  while (isStartProgramm) {
    scf_t::StringToConsole("Введите " + fileNum + ", если ввод из файла. Если из консоли - любой другой символ/строку");
    bool isInputDataFromFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;

    std::string text;
    try {
      // 2.4.4.1 Вводить исходные данные из файла
      text = isInputDataFromFile ? GetTextFromFile() : GetTextFromConsole();
    }
    catch (const char* msg) {
      scf_t::ErrorTextToConsole(msg);
      if (IsExitProgramm())
        return;
      else {
        continue;
      }
    }

    // 2.4.4.1 Сохранить исходные данные в файле (если консоль)
    if (!isInputDataFromFile) {
      scf_t::StringToConsole("Если хотетите сохранить исходные данные в файл введите " + fileNum + ", иначе любую другую букыу");
      bool isInputDataSaveToFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;
      if (isInputDataSaveToFile) {
        SaveFile(text);
      }
    }

    scf_t::StringToConsole("\nВведите " + ignoreSimbNum + ", если нужно игнорировать символы отличные от букв, иначе любой другой символ/строку");
    bool isIgnoreSimbols = scf_t::StringFromConsoleByLine() == ignoreSimbNum ? true : false;

    std::string transformedString = TransformText::GetTransformedText(text, isIgnoreSimbols);

    scf_t::StringToConsole("\nПолученный текст:");
    scf_t::StringToConsole(transformedString);

    // 2.4.4.1 Сохранить резульат в файл
    scf_t::StringToConsole("\nЕсли хотите сохранить в файл нажмите 1, иначе любую другую клавишу");
    bool isResultDataSaveFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;
    if (isResultDataSaveFile) {
      SaveFile(transformedString);
    }

    //scf_t::StringToConsole("\nВыполнение программы завершено");

    // 2.3.2 Закольцовывание, выбор пункта меню для завершения
    isStartProgramm = IsExitProgramm();
  }
  
  return 0;
}

bool IsExitProgramm() {
  scf_t::StringToConsole("Если хотите завершить программу нажмитие " + exitProgrammNum + ", иначе любой другой символ/строку");
  bool isExit = scf_t::StringFromConsoleByLine() == exitProgrammNum ? true : false;
  return isExit;
}

std::string GetTextFromFile() {
  //scf_t::StringToConsole("Введите путь к файлу:");
  //std::string filePath = scf_t::StringFromConsoleByLine();
  std::string str;
    str = sff_t::GetStringFromFile();
    return str;
}

std::string GetTextFromConsole() {
  scf_t::StringToConsole("Введите текст");
  scf_t::InfoTextToConsole("(текст считается законченным, если в конце строки стоит $)");
  std::string line = scf_t::StringFromConsoleByLine();
  while (line[line.size() - 1] != '$') {

    line += +"\n" + scf_t::StringFromConsoleByLine();
  }
  line.pop_back();

  return line;
}

void InfoConsole() {
  scf_t::StringToConsole("Лабораторная работа 1");
  std::string zadacha = "Задача: Задан текст. Составить новый текст из букв заданного по принципу:\n первое слово нового текста состоит их последних букв слов заданного\n текста, второе слово из предпоследних букв и так далее.";
  scf_t::StringToConsole(zadacha);
  scf_t::StringToConsole("Автор: Тюлькина Ирина Павловна");
  scf_t::StringToConsole("Группа: 494 Курс: 4");
  scf_t::StringToConsole("В результате программы получаем текст");
}

void SaveFile(const std::string& textResult) {

  /*scf_t::StringToConsole("Введите путь к файлу:");
  std::string filePath = scf_t::StringFromConsoleByLine();*/

  try {
    scf_t::InfoTextToConsole("Идет сохранение в файл...");
    sff_t::SaveStringToFile(textResult);
    scf_t::InfoTextToConsole("Файл успешно сохранен");
  }
  catch (const char* msg) {
    scf_t::ErrorTextToConsole(msg);
    throw msg;
  }
}