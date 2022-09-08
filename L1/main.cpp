/*
17. Задан текст. Составить новый текст из букв заданного по принципу: 
первое слово нового текста состоит их последних букв слов заданного 
текста, второе слово из предпоследних букв и так далее.
*/

/*
* Вопросы: 
* 1. Что делать с символами помимо букв
* 2. Что делать с '\n'
* 3. Текст многострочный или однострочный
*/

#include <iostream>
#include "TransformText.h"
#include "SimpleConsoleFunction.h"
#include "SimpleFileFunctions.h"

std::string GetTextFromFile();
std::string GetTextFromConsole();
void SaveFile(const std::string& textResult);

int main() {
  setlocale(LC_ALL, "Russian"); // Русская локализация консоли
  const std::string fileNum = "1";
  const std::string ignoreSimbNum = "1";

  scf_t::StringToConsole("Введите " + fileNum + ", если ввод из файла. Если из консоли - любой другой символ/строку");
  bool fromFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;

  std::string text;
  try {
     text = fromFile? GetTextFromFile() : GetTextFromConsole();
  }
  catch (const char* msg) {
    scf_t::ErrorTextToConsole( msg);
    return 0;
  }

  scf_t::StringToConsole("\nВведите " + ignoreSimbNum +", если нужно игнорировать символы отличные от букв, иначе любой другой символ/строку");
  bool isIgnoreSimbols = scf_t::StringFromConsoleByLine() == ignoreSimbNum ? true : false;

  std::string transformedString = TransformText::GetTransformedText(text, isIgnoreSimbols);

  scf_t::StringToConsole("\nПолученный текст:");
  scf_t::StringToConsole(transformedString);

  scf_t::StringToConsole("\nЕсли хотите сохранить в файл нажмите 1, иначе любую другую клавишу");
  bool saveFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;
  if (saveFile) {
    SaveFile(transformedString);
  }
  

  scf_t::StringToConsole("\nВыполнение программы завершено");
  std::cin.get();
  return 0;
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
  }
}