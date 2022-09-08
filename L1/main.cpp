/*
17. Задан текст. Составить новый текст из букв заданного по принципу: 
первое слово нового текста состоит их последних букв слов заданного 
текста, второе слово из предпоследних букв и так далее.
*/

/*
* Вопросы: 
* 1. Что делать с символами помимо букв
* 2. Что делать с '\n'
*/

#include <iostream>
#include "TransformText.h"
#include "SimpleConsoleFunction.h"

std::string GetTextFromFile();
std::string GetTextFromConsole();
void SaveFile();

int main() {
  setlocale(LC_ALL, "Russian"); // Русская локализация консоли
  const std::string fileNum = "1";
  const std::string ignoreSimbNum = "1";

  scf_t::StringToConsole("Введите " + fileNum + ", если ввод из файла. Если из консоли - любой другой символ/строку"); // !!!!!
  bool fromFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;

  std::string text;
  try {
     text = fromFile? GetTextFromFile() : GetTextFromConsole();
  }
  catch (std::string msg) {
    scf_t::ErrorTextToConsole("Ошибка при получении текста: " + msg);
    return 0;
  }

  scf_t::StringToConsole("\nВведите " + ignoreSimbNum +", если нужно игнорировать символы отличные от букв, иначе любой другой символ/строку");
  bool isIgnoreSimbols = scf_t::StringFromConsoleByLine() == ignoreSimbNum ? true : false;

  std::string transformedString = TransformText::GetTransformedText(text, isIgnoreSimbols);

  scf_t::StringToConsole("\nПолученный текст:");
  scf_t::StringToConsole(transformedString);

  scf_t::StringToConsole("\n\n\nЕсли хотите сохранить в файл нажмите 1, иначе любую другую клавишу"); // !!!!
  bool saveFile = scf_t::StringFromConsoleByLine() == fileNum ? true : false;
  if (saveFile) {
    SaveFile();
  }
    
  std::cin.get();
  return 0;
}

std::string GetTextFromFile() {
  scf_t::StringToConsole("Введите путь к файлу:");
  std::string filePath = scf_t::StringFromConsoleByLine();

  return "file";
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

void SaveFile() {
  scf_t::InfoTextToConsole("Идет сохранение в файл...");
}