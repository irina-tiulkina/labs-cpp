#include "TransformText.h"

/// <summary>
 ///  Задан текст. Составить новый текст из букв заданного по принципу: 
 /// первое слово нового текста состоит их последних букв слов заданного
 /// текста, второе слово из предпоследних букв и так далее.
 /// </summary>
 /// <param name="text">заданный текст</param>
 /// <returns></returns>
std::string TransformText::GetTransformedText(const std::string& text, bool isIgnoreSimbols)
{
  std::vector<std::string> delimText = Split(text, ' ');
  std::vector<std::string> words;

  for (int i = 0; i < delimText.size(); i++) { 

    std::string wordDelim = isIgnoreSimbols ? GetWorgdWithoutSimbols(delimText[i]) : delimText[i];

    if (wordDelim.size() > words.size()) {
      int addSize = delimText[i].size() - words.size();
      for (int k = 0; k < addSize; k++) {
        words.push_back("");
      }
    }

    for (int j = wordDelim.size()-1; j >= 0 ; j--) {
      size_t indexWord = (wordDelim.size() - 1) - j;
      words[indexWord] += wordDelim[j];
    }
  }

  std::string str = "";

  for (int i = 0; i < words.size(); i++) {
    str += (i == words.size() -1) ? words[i] : words[i] + ' ';
  }

  return str;
}

std::string TransformText::GetWorgdWithoutSimbols(const std::string& s) { // ??
  std::string word = "";
  for (int i = 0; i < s.size(); i++) {
    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '\n') {
      word += s[i];
    }
    else {
      continue;
    }
  }
  return word;
}

std::vector<std::string> TransformText::Split(const std::string& s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}
