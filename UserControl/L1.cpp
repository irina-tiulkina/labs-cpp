#include "pch.h"
#include "L1.h"

std::string L1::GetStrWithoutSimbols(const std::string& s)
{
  std::string str = "";
  for (int i = 0; i < s.size(); i++) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
      str += s[i];
    }
    else {
      continue;
    }
  }
  return str;
}

std::string L1::ProgrammFunction(const std::string& inputDataInString) {
  std::string replacedText = st_t::Replace(inputDataInString, '\n', " ");
  replacedText = GetStrWithoutSimbols(replacedText);
  std::vector<std::string> delimText = st_t::Split(replacedText, ' ');

  std::vector<std::string> words;

  for (size_t i = 0; i < delimText.size(); i++) {

    std::string wordDelim = delimText[i];

    if (wordDelim.size() > words.size()) {
      size_t addSize = wordDelim.size() - words.size();
      for (int k = 0; k < addSize; k++) {
        words.push_back("");
      }
    }

    for (int j = wordDelim.size() - 1; j >= 0; j--) {
      size_t indexWord = (wordDelim.size() - 1) - j;
      words[indexWord] += wordDelim[j];
    }
  }

  std::string str = "";

  for (size_t i = 0; i < words.size(); i++) {
    str += (i == words.size() - 1) ? words[i] : words[i] + ' ';
  }

  return str;
}

std::string L1::GetInputDataFromFile()
{
  return uic_t::GetInputDataFromFile();
}

std::string L1::GetInputDataFromConsole()
{
  return uic_t::GetInputDataFromConsole();
}