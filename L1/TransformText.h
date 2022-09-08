#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

class TransformText
{
private:
  static std::string Replace(const std::string& text, char oldVal, const std::string& newVal);
  static std::vector<std::string> Split(const std::string& s, char delim);
  static std::string GetWorgdWithoutSimbols(const std::string& s);
public:
  /// <summary>
  ///  Задан текст. Составить новый текст из букв заданного по принципу: 
  /// первое слово нового текста состоит их последних букв слов заданного
  /// текста, второе слово из предпоследних букв и так далее.
  /// </summary>
  /// <param name="text">заданный текст</param>
  /// <returns></returns>
  static std::string GetTransformedText(const std::string& text, bool isIgnoreSimbols);
};

